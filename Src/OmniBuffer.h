#pragma once

#include "Common.h"

class OmniBuffer
{
public:

	OmniBuffer(glm::vec3 lightPos) : lightPos(lightPos) {};

	void Init();
	void Bind();

	unsigned int depthCubemap;
	unsigned int depthMapFBO;
	const unsigned int SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;

	float aspect = (float)SHADOW_WIDTH / (float)SHADOW_HEIGHT;
	
	float near = 1.0f;
	float far = 25.0f;

	glm::vec3 lightPos;

	glm::mat4 shadowProj = glm::perspective(glm::radians(90.0f), aspect, near, far);

	std::vector<glm::mat4> shadowTransforms;
};