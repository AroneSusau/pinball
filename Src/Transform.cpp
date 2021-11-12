#include "Transform.h"

Transform::Transform()
	: translate(glm::identity<glm::mat4>())
	, rotate(glm::identity<glm::mat4>())
	, scale(glm::identity<glm::mat4>())
	, position(glm::vec3(0.0f))
{
}

Transform::~Transform()
{}

void Transform::Translate(glm::vec3 amount)
{
	position += amount;
	translate = glm::translate(glm::identity<glm::mat4>(), position);
}

void Transform::Roll(float degrees)
{
	float radians = glm::radians(degrees);

	right = glm::normalize((right * cosf(radians) + (up * sinf(radians))));
	up    = glm::cross(forward, right);
}

void Transform::Pitch(float degrees)
{
	float radians = glm::radians(degrees);

	forward = glm::normalize((forward * cosf(radians) + (up * sinf(radians))));
	up = glm::cross(forward, right);
}

void Transform::Yaw(float degrees)
{
	float radians = glm::radians(degrees);

	forward = glm::normalize((forward * cosf(radians) - (right * sinf(radians))));
	right = glm::cross(forward, up);
}

void Transform::Scale(glm::vec3 amount)
{
	scale = glm::scale(scale, amount);
}

glm::mat4 Transform::GetMatrix()
{
	rotate = glm::lookAt(glm::vec3(0, 0, 0), forward, up);

	if (hasParent)
	{
		return parent->GetReducedMatrix() * (translate * rotate * scale);
	}
	else
	{
		return translate * rotate * scale;
	}	
}

glm::mat4 Transform::GetReducedMatrix()
{
	if (hasParent)
	{
		return parent->GetReducedMatrix() * (translate * rotate);
	}
	else
	{
		return translate * rotate;
	}
}

glm::vec3 Transform::GetPosition()
{
	return position;
}

glm::mat4 Transform::GetRotationMatrix()
{
	if (hasParent)
	{
		return parent->GetRotationMatrix() * glm::lookAt(glm::vec3(0, 0, 0), forward, up);
	}
	else
	{
		return glm::lookAt(glm::vec3(0, 0, 0), forward, up);
	}
}

void Transform::SetParent(Transform* transform)
{
	parent = transform;
	hasParent = true;
}

void Transform::SetPosition(glm::vec3 value)
{
	position = value;
	translate = glm::translate(glm::identity<glm::mat4>(), position);
}

void Transform::SetPositionX(float value)
{
	position.x = value;
}

void Transform::SetPositionY(float value)
{
	position.y = value;
}

void Transform::SetPositionZ(float value)
{
	position.z = value;
}
