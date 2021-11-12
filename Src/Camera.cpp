#include "Camera.h"

Camera::Camera(float width, float height, Timer* timer)
{
    this->projection = new Projection(width, height);
    this->view       = new View(DEFAULT_CAMERA_POSITION, DEFAULT_CAMERA_FORWARD, DEFAULT_CAMERA_UP);
    this->timer      = new Timer();
}

Camera::~Camera()
{
    timer = nullptr;

    delete view;
    delete projection;
}

void Camera::Tick()
{
    view->Update();
    timer->Tick(SDL_GetTicks() / 1000.0f);
}

void Camera::KeyboardEvents(const Uint8* keys)
{
    float dv = speed * timer->delta;
    
    if (keys[SDL_SCANCODE_W]) {
        this->view->position += dv * this->view->forward;
    }
    if (keys[SDL_SCANCODE_S]) {
        this->view->position -= dv * this->view->forward;
    }
    if (keys[SDL_SCANCODE_Q]) {
        this->view->position -= dv * this->view->up;
    }
    if (keys[SDL_SCANCODE_E]) {
        this->view->position += dv * this->view->up;
    }
    if (keys[SDL_SCANCODE_A]) {
        this->view->position -= glm::normalize(glm::cross(this->view->forward, this->view->up)) * dv;
    }
    if (keys[SDL_SCANCODE_D]) {
        this->view->position += glm::normalize(glm::cross(this->view->forward, this->view->up)) * dv;
    }
}

void Camera::MouseEvents()
{
    Uint32 buttons;
    int x, y;

    buttons = SDL_GetMouseState(&x, &y);

    if (firstMouse)
    {
        lastX = x;
        lastY = y;
        firstMouse = false;
    }

    float xoffset = x - lastX;
    float yoffset = lastY - y;
    lastX = x;
    lastY = y;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    if ((buttons & SDL_BUTTON_LMASK) != 0) {
        yaw += xoffset;
        pitch += yoffset;

        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;

        glm::vec3 temp;
        temp.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        temp.y = sin(glm::radians(pitch));
        temp.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        this->view->forward = glm::normalize(temp);
    }
}
