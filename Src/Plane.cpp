#include "Plane.h"

Plane::Plane(float uv)
	: uv(uv)
{}

void Plane::Generate()
{
	vertices.insert(vertices.begin(), {
		glm::vec3(-1, -1, 0),
		glm::vec3( 1, -1, 0),
		glm::vec3( 1,  1, 0),

		glm::vec3( 1,  1, 0),
		glm::vec3(-1,  1, 0),
		glm::vec3(-1, -1, 0),

	});

	texels.insert(texels.begin(), {
		glm::vec2(0, 0)* uv,
		glm::vec2(1, 0)* uv,
		glm::vec2(1, 1)* uv,

		glm::vec2(1, 1)* uv,
		glm::vec2(0, 1)* uv,
		glm::vec2(0, 0)* uv,
	});

	normals.insert(normals.begin(), {
		glm::vec3(0, 0, 1),
		glm::vec3(0, 0, 1),
		glm::vec3(0, 0, 1),

		glm::vec3(0, 0, 1),
		glm::vec3(0, 0, 1),
		glm::vec3(0, 0, 1),
	});
}