#pragma once

#include "Collider.h"

class AABBCollider : public Collider
{
public:

	AABBCollider(glm::vec3 position, glm::vec3 size) 
		: Position(position)
		, Width(size.x)
		, Height(size.y)
		, Depth(size.z)
	{};

	glm::vec3 Position;

	void SetPosition(glm::vec3 position) 
	{
		Position = position;
	}

	glm::vec3 SizeVector3()
	{
		return glm::vec3(Width, Height, Depth);
	};

	collider_type type = collider_type::AABB;

	float Width;
	float Height;
	float Depth;
};