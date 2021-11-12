#pragma once

#include "Common.h"
#include "Timer.h"

class RigidBody
{
public:
	
	RigidBody(Timer* timer) : timer(timer) {};

	float mass = 90.0f;
	float elasticity = 0.25;
	float friction = 0.99;

	float cutoff = 0.001f;

	glm::vec3 gravity      = glm::vec3(0.0f, -7000.0f, 0.0f);

	glm::vec3 velocity     = glm::vec3(0.0);
	glm::vec3 acceleration = glm::vec3(0.0);

	Timer* timer;

	void Tick(float delta) 
	{
		velocity += (acceleration + gravity) * delta;
	}
};