#include "Scene.h"

glm::vec4 booster_position = glm::vec4(500, -150, 0, 1.0f);
OBBCollider* booster;
ParticleEmitter* boosterEmitter;

Scene::Scene(const char* root, float width, float height, Timer* timer)
{
    this->width       = width;
    this->height      = height;
    this->timer       = timer;
    this->camera      = new Camera(width, height, timer);
    this->shader      = new Shader(root, "Simple.vert", "Simple.frag");
    this->depthShader = new Shader(root, "Depth.vert", "Depth.frag");

    this->shader->Init();
    this->depthShader->Init();
    this->textures.Init(root);

    this->directional = new Light(
        DEFAULT_DIR_AMBIENT,
        DEFAULT_DIR_DIFFUSE,
        DEFAULT_DIR_SPECULAR,
        DEFAULT_DIR_VIEW
    );

    this->cubemap = new CubeMap(root, "png", GL_RGBA);
    this->cubemap->Init();

    this->volatile_tree = new Octree();

    Setup::Init(timer, balls, cuboids, pegs, bumpers, lights);

    booster = new OBBCollider(glm::vec3(-650, 150, 0), glm::vec3(50, 50, 50));
    boosterEmitter = new ParticleEmitter(
        booster_position,
        glm::vec3(-100),
        glm::vec3(100),
        CommonMaterials::Blue,
        100.0f,
        0.01f,
        1.0f,
        2.0f,
        timer,
        false
    );

    emitters.push_back(boosterEmitter);
}

Scene::~Scene()
{
    timer = nullptr;

    delete camera;
}

void Scene::Init()
{
    InitShadows();
    glEnable(GL_MULTISAMPLE);
    directional->InitLightSpaceMatrix();
}

void Scene::InitUniforms()
{
    shader->setVec3("uCameraForward", camera->view->forward);
    shader->setVec3("uCameraPosition", camera->view->position);

    shader->setMat4("uProjection", camera->projection->matrix);
    shader->setMat4("uView", camera->view->matrix);
}

