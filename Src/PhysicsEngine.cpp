#include "PhysicsEngine.h"

float PhysicsEngine::Clamp(float dimension, float closest)
{
    closest = round(closest);

    if (dimension == closest)
    {
        return 1;
    }
    else if (-dimension == closest)
    {
        return -1;
    }

    return 0;
}

glm::vec3 PhysicsEngine::Reflect(glm::vec3 direction, glm::vec3 normal)
{
    return direction - 2 * (glm::dot(direction, normal)) * normal;
}

glm::vec3 PhysicsEngine::BoxNormals(glm::vec3 dimensions, glm::vec3 closest)
{
    glm::vec3 result = glm::vec3(0.0);

    result.x = Clamp(dimensions.x, closest.x);
    result.y = Clamp(dimensions.y, closest.y);
    result.z = Clamp(dimensions.z, closest.z);

    return glm::normalize(result);
}

void PhysicsEngine::ball2ball_collision(std::vector<Light*>& lights, std::vector<Collision*>& collisions, std::vector<ParticleEmitter*>& emitters, Ball* b1, Ball* b2, Timer* timer)
{
    auto p1 = b1->transform->GetPosition();
    auto p2 = b2->transform->GetPosition();

    auto v1 = b1->body->velocity;
    auto v2 = b2->body->velocity;

    auto m1 = b1->body->mass;
    auto m2 = b2->body->mass;

    auto sub = p1 - p2;
    auto nv = glm::normalize(glm::vec3(sub));
    auto tv = glm::normalize(glm::cross(nv, glm::vec3(-nv.y, nv.x, 0.0f)));

    auto n1 = glm::dot(v1, nv);
    auto t1 = glm::dot(v1, tv);
    auto n2 = glm::dot(v2, nv);
    auto t2 = glm::dot(v2, tv);

    auto M = m1 + m2;
    auto newn1 = (n1 * (m1 - m2) + (2 * m2 * n2)) / M;
    auto newn2 = (n2 * (m2 - m1) + (2 * m1 * n1)) / M;

    b1->body->velocity.x = newn1 * nv.x + t1 * tv.x * b2->body->friction;
    b1->body->velocity.y = newn1 * nv.y + t1 * tv.y * b2->body->friction;
    b1->body->velocity.z = newn1 * nv.z + t1 * tv.z * b2->body->friction;

    b2->body->velocity.x = newn2 * nv.x + t2 * tv.x * b1->body->friction;
    b2->body->velocity.y = newn2 * nv.y + t2 * tv.y * b1->body->friction;
    b2->body->velocity.z = newn2 * nv.z + t2 * tv.z * b1->body->friction;
    
    auto collisionPosition = p1 - glm::normalize(sub) * b1->collider->Radius;

    if (lights.size() <= 100)
        lights.push_back(Light::CollisionLight(collisionPosition, lights.size()));

    collisions.push_back(new Collision(
        collisionPosition,
        nv,
        tv,
        glm::normalize(b1->body->velocity)
    ));

    emitters.push_back(new ParticleEmitter(
        collisionPosition,
        glm::vec3(-300),
        glm::vec3(300),
        CommonMaterials::Yellow,
        0.25f,
        0.1f,
        25.0f,
        0.25f,
        timer,
        true
    ));
}

void PhysicsEngine::ball2ball_reposition(Ball* b1, Ball* b2)
{
    
    float radius = b1->collider->GetRadius() + b2->collider->GetRadius();
    auto  dp = b1->collider->GetPosition() - b2->collider->GetPosition();
    float distance = abs(glm::length(dp));
    float diff = radius - distance;

    b1->transform->Translate(glm::normalize(dp) * diff);
}

void PhysicsEngine::ball2box_collision(std::vector<Collision*>& collisions, Ball* b1, Cuboid<AABBCollider>* c2)
{
    auto p1 = b1->transform->GetPosition();
    auto p2 = CollisionDetector::ClosestPoint(c2->collider, p1 - c2->collider->Position);
    auto v1 = b1->body->velocity;
    auto nv = BoxNormals(c2->collider->SizeVector3(), p2);

    b1->body->velocity.x = (nv.x == 0 ? v1.x : -v1.x);
    b1->body->velocity.y = (nv.y == 0 ? v1.y : -v1.y);
    b1->body->velocity.z = (nv.z == 0 ? v1.z : -v1.z);
}

