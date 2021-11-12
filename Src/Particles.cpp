#include "Particle.h"

Particle::Particle(Material* color, float lifetime, glm::vec3 position, glm::vec3 velocity, Timer* timer)
	: color(color)
	, lifetime(lifetime)
	, position(position)
	, velocity(velocity)
	, timer(timer)
	, Mesh(new Plane(1.0f), color, new Collider(), timer)
{}

void Particle::Tick()
{
	lifetime -= timer->delta;

	transform->Translate(velocity * timer->delta);
	transform->Roll(velocity.x * timer->delta);
}

bool Particle::IsDone()
{
	return lifetime <= 0;
}