void Scene::InitFrame(float width, float height, unsigned int buffer)
{
    glBindFramebuffer(GL_FRAMEBUFFER, buffer);
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Scene::InitShadows()
{
    glGenFramebuffers(1, &depthMapFBO);

    glGenTextures(1, &depthMap);
    glBindTexture(GL_TEXTURE_2D, depthMap);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Scene::Tick()
{
    if (slowmo)
        timer->delta /= 16;

    if (running)
        UpdateState(timer);

    switch (framebuffer)
    {
        case Hidden_Buffer::BLOOM_BUFFER: RenderDefaultBuffer();
            break;
        case Hidden_Buffer::SHADOW_BUFFER: RenderShadowBuffer();
            break;
        case Hidden_Buffer::DEFAULT_BUFFER: RenderDefaultBuffer();
            break;
    }
}

void Scene::Render(Shader* shader)
{
    InitUniforms();
    
    for (Ball* ball : balls)
        if (running)
            ball->Animate(timer);

    directional->EnableDirectional(shader);
    directional->ApplyLightMatrix(shader);

    for (auto mesh : balls)
        mesh->Draw(shader);

    for (auto mesh : cuboids)
        mesh->Draw(shader);

    for (auto mesh : pegs)
        mesh->Draw(shader);

    for (auto mesh : bumpers)
        mesh->Draw(shader);

    for (auto emitter : emitters)
        emitter->Render(shader);
}

void Scene::RenderDefaultBuffer()
{
    depthShader->Use();

    InitFrame(SHADOW_WIDTH, SHADOW_HEIGHT, depthMapFBO);

    Render(depthShader);

    InitFrame(width, height, 0);

    shader->Use();

    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, depthMap);

    shader->setInt("uShadows", 3);
    shader->setInt("uLightCount", lights.size());

    for (auto light : lights)
        light->Enable(shader);

    Render(shader);

    cubemap->Draw(shader, camera);

    Debug();
}

void Scene::RenderShadowBuffer()
{
    depthShader->Use();

    InitFrame(width, height, 0);

    Render(depthShader);
}

void Scene::UpdateState(Timer* clock)
{

    booster->SetPosition(cuboids.at(0)->transform->GetReducedMatrix() * booster_position);
    booster->SetRotation(cuboids.at(0)->transform->GetRotationMatrix());

    UpdateCollisions(clock);
    UpdateLaunch();
    UpdateBumpers();
    UpdateEmitters();
    UpdateLights();

    if (!bruteforce)
        GenerateVolatileTree();

    for (Cuboid<OBBCollider>* cuboid : cuboids)
        cuboid->UpdateState(timer);

    for (int i = 0; i < balls.size(); ++i)
    {
        auto ball = balls.at(i);

        if (CollisionDetector::Simulate(ball->collider, booster))
        {
            ball->transform->SetPosition(cuboids.at(0)->transform->GetReducedMatrix() * (booster_position + glm::vec4(200, 0, 0, 1.0)));
            ball->body->velocity = glm::mat3(cuboids.at(0)->transform->GetRotationMatrix()) * glm::vec3(8000, 0, -430);
        }
        
        ball->UpdateState(clock);

        StaticCollisions(ball);
        BallsCollisions(ball);
    
        ValidateBalls(ball, i);
    }

    UpdatePaddles();
}

void Scene::UpdateLights()
{
    for (int i = 0; i < lights.size(); ++i)
    {
        auto light = lights.at(i);
        light->Tick(timer->delta);

        if (light->IsDestroyable)
        {
            if (light->IsDone())
            {
                lights.erase(lights.begin() + i);
                delete light;
            }
        }
        else
        {
            light->UpdatePosition();
        }
    }
}

void Scene::UpdateEmitters()
{
    boosterEmitter->lifetime = 100.0f;
    boosterEmitter->position = cuboids.at(0)->transform->GetReducedMatrix() * booster_position;

    for (int i = 0; i < emitters.size(); ++i)
    {
        auto emitter = emitters.at(i);
        
        emitter->Tick();

        if (emitter->IsDone())
        {
            delete emitter;
            emitters.erase(emitters.begin() + i);
        }
    }
}

void Scene::UpdateBumpers()
{
    for (auto bumper : bumpers)
    {
        bumper->Tick();
    }

    for (auto peg : pegs)
    {
        peg->Tick();
    }
}

void Scene::UpdatePaddles()
{
    float speed = 200.0f;

    if (LeftPaddleSwing)
    {
        if (LeftPaddleYaw < 45.0f)
        {
            LeftPaddleYaw += speed * timer->delta;
            cuboids.at(cuboids.size() - 2)->Parent->transform->Yaw(speed * timer->delta);
        }
    }
    else
    {
        if (LeftPaddleYaw > 0.0f)
        {
            LeftPaddleYaw -= speed * timer->delta;
            cuboids.at(cuboids.size() - 2)->Parent->transform->Yaw(speed * -timer->delta);
        }
    }

    if (RightPaddleSwing)
    {
        if (RightPaddleYaw > -30.0f)
        {
            RightPaddleYaw -= speed * timer->delta;
            cuboids.at(cuboids.size() - 1)->Parent->transform->Yaw(-speed * timer->delta);
        }
    }
    else
    {
        if (RightPaddleYaw < 0.0f)
        {
            RightPaddleYaw += speed * timer->delta;
            cuboids.at(cuboids.size() - 1)->Parent->transform->Yaw(speed * timer->delta);
        }
    }
}

void Scene::StaticCollisions(Ball* ball)
{
    for (Peg* peg : pegs)
    {
        peg->ApplyForce(ball);

        if (CollisionDetector::Simulate(ball->collider, peg->collider))
        {
            peg->Activate();

            PhysicsEngine::ball2peg_reposition(ball, peg);
            PhysicsEngine::ball2peg_collision(ball, peg);
        }
    }

    for (Bumper* bumper : bumpers)
    {
        if (CollisionDetector::Simulate(ball->collider, bumper->collider))
        {
            PhysicsEngine::ball2bumper_reposition(ball, bumper);
            PhysicsEngine::ball2bumper_collision(ball, bumper);
        }
    }

    for (Cuboid<OBBCollider>* cuboid : cuboids)
    {
        if (CollisionDetector::Simulate(ball->collider, cuboid->collider))
        {
            PhysicsEngine::ball2box_reposition(ball, cuboid);
            PhysicsEngine::ball2box_collision(ball, cuboid);
        }
    }
}

void Scene::BallsCollisions(Ball* ball)
{
    auto reference = std::unordered_set<Ball*>();

    if (!bruteforce)
    {
        volatile_tree->Insert(
            ball->transform->GetPosition(),
            glm::vec3(ball->collider->GetRadius()),
            ball);

        volatile_tree->Search(lights, collisions, emitters, reference, ball, timer);
    }
    else
    {
        for (Ball* b2 : balls)
        {
            if (ball != b2 && CollisionDetector::Simulate(ball->collider, b2->collider))
            {
                PhysicsEngine::ball2ball_reposition(ball, b2);
                PhysicsEngine::ball2ball_collision(lights, collisions, emitters, ball, b2, timer);
            }
        }
    }
}

void Scene::ValidateBalls(Ball* ball, int index)
{
    if (ball->IsDone())
    {
        balls.erase(balls.begin() + index);
    }
}

void Scene::GenerateVolatileTree()
{
    delete volatile_tree;
    volatile_tree = new Octree();
}

void Scene::UpdateCollisions(Timer* clock)
{
    for (int i = 0; i < collisions.size(); ++i)
    {
        Collision* collision = collisions.at(i);
        collision->Update(clock->delta);

        if (collision->IsDone())
        {
            delete collision;
            collisions.erase(collisions.begin() + i);
        }
    }
}

void Scene::UpdateLaunch()
{
    float last = 0;
    
    for (int i = 3; i > 0; --i)
    {
        auto light = lights.at(i - 1);
        auto interval = (1.0f / 3.0f) * (4.0f - (float) i);
    
        auto time = fminf(InvLerp(last, interval, launchPower), 1.0f);
    
        light->Diffuse  = glm::clamp(glm::vec4(0.0), glm::vec4(1.0), glm::vec4(Lerp(glm::vec3(1, 0, 0), glm::vec3(0, 1, 0), time), 1.0));
        light->Specular = light->Diffuse;
        light->Ambient  = glm::vec4(light->Diffuse.x * 0.2f, light->Diffuse.y * 0.2f, light->Diffuse.z * 0.2f, 1.0);
        last = interval;
    }
}

void Scene::Done()
{
    glUseProgram(0);
    glBindVertexArray(0);
}

void Scene::Debug()
{
    auto projection = camera->projection->matrix;
    auto view       = camera->view->matrix;

    if (collisionDebug)
        PhysicsEngine::DrawCollisions(collisions, projection, view);

    if (colliderDebug)
    {
        for (auto cuboid : cuboids)
            cuboid->collider->Debug(projection, view);

        for (auto ball : balls)
            ball->collider->Debug(projection, view);

        for (auto peg : pegs)
            peg->collider->Debug(projection, view);

        for (auto bumper : bumpers)
            bumper->collider->Debug(projection, view);

        booster->Debug(projection, view);
    }

    if (velocityDebug)
    {
        for (auto ball : balls)
            ball->Debug(projection, view);
    }

    if (volatileDebug)
        volatile_tree->Debug(projection, view);

    if (lightDebug)
    {
        directional->Debug(projection, view);

        for (auto light : lights)
            light->Debug(projection, view);
    }
}

void Scene::KeyPress(SDL_Event e)
{
}

void Scene::KeyDown(SDL_Event e)
{
    auto key = e.key.keysym.sym;

    if (key == SDLK_SPACE)
    {
        running = !running;
    }   
    else if (key == SDLK_1)
    {
        framebuffer = Hidden_Buffer::DEFAULT_BUFFER;
    }
    else if (key == SDLK_2)
    {
        framebuffer = Hidden_Buffer::SHADOW_BUFFER;
    }
    else if (key == SDLK_3)
    {
        framebuffer = Hidden_Buffer::BLOOM_BUFFER;
    }
    else if (key == SDLK_RETURN)
    {
        launchPower += 0.05;
        launchPower = fminf(launchPower, 1.0);
    }
    else if (key == SDLK_MINUS)
    {
        cuboids.at(0)->transform->Pitch(-0.5f);
    }
    else if (key == SDLK_EQUALS)
    {
        cuboids.at(0)->transform->Pitch(0.5f);
    }
    else if (key == SDLK_TAB)
    {
        slowmo = !slowmo;
    }
    else if (key == SDLK_z)
    {
        collisionDebug = !collisionDebug;
    }
    else if (key == SDLK_x)
    {
        volatileDebug = !volatileDebug;
    }
    else if (key == SDLK_c)
    {
        colliderDebug = !colliderDebug;
    }
    else if (key == SDLK_b)
    {
        bruteforce = !bruteforce;
    }
    else if (key == SDLK_v)
    {
        velocityDebug = !velocityDebug;
    }
    else if (key == SDLK_l)
    {
        lightDebug = !lightDebug;
    }
    else if (key == SDLK_LEFT)
    {
        LeftPaddleSwing = true;
    }
    else if (key == SDLK_RIGHT)
    {
        RightPaddleSwing = true;
    }
    else if (key == SDLK_h)
    {
        displayHud = !displayHud;
    }
    else if (key == SDLK_LSHIFT)
    {
        camera->view->forward = DEFAULT_CAMERA_FORWARD;
        camera->view->up = DEFAULT_CAMERA_UP;
        camera->view->position = DEFAULT_CAMERA_POSITION;
    }
}

void Scene::KeyUp(SDL_Event e)
{
    auto key = e.key.keysym.sym;

    if (key == SDLK_LEFT)
    {
        LeftPaddleSwing = false;
    }
    else if (key == SDLK_RIGHT)
    {
        RightPaddleSwing = false;
    }
    else if (key == SDLK_RETURN)
    {
        auto ball = new Ball(50.0f, CommonTextures::Marble, timer);
        auto rotate = glm::mat3(cuboids.at(0)->transform->GetRotationMatrix());

        ball->Init();

        ball->transform->Translate(rotate * glm::vec3(-1250.0f, -100, 1800.0f));
        ball->transform->Scale(glm::vec3(1.0f));

        ball->body->velocity = rotate * glm::vec3(0.0, 0.0, -8000.0 * launchPower);

        balls.push_back(ball);

        launchPower = 0.0f;
    }
    else if (key == SDLK_j)
    {
        auto ball = new Ball(50.0f, CommonTextures::Marble, timer);
        auto rotate = glm::mat3(cuboids.at(0)->transform->GetRotationMatrix());

        ball->Init();

        ball->transform->Translate(rotate * booster_position);
        ball->transform->Scale(glm::vec3(1.0f));

        ball->body->velocity = rotate * glm::vec3(0.0, 0.0, 0.0);

        balls.push_back(ball);

        launchPower = 0.0f;
    }
}

std::string Scene::BufferToString()
{
    switch (framebuffer)
    {
    case Hidden_Buffer::BLOOM_BUFFER:   return "BLOOM BUFFER";
    case Hidden_Buffer::SHADOW_BUFFER:  return "SHADOW BUFFER";
    case Hidden_Buffer::DEFAULT_BUFFER: return "DEFAULT BUFFER";
    }
}

std::string Scene::ActiveToString(bool param)
{
    if (param)
        return "Active";
    else
        return "Deactive";
}