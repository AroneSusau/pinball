#pragma once

#include "Common.h"
#include "Plane.h"
#include "Mesh.h"
#include "Material.h"
#include "Timer.h"

class Particle : public Mesh
{
public:
	Particle(Material* color, float lifetime, glm::vec3 position, glm::vec3 velocity, Timer* timer);

	void Tick();

	bool IsDone();

	Timer* timer;

	Material* color;

	glm::vec3 position;
	glm::vec3 velocity;

	float lifetime;

};