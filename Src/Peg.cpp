#include "Peg.h"

Peg::Peg(float magnetism, TexturedMaterial* material, OBBCollider* collider, Transform* parent, Light* light, Timer* timer)
	: Mesh(new Cylinder(glm::vec2(1, 1), 1, 1, 2, 1, 30), material, collider, timer)
{
    this->collider = collider;
    this->magnetism = magnetism;
    this->timer = timer;
    this->light = light;

    transform->SetParent(parent);
}

void Peg::ApplyForce(Ball* ball)
{
    glm::vec3 ballPos = ball->transform->GetMatrix()[3];
    glm::vec3 pegsPos = transform->GetMatrix()[3];
    
    glm::vec3 distance = pegsPos - ballPos;
    float intensity = 1.0f - fminf(MAX_MAG_DISTANCE, glm::length(distance)) / MAX_MAG_DISTANCE;
    glm::vec3 direction = glm::normalize(distance);

    ball->body->velocity += magnetism * intensity * direction;
}

void Peg::Tick()
{
    collider->SetPosition(glm::vec3(transform->GetMatrix()[3]));
    collider->SetRotation(transform->GetRotationMatrix());

    if (light->IsActive)
    {
        lightTimer -= timer->delta;

        if (lightTimer <= 0.0f)
        {
            Deactivate();
        }
    }
}

void Peg::Activate()
{
    light->IsActive = true;
    lightTimer = lightActiveMax;
}

void Peg::Deactivate()
{
    light->IsActive = false;
}
