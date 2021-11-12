#pragma once

#include <glad/glad.h>
#include <sdl/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string>

#include <vector>
#include <unordered_set>
#include <math.h>

void PrintVec3(glm::vec3 point);
void PrintVec3(glm::vec3 point, std::string desc);

void PrintFloat(float point);
void PrintFloat(float point, std::string desc);

float easeInSine(float x);

float InvLerp(float start, float end, float result);
glm::vec3 Lerp(glm::vec3 start, glm::vec3 end, float time);
float Lerp(float start, float end, float time);