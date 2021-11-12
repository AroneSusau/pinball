#pragma once

#include "Common.h"

class Model
{
public:

	Model();
	~Model();

	virtual void Generate() = 0;

	void Init();
	void Done();

	void CreateVAO();

	template <typename T>
	void CreateVBO(unsigned int& vbo, std::vector<T> list, int count, int index);

	unsigned int GetVAO();
	int GetSize();

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;
	std::vector<glm::vec2> texels;

private:

	unsigned int vao = 0;

	unsigned int vertex_vbo = 0;
	unsigned int normal_vbo = 0;
	unsigned int texel_vbo  = 0;
};