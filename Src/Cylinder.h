#pragma once

#pragma once

#include "Common.h"
#include "Model.h"

class Cylinder : public Model
{
public:

	Cylinder(glm::vec2 uv, float baseRadius, float topRadius, float height, float stack, float sector);

	std::vector<float> getUnitCircleVertices();
	void Generate();

	glm::vec2 uv;

	float baseRadius;
	float topRadius;

	float height;
	float stackCount;
	float sectorCount;
};