#pragma once

#include "Common.h"

class Transform
{
public:

	Transform();
	~Transform();

	void Translate(glm::vec3 amount);
	
	void Roll(float degrees);
	void Pitch(float degrees);
	void Yaw(float degrees);

	void Scale(glm::vec3 amount);

	glm::mat4 GetMatrix();
	glm::mat4 GetReducedMatrix();
	
	glm::vec3 GetPosition();

	glm::mat4 GetRotationMatrix();
	
	void SetParent(Transform* matrix);

	void SetPosition(glm::vec3 value);

	void SetPositionX(float value);
	void SetPositionY(float value);
	void SetPositionZ(float value);

	glm::vec3 position;

	glm::vec3 forward = glm::vec3(0, 0, -1);
	glm::vec3 right = glm::vec3(1, 0, 0);
	glm::vec3 up = glm::vec3(0, 1, 0);

	glm::mat4 translate;
	glm::mat4 rotate;
	glm::mat4 scale;

	Transform* parent;
	bool hasParent = false;
};