void PhysicsEngine::ball2box_reposition(Ball* b1, Cuboid<AABBCollider>* c2)
{
    glm::vec3 position = b1->collider->GetPosition();
    glm::vec3 direction = glm::normalize(b1->body->velocity);
    glm::vec3 closestPoint = CollisionDetector::ClosestPoint(c2->collider, position);
    glm::vec3 collision = closestPoint - position;
    
    float radius = b1->collider->GetRadius();
    float distance = abs(glm::length(collision));
    float difference = radius - distance;

    b1->transform->Translate(-glm::normalize(collision) * difference);
}

void PhysicsEngine::ball2box_collision(Ball* b1, Cuboid<OBBCollider>* c2)
{
    glm::vec3 p1 = b1->transform->GetPosition();
    glm::vec3 p2 = c2->transform->GetMatrix()[3];
    
    auto size = c2->collider->SizeVector3();

    auto m3Rotation  = glm::mat3(c2->transform->GetRotationMatrix());
    auto invRotation = glm::inverse(m3Rotation);

    auto v1 = invRotation * b1->body->velocity;

    auto t1 = (invRotation * p1);
    auto t2 = (invRotation * p2);

    auto invPos   = t1 - t2;
    auto aabb     = new AABBCollider(glm::vec3(0), size);
    auto closest  = CollisionDetector::ClosestPoint(aabb, invPos);
    
    auto normal   = BoxNormals(size, closest);

    b1->body->velocity = m3Rotation * Reflect(v1, normal) * c2->body->friction;

    delete aabb;
}

void PhysicsEngine::ball2box_reposition(Ball* b1, Cuboid<OBBCollider>* c2)
{
    glm::vec3 position = b1->collider->GetPosition();
    glm::vec3 direction = glm::normalize(b1->body->velocity);
    glm::vec3 closestPoint = CollisionDetector::ClosestPoint(c2->collider, position);
    glm::vec3 collision = closestPoint - position;
    
    float length = glm::length(collision);
    float radius = b1->collider->GetRadius();

    if (length == 0)
    {
        position -= glm::normalize(b1->body->velocity);
        collision = closestPoint - position;
        length = glm::length(collision);
    }

    float distance = abs(length);
    float difference = radius - distance;

    glm::vec3 amount = (length ? -glm::normalize(collision) : -b1->body->velocity) * difference;

    b1->transform->Translate(amount);
}

void PhysicsEngine::ball2peg_collision(Ball* b1, Peg* c2)
{
    glm::vec3 p1 = b1->transform->GetPosition();
    glm::vec3 p2 = c2->transform->GetMatrix()[3];

    auto size = c2->collider->SizeVector3();

    auto m3Rotation = glm::mat3(c2->transform->GetRotationMatrix());
    auto invRotation = glm::inverse(m3Rotation);

    auto v1 = invRotation * b1->body->velocity;

    auto t1 = (invRotation * p1);
    auto t2 = (invRotation * p2);

    auto invPos = t1 - t2;
    auto aabb = new AABBCollider(glm::vec3(0), size);
    auto closest = CollisionDetector::ClosestPoint(aabb, invPos);

    auto normal = BoxNormals(size, closest);

    b1->body->velocity = m3Rotation * Reflect(v1, normal) * c2->body->friction;

    delete aabb;
}

void PhysicsEngine::ball2peg_reposition(Ball* b1, Peg* c2)
{
    glm::vec3 position = b1->collider->GetPosition();
    glm::vec3 direction = glm::normalize(b1->body->velocity);
    glm::vec3 closestPoint = CollisionDetector::ClosestPoint(c2->collider, position);
    glm::vec3 collision = closestPoint - position;

    float length = glm::length(collision);
    float radius = b1->collider->GetRadius();

    if (length == 0)
    {
        position -= glm::normalize(b1->body->velocity);
        collision = closestPoint - position;
        length = glm::length(collision);
    }

    float distance = abs(length);
    float difference = radius - distance;

    glm::vec3 amount = (length ? -glm::normalize(collision) : -b1->body->velocity) * difference;

    b1->transform->Translate(amount);
}

