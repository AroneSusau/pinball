#include "Cube.h"

Cube::Cube(std::vector<glm::vec2> uv, glm::vec3 size)
	: uv(uv)
{}

void Cube::Generate()
{
	glm::vec3 v[8] = {
		glm::vec3( 1,  1, 1), // 0 t-r
		glm::vec3(-1,  1, 1), // 1 t-l
		glm::vec3(-1, -1, 1), // 2 b-l
		glm::vec3( 1, -1, 1), // 3 b-r

		glm::vec3( 1,  1, -1), // 4 t-r
		glm::vec3(-1,  1, -1), // 5 t-l
		glm::vec3(-1, -1, -1), // 6 b-l
		glm::vec3( 1, -1, -1), // 7 b-r
	};

	glm::vec2 t[8] = {
		glm::vec2(0, 0), // b-l
		glm::vec2(0, 1), // t-l
		glm::vec2(1, 1), // t-r
		glm::vec2(1, 0), // b-r
	};

	glm::vec3 n[8] = {
		glm::vec3( 1,  1, 1),
		glm::vec3(-1,  1, 1),
		glm::vec3(-1, -1, 1),
		glm::vec3( 1, -1, 1),

		glm::vec3( 1,  1, -1),
		glm::vec3(-1,  1, -1),
		glm::vec3(-1, -1, -1),
		glm::vec3( 1, -1, -1),
	};

	vertices.insert(vertices.begin(), {
		v[1], v[2], v[3], // front
		v[3], v[0], v[1],

		v[5], v[4], v[7], // back
		v[7], v[6], v[5],

		v[1], v[5], v[6], // left
		v[6], v[2], v[1],

		v[0], v[3], v[7], // right
		v[7], v[4], v[0],

		v[1], v[0], v[4], // top
		v[4], v[5], v[1],

		v[3], v[2], v[6], // bottom
		v[6], v[7], v[3],
	});

	texels.insert(texels.begin(), {
		t[2] * uv[0], t[3] * uv[0], t[0] * uv[0],
		t[0] * uv[0], t[1] * uv[0], t[2] * uv[0],

		t[2] * uv[0], t[1] * uv[0], t[0] * uv[0],
		t[0] * uv[0], t[3] * uv[0], t[2] * uv[0],

		t[1] * uv[1], t[2] * uv[1], t[3] * uv[1],
		t[3] * uv[1], t[0] * uv[1], t[1] * uv[1],

		t[1] * uv[1], t[0] * uv[1], t[3] * uv[1],
		t[3] * uv[1], t[2] * uv[1], t[1] * uv[1],

		t[1] * uv[2], t[2] * uv[2], t[3] * uv[2],
		t[3] * uv[2], t[0] * uv[2], t[1] * uv[2],

		t[0] * uv[2], t[3] * uv[2], t[2] * uv[2],
		t[2] * uv[2], t[1] * uv[2], t[0] * uv[2],
	});

	normals.insert(normals.begin(), {
		n[1], n[2], n[3], // front
		n[3], n[0], n[1],

		n[5], n[4], n[7], // back
		n[7], n[6], n[5],

		n[1], n[5], n[6], // left
		n[6], n[2], n[1],

		n[0], n[3], n[7], // right
		n[7], n[4], n[0],

		n[1], n[0], n[4], // top
		n[4], n[5], n[1],

		n[3], n[2], n[6], // bottom
		n[6], n[7], n[3],
	});
}