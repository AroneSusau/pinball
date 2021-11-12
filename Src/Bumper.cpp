#include "Bumper.h"

Bumper::Bumper(float impulse, float direction, glm::vec3 start, glm::vec3 end, TexturedMaterial* material, OBBCollider* collider, Transform* parent, Timer* timer)
    : Mesh(new Cylinder(glm::vec2(1, 1), 3, 1, 2, 1, 4), material, collider, timer)
{
    this->collider = collider;
    this->timer = timer;
    this->direction = direction;
    this->body->friction = impulse;

    this->start = start;
    this->end = end;

    transform->SetParent(parent);
}

void Bumper::Tick()
{
    duration += countdown ? -timer->delta / 2.0f : timer->delta / 2.0f;

    if (duration >= 1)
    {
        countdown = true;
        duration = 1.0f;
    }
    else if (duration <= 0)
    {
        countdown = false;
        duration = 0.0f;
    }

    transform->SetPosition(Lerp(start, end, duration));
    transform->Yaw(140.0f * timer->delta * direction);
    collider->SetPosition(glm::vec3(transform->GetMatrix()[3]));
    collider->SetRotation(transform->GetRotationMatrix());
}