void PhysicsEngine::ball2bumper_collision(Ball* b1, Bumper* c2)
{
    glm::vec3 p1 = b1->transform->GetPosition();
    glm::vec3 p2 = c2->transform->GetMatrix()[3];

    auto size = c2->collider->SizeVector3();

    auto m3Rotation = glm::mat3(c2->transform->GetRotationMatrix());
    auto invRotation = glm::inverse(m3Rotation);

    auto v1 = invRotation * b1->body->velocity;

    auto t1 = (invRotation * p1);
    auto t2 = (invRotation * p2);

    auto invPos = t1 - t2;
    auto aabb = new AABBCollider(glm::vec3(0), size);
    auto closest = CollisionDetector::ClosestPoint(aabb, invPos);

    auto normal = BoxNormals(size, closest);

    b1->body->velocity = m3Rotation * Reflect(v1, normal) * c2->body->friction;

    delete aabb;
}

void PhysicsEngine::ball2bumper_reposition(Ball* b1, Bumper* c2)
{
    glm::vec3 position = b1->collider->GetPosition();
    glm::vec3 direction = glm::normalize(b1->body->velocity);
    glm::vec3 closestPoint = CollisionDetector::ClosestPoint(c2->collider, position);
    glm::vec3 collision = closestPoint - position;

    float length = glm::length(collision);
    float radius = b1->collider->GetRadius();

    if (length == 0)
    {
        position -= glm::normalize(b1->body->velocity);
        collision = closestPoint - position;
        length = glm::length(collision);
    }

    float distance = abs(length);
    float difference = radius - distance;

    glm::vec3 amount = (length ? -glm::normalize(collision) : -b1->body->velocity) * difference;

    b1->transform->Translate(amount);
}

void PhysicsEngine::ball2wall_collision(Ball* ball, float dimension)
{
    auto position = ball->transform->GetPosition();
    auto velocity = ball->body->velocity;

    if (position.x + ball->collider->Radius >= dimension)
    {
        ball->body->velocity.x = -velocity.x;
        ball->transform->SetPositionX(dimension - ball->collider->Radius);
    }

    if (position.x - ball->collider->Radius <= -dimension)
    {
        ball->body->velocity.x = -velocity.x;
        ball->transform->SetPositionX(-dimension + ball->collider->Radius);
    }

    if (position.z + ball->collider->Radius >= dimension)
    {
        ball->body->velocity.z = -velocity.z;
        ball->transform->SetPositionZ(dimension - ball->collider->Radius);
    }

    if (position.z - ball->collider->Radius <= -dimension)
    {
        ball->body->velocity.z = -velocity.z;
        ball->transform->SetPositionZ(-dimension + ball->collider->Radius);
    }
}

void PhysicsEngine::DrawCollisions(std::vector<Collision*> &collisions, glm::mat4 projection, glm::mat4 view)
{
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(projection));

    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(glm::value_ptr(view));

    glUseProgram(0);
    glDisable(GL_TEXTURE);

    for (const Collision* collision : collisions)
    {
        glPushMatrix();
        glTranslatef(collision->position.x, collision->position.y, collision->position.z);

        glBegin(GL_LINES);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3fv(glm::value_ptr(-collision->normal * 50.0f));
            glVertex3fv(glm::value_ptr(collision->normal));

            glColor3f(1.0f, 1.0f, 0.0f);
            glVertex3fv(glm::value_ptr(collision->tangent * 50.0f));
            glVertex3fv(glm::value_ptr(-collision->tangent));

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3fv(glm::value_ptr(collision->reflection * 50.0f));
            glVertex3fv(glm::value_ptr(-collision->reflection));
        glEnd();

        glPopMatrix();
    }
}