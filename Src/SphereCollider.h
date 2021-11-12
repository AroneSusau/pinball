#pragma once

#include "Collider.h"

class SphereCollider : public Collider
{
public:
	
	SphereCollider(float radius, glm::vec3 position) 
		: Radius(radius) 
		, Position(position)
	{}

	void SetRadius(float radius)
	{
		Radius = radius;
	}

	float GetRadius()
	{
		return Radius;
	}

	void Debug(glm::mat4 projection, glm::mat4 view)
	{
		glDisable(GL_CULL_FACE);
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(glm::value_ptr(projection));

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(glm::value_ptr(view));

		glUseProgram(0);
		glDisable(GL_TEXTURE);

		glPushMatrix();
		glTranslatef(GetPosition().x, GetPosition().y, GetPosition().z);
		glScalef(1.05, 1.05, 1.05);

		glColor3f(1.0f, 0.0f, 1.0f);

		glBegin(GL_LINES);

		for (auto triangle : generic_sphere)
		{
			glVertex3fv(glm::value_ptr(triangle));
		}

		glEnd();

		glPopMatrix();
		glEnable(GL_CULL_FACE);
	}

	glm::vec3 Position;

	collider_type type = collider_type::SPHERE;

	float Radius;

};