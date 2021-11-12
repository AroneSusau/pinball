#pragma once

#include "Common.h"
#include "Geometry.h"
#include "Colliders.h"

#include "Ball.h"

#include "Mesh.h"
#include "Light.h"

#define MAX_MAG_DISTANCE 1000.0f

class Peg : public Mesh
{
public:

	Peg(float magnetism, TexturedMaterial* material, OBBCollider* collider, Transform* parent, Light* light, Timer* timer);

	void ApplyForce(Ball* ball);

	void Tick();

	void Activate();
	void Deactivate();

	OBBCollider* collider;
	Light*		 light;
	Timer*		 timer;

	float magnetism;

	float lightTimer = 0.0;
	float lightActiveMax = 0.5f;
};