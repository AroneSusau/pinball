#pragma once

#include "Common.h"
#include "GenericShapes.h"

enum class collider_type
{
	OBB,
	AABB,
	SPHERE,
	DEFAULT
};

class Collider
{
public:
	glm::vec3 Position;
	collider_type type = collider_type::DEFAULT;

	void Debug(glm::mat4 projection, glm::mat4 view) {};

	glm::vec3 GetPosition()
	{
		return Position;
	}

	void SetPosition(glm::vec3 position) 
	{
		Position = position;
	}
};