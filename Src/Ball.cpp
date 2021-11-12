#include "Ball.h"

Ball::Ball(float radius, Material* material, Timer* timer)
	: Mesh(new Sphere(radius), material, new SphereCollider(radius, glm::vec3(0.0)), timer)
{
	collider = new SphereCollider(radius, glm::vec3(0.0));
}

void Ball::UpdateState(Timer* clock)
{
    body->Tick(clock->delta);
    
    transform->Translate(body->velocity * clock->delta);
    collider->SetPosition(transform->GetPosition());

    Clamp();
}

void Ball::Animate(Timer* clock)
{
    float cir = 4.5f * M_PI * collider->Radius;

    float rx = (body->velocity.x / cir) * 2.0 * M_PI * (180.0f / M_PI);
    float rz = (body->velocity.z / cir) * 2.0 * M_PI * (180.0f / M_PI);

    transform->Pitch(-rz * clock->delta);
    transform->Roll(-rx * clock->delta);
}

void Ball::Clamp()
{
    body->velocity = glm::clamp(body->velocity, glm::vec3(-5000), glm::vec3(5000));
}

void Ball::Debug(glm::mat4 projection, glm::mat4 view)
{
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(glm::value_ptr(projection));

    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(glm::value_ptr(view));

    glUseProgram(0);
    glDisable(GL_TEXTURE);

    glPushMatrix();
    glTranslatef(transform->position.x, transform->position.y, transform->position.z);

    glBegin(GL_LINES);

    glColor3f(0.25098039215f, 0.87843137254f, 0.815686275f);

    glVertex3f(0.0, 0.0, 0.0);
    glVertex3fv(glm::value_ptr(body->velocity / 10.0f));

    glEnd();

    glPopMatrix();
}

bool Ball::IsDone()
{
    return (
        transform->GetPosition().x < -BALL_BOUNDS || transform->GetPosition().x > BALL_BOUNDS || isnan(transform->position.x) ||
        transform->GetPosition().y < -BALL_BOUNDS || transform->GetPosition().y > BALL_BOUNDS || isnan(transform->position.y) ||
        transform->GetPosition().z < -BALL_BOUNDS || transform->GetPosition().z > BALL_BOUNDS || isnan(transform->position.z)
    );
}
