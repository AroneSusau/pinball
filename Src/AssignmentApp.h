#include "RTRApp.h"

#include "Scene.h"

#define MAX_STRING 1024

class AssignmentApp : public RTRApp
{
public:
    AssignmentApp(const char* title, const char* root, bool fullscreen = false, int width = 1024, int height = 768);
    int Init();
    void Done();
    bool Tick(unsigned int td_milli);

    Scene* scene;
    Timer* timer;

    char* text = new char[MAX_STRING + 1];

    const char* root;

private:
    bool m_QuitApp = false;

    void CheckInput();
    void UpdateState(unsigned int td_milli);
    void RenderFrame();
    void RenderOSD();
};
