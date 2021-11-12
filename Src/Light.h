#pragma once

#include <glad/glad.h>
#include <sdl/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <random>
#include <ctime>

#include "Shader.h"
#include "Camera.h"
#include "GenericShapes.h"

#define DEFAULT_DIR_EYE    glm::vec3(-1943.77, 1795.41, 2343.49)
#define DEFAULT_DIR_CENTRE glm::vec3(0.555875, -0.361625, -0.748486)
#define DEFAULT_DIR_UP     glm::vec3(0, 1, 0)

#define DEFAULT_DIR_VIEW   new View(DEFAULT_DIR_EYE, DEFAULT_DIR_CENTRE, DEFAULT_DIR_UP)

#define DEFAULT_NEAR 0.1f
#define DEFAULT_FAR  6000.0f

#define DEFAULT_DISTANCE 4000.0f

#define DEFAULT_DIR_AMBIENT  glm::vec4(0.2f, 0.2f, 0.2f, 1.0f)
#define DEFAULT_DIR_DIFFUSE  glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)
#define DEFAULT_DIR_SPECULAR glm::vec4(1.0f, 1.0f, 1.0f, 1.0f)

struct Light
{
	glm::vec4 Ambient;
	glm::vec4 Diffuse;
	glm::vec4 Specular;

	float Constant  = 1.0f;
	float Linear    = 0.0f;
	float Quadratic = 0.0f;

	float LifeTime     = 1.0f;
	bool IsDestroyable = false;
	bool IsActive      = true;

	View* ViewMatrix;
	Transform* Parent;

	glm::mat4 Projection;
	glm::mat4 LightSpaceMatrix = glm::identity<glm::mat4>();

	int Number;

	glm::vec3 Position;

	Light(glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, View* view, int number = 0, float constant = 1.0, float linear = 0.0, float quadratic = 0.0) :
		Ambient(ambient),
		Diffuse(diffuse),
		Specular(specular),
		ViewMatrix(view),
		Position(view->position),
		Number(number),
		Constant(constant),
		Linear(linear),
		Quadratic(quadratic),
		Projection(glm::identity<glm::mat4>())
	{};

	~Light()
	{
		delete ViewMatrix;
	}

	void EnableDirectional(Shader* shader)
	{
		shader->setVec4("Directional.Ambient",  Ambient);
		shader->setVec4("Directional.Diffuse",  Diffuse);
		shader->setVec4("Directional.Specular", Specular);
		shader->setVec3("Directional.Position", ViewMatrix->position);
		shader->setVec3("Directional.Forward",  ViewMatrix->forward);
	}

	void Enable(Shader* shader)
	{
		std::string key = "uLights[" + std::to_string(Number) + "].";

		shader->setVec4(key + "Ambient",  Ambient);
		shader->setVec4(key + "Diffuse",  Diffuse);
		shader->setVec4(key + "Specular", Specular);
		shader->setVec3(key + "Position", ViewMatrix->position);

		shader->setFloat(key + "Constant", Constant);
		shader->setFloat(key + "Linear", Linear);
		shader->setFloat(key + "Quadratic", Quadratic);
		shader->setBool(key + "Active", IsActive);
	}

	void InitLightSpaceMatrix()
	{

		glm::mat4 lightProjection = glm::ortho(
			-DEFAULT_DISTANCE,
			 DEFAULT_DISTANCE, 
			-DEFAULT_DISTANCE, 
			 DEFAULT_DISTANCE, 
			 DEFAULT_NEAR, 
			 DEFAULT_FAR);

		Projection = lightProjection;

		LightSpaceMatrix = lightProjection * ViewMatrix->matrix;
	}

	void UpdateLightMatrix(glm::mat4 matrix)
	{
		LightSpaceMatrix = Projection * matrix;
	}


	void ApplyLightMatrix(Shader* shader)
	{
		shader->setMat4("uLightSpaceMatrix", LightSpaceMatrix);
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

		glTranslatef(ViewMatrix->position.x, ViewMatrix->position.y, ViewMatrix->position.z);
		glScalef(20.0f, 20.0f, 20.0f);

		glColor3fv(glm::value_ptr(Diffuse));

		glBegin(GL_TRIANGLES);

		for (auto vertex : generic_cube)
			glVertex3fv(glm::value_ptr(vertex));

		glEnd();

		glPopMatrix();
		glEnable(GL_CULL_FACE);
	}

	void Tick(float delta)
	{
		if (IsDestroyable)
			LifeTime -= delta * 8.0f;
	}

	void SetParent(Transform* parent)
	{
		Parent = parent;
	}

	void SetDestroyable(bool value)
	{
		IsDestroyable = value;
	}

	void SetLifeTime(bool value)
	{
		LifeTime = value;
	}

	bool IsDone()
	{
		return LifeTime <= 0.0f && IsDestroyable;
	}

	void UpdatePosition()
	{
		if (Parent != nullptr)
		{
			ViewMatrix->position = Parent->GetReducedMatrix() * glm::vec4(Position, 1.0);
		}
		else
		{
			ViewMatrix->position = Position;
		}
	}

	static Light* CollisionLight(glm::vec3 position, int index)
	{
		Light* light = new Light(
			glm::vec4(0.2, 0.2, 0.2, 1.0),
			glm::vec4(1, 1, 0.2, 1.0),
			glm::vec4(1, 1, 0.2, 1.0),
			new View(position, glm::vec3(0), glm::vec3(0)),
			index, 0.0, 0.005, 0.00001
		);

		light->SetDestroyable(true);
		light->SetLifeTime(0.01);

		return light;
	}
};