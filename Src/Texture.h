#pragma once

#include "Common.h"
#include "Shader.h"

class Texture
{
public:

	Texture(std::string path, std::string filename, std::string name, GLenum type);
	~Texture();

	void Init();
	void Apply(int i, Shader* shader);

	unsigned int GetID();

private:

	unsigned int ID;

	std::string path;
	std::string filename;

	std::string name;

	GLenum type;
};