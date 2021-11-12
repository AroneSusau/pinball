#pragma once

#include "Common.h"
#include "Geometry.h"
#include "Colliders.h"

#include "Mesh.h"

template <class C>
class Cuboid : public Mesh
{
public:

	Cuboid(Material* material, C* collider, Timer* timer)
		: Mesh(new Cube({ glm::vec2(1.0) , glm::vec2(1.0) , glm::vec2(1.0) }, glm::vec3(0.0)), material, collider, timer)
	{
		this->collider = collider;
	}

	void UpdateState(Timer* clock);

	void SetUV(std::vector<glm::vec2> uv);
	void SetParent(Cuboid<C>* parent);

	Cuboid<C>* Parent;
	C* collider;
};