#pragma once

#include "Common.h"
#include "Geometry.h"
#include "Colliders.h"

#include "Mesh.h"

#define BALL_BOUNDS 3000.0f

class Ball : public Mesh
{
public:

	Ball(float radius, Material* material, Timer* timer);

	void UpdateState(Timer* clock);
	void Animate(Timer* clock);
	void Clamp();

	void Debug(glm::mat4 projection, glm::mat4 view);

	bool IsDone();

	SphereCollider* collider;
};