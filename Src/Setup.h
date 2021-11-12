#pragma once

#include "Common.h"
#include "CommonTextures.h"
#include "Colliders.h"
#include "Geometry.h"

#include "Timer.h"

#include "Ball.h"
#include "Cuboid.h"
#include "Peg.h"
#include "Bumper.h"

#include "Light.h"

typedef std::vector<glm::vec2> uv_list;

class Setup
{
public:

	static void Init(Timer* timer, std::vector<Ball*>& balls, std::vector<Cuboid<OBBCollider>*>& cuboids, std::vector<Peg*>& pegs, std::vector<Bumper*>& bumpers, std::vector<Light*>& lights);

	static void PushCuboid(
		Timer* timer, 
		std::vector<Cuboid<OBBCollider>*>& cuboids, 
		glm::vec3 scale,
		glm::vec3 position, 
		glm::vec3 rotation, 
		uv_list uv,
		TexturedMaterial* texture,
		OBBCollider* collider,
		float friction = 0.99f)
	{
		Cuboid<OBBCollider>* cuboid = new Cuboid<OBBCollider>(texture, collider, timer);

		cuboid->SetUV(uv);

		cuboid->Init();

		cuboid->transform->Translate(position);
		cuboid->transform->Scale(scale);

		cuboid->transform->Yaw(rotation.x);
		cuboid->transform->Pitch(rotation.y);
		cuboid->transform->Roll(rotation.z);

		cuboid->body->friction = friction;

		cuboids.push_back(cuboid);
	}
};