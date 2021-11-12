#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glad/glad.h>
#include <sdl/SDL.h>

#include "Timer.h"

#define DEFAULT_CAMERA_POSITION glm::vec3(21.7654, 1278.5, 3561.4)
#define DEFAULT_CAMERA_FORWARD glm::vec3(- 0.0144908, -0.385906, -0.922424)
#define DEFAULT_CAMERA_UP glm::vec3(0.0f, 1.0f, 0.0f)

#define DEFAULT_CAMERA_SPEED 500.0f

struct Projection {
	
	float width  = 0;
	float height = 0;

	float fovy   = 60.0f;
	float aspect = 0;
	float znear  = 0.1f;
	float zfar   = 10000.0f;

	glm::mat4 matrix = glm::mat4();

	Projection(float width, float height)
	{
		this->width = width;
		this->height = height;
		this->aspect = (float)width / (float)height;

		this->matrix = glm::perspective(
			glm::radians(fovy),
			aspect,
			znear,
			zfar
		);
	}
};

struct View {

	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 up;

	glm::mat4 matrix = glm::mat4();

	View(glm::vec3 position, glm::vec3 forward, glm::vec3 up)
		: position(position)
		, forward(forward)
		, up(up)
	{
		Update();
	}

	void Update() 
	{
		matrix = glm::lookAt(
			position,
			position + forward,
			up
		);
	}
};

class Camera
{
public:

	Camera(float width, float height, Timer* timer);
	~Camera();

	void Tick();

	void KeyboardEvents(const Uint8* keys);
	void MouseEvents();

	Projection* projection;
	View*	    view;
	Timer*	    timer;

private:

	bool  firstMouse = true;

	float yaw = -90.0f;
	float pitch = 0.0f;
	float lastX = 800.0f / 2.0f;
	float lastY = 600.0f / 2.0f;

	float speed = DEFAULT_CAMERA_SPEED;

};