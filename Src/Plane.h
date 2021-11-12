#pragma once

#include "Common.h"
#include "Model.h"

class Plane : public Model
{
public:

	Plane(float uv);

	void Generate();

	float uv;
};