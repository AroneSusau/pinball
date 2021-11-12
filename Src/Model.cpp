#include "Model.h"

Model::Model()
{}

Model::~Model()
{
	Done();
}

void Model::Init()
{
    Generate();

    CreateVAO();

    CreateVBO(vertex_vbo, vertices, 3, 0);
    CreateVBO(normal_vbo, normals,  3, 1);
    CreateVBO(texel_vbo,  texels,   2, 2);
}

void Model::Done()
{	
    glDeleteBuffers(1, &vertex_vbo);
    glDeleteBuffers(1, &normal_vbo);
    glDeleteBuffers(1, &texel_vbo);

	glDeleteVertexArrays(1, &vao);
}

template <typename T>
void Model::CreateVBO(unsigned int &vbo, std::vector<T> list, int count, int index)
{
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(T) * list.size(), &list[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, count, GL_FLOAT, GL_FALSE, sizeof(T), (void*) 0);
}

void Model::CreateVAO()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

unsigned int Model::GetVAO()
{
	return vao;
}

int Model::GetSize()
{
    return vertices.size();
}
