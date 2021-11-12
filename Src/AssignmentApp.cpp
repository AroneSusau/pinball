#include "AssignmentApp.h"

#define GLT_IMPLEMENTATION
#include <gltext/gltext.h>

AssignmentApp::AssignmentApp(const char* title, const char* root, bool fullscreen, int width, int height)
    : root(root), RTRApp(title, fullscreen, width, height)
{}

bool AssignmentApp::Tick(unsigned int td_milli)
{
    m_QuitApp = false;
    CheckInput();
    UpdateState(td_milli);
    RenderFrame();
    return m_QuitApp;
}

void AssignmentApp::CheckInput()
{
    const Uint8* keys;
    SDL_Event e;

    SDL_PumpEvents();

    if (keys = SDL_GetKeyboardState(nullptr)) {
        if (keys[SDL_SCANCODE_ESCAPE]) {
            m_QuitApp = true;
        }
        
        scene->camera->KeyboardEvents(keys);
    }

    if (SDL_PollEvent(&e) == 1)
    {
        auto sym = e.key.keysym.sym;

        if (e.type == SDL_KEYDOWN)
        {
            scene->KeyDown(e);
        }
        else if (e.type == SDL_KEYUP)
        {
            scene->KeyUp(e);
        }
    }

    scene->camera->MouseEvents();
}

void AssignmentApp::UpdateState(unsigned int td_milli)
{
    timer->Tick(td_milli);
    scene->camera->Tick();
}

void AssignmentApp::RenderOSD()
{
    if (scene->displayHud)
    {
        float scale = 1.0f;
        glm::vec2 position = glm::vec2(10, 10);

        sprintf_s(text, MAX_STRING,
            "FPS: %i\n"
            "%s\n"
            "\n"
            "Physics: %s\n"
            "Velocities: %s\n"
            "Slow Motion: %s\n"
            "\n"
            "Collision Debug: %s\n"
            "Collision Bruteforce: %s\n"
            "Collider Debug: %s\n"
            "\n"
            "Octree Debug: %s\n"

            , (int)timer->fps
            , scene->BufferToString().c_str()

            , scene->ActiveToString(scene->running).c_str()
            , scene->ActiveToString(scene->velocityDebug).c_str()
            , scene->ActiveToString(scene->slowmo).c_str()

            , scene->ActiveToString(scene->collisionDebug).c_str()
            , scene->ActiveToString(scene->bruteforce).c_str()
            , scene->ActiveToString(scene->colliderDebug).c_str()

            , scene->ActiveToString(scene->volatileDebug).c_str());

        GLTtext* message = gltCreateText();
        gltSetText(message, text);

        float width = gltGetTextWidth(message, scale);
        float height = gltGetTextWidth(message, scale);

        gltBeginDraw();
        gltColor(0.0f, 1.0f, 0.0f, 1.0f);
        gltDrawText2D(message, position.x, position.y, scale);
        gltEndDraw();

        gltDeleteText(message);

        glUseProgram(0);
    }
}

void AssignmentApp::RenderFrame()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
    scene->Tick();

    RenderOSD();

    SDL_GL_SwapWindow(m_SDLWindow);
}

int AssignmentApp::Init()
{
    if (int err = RTRApp::Init() != 0) {
        return err;
    }

    gltInit();
    glViewport(0, 0, m_WindowWidth, m_WindowHeight);

    timer = new Timer();
    scene = new Scene(root, m_WindowWidth, m_WindowHeight, timer);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    scene->Init();

    return 0;
}

void AssignmentApp::Done()
{
    gltTerminate();

    scene->Done();
    RTRApp::Done();
}
