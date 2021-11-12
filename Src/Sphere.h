#pragma once

#include "Common.h"
#include "Model.h"

#define DEFAULT_SECTORS 30.0f
#define DEFAULT_STACKS  30.0f

class Sphere : public Model
{
public:
	
	Sphere(float radius, float sectors = DEFAULT_SECTORS, float stacks = DEFAULT_STACKS);

	void Generate();

private:

	float radius;
	float sectors;
	float stacks;

};
