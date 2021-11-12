#pragma once

#include "Common.h"
#include "Geometry.h"
#include "Colliders.h"

#include "Ball.h"

#include "Mesh.h"

class Bumper : public Mesh
{
public:

	Bumper(float impulse, float direction, glm::vec3 start, glm::vec3 end, TexturedMaterial* material, OBBCollider* collider, Transform* parent, Timer* timer);

	void Tick();

	OBBCollider* collider;
	Timer* timer;

	glm::vec3 start;
	glm::vec3 end;

	float duration = 0.0f;
	float direction = 1;

	bool countdown = false;
};