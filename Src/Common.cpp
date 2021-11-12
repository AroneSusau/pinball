#include "Common.h"

void PrintVec3(glm::vec3 point) {
	std::cout << point.x << ", " << point.y << ", " << point.z << std::endl;
}

void PrintVec3(glm::vec3 point, std::string desc) {
	std::cout << desc << ": " << point.x << ", " << point.y << ", " << point.z << std::endl;
}

void PrintFloat(float point) {
	std::cout << point << std::endl;
}

void PrintFloat(float point, std::string desc) {
	std::cout << desc << ": " << point << std::endl;
}

float easeInSine(float x) {
  return 1.0f - cos((x * M_PI) / 2.0f);
}

float InvLerp(float start, float end, float result)
{
	return (result - start) / (end - start);
}

glm::vec3 Lerp(glm::vec3 start, glm::vec3 end, float time)
{
	return (1.0f - time) * start + time * end;
}

float Lerp(float start, float end, float time)
{
	return (1.0f - time) * start + time * end;
}
