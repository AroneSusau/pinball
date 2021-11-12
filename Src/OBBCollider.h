#pragma once

#include "Collider.h"

class OBBCollider : public Collider
{
public:

	OBBCollider(glm::vec3 position, glm::vec3 size)
		: Position(position)
		, Rotation(glm::identity<glm::mat4>())
		, Width(size.x)
		, Height(size.y)
		, Depth(size.z)
	{};

	glm::mat4 GetRotation() 
	{
		return Rotation;
	};

	void SetPosition(glm::vec3 position)
	{
		Position = position;
	}

	void SetRotation(glm::mat4 matrix)
	{
		Rotation = matrix;
	};

	std::vector<float> SizeList()
	{	
		return { Width, Height, Depth };
	};

	glm::vec3 SizeVector3()
	{
		return glm::vec3(Width, Height, Depth);
	};

	void Debug(glm::mat4 projection, glm::mat4 view)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDisable(GL_CULL_FACE);
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(glm::value_ptr(projection));

		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(glm::value_ptr(view));

		glUseProgram(0);
		glDisable(GL_TEXTURE);

		glPushMatrix();

		glTranslatef(Position.x, Position.y, Position.z);
		glMultMatrixf(glm::value_ptr(Rotation));
		glScalef(Width + 5, Height + 5, Depth + 5);

		glColor3f(1.0f, 1.0f, 1.0f);

		glBegin(GL_TRIANGLES);
			
		for (auto triangle : generic_cube)
		{
			glVertex3fv(glm::value_ptr(triangle));
		}

		glEnd();

		glPopMatrix();
		glEnable(GL_CULL_FACE);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	glm::vec3 Position;
	glm::mat4 Rotation;

	collider_type type = collider_type::OBB;

	float Width;
	float Height;
	float Depth;
};