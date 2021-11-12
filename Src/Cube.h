#pragma once

#include "Common.h"
#include "Model.h"

class Cube : public Model
{
public:

	Cube(std::vector<glm::vec2> uv, glm::vec3 size);

	void Generate();

	std::vector<glm::vec2> uv;
	glm::vec3 size;
};