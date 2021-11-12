#include "Texture.h"
#include <stb/stb_image.h>

Texture::Texture(std::string path, std::string filename, std::string name, GLenum type)
	: ID(0)
	, path(path)
	, filename(filename)
	, name(name)
	, type(type)
{}

Texture::~Texture()
{}

void Texture::Init()
{
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char* data = stbi_load((path + filename).c_str(), &width, &height, &nrChannels, 0);

	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture: " << filename << " - on path, " << path << std::endl;
	}

	stbi_image_free(data);
}

void Texture::Apply(int index, Shader* shader)
{
	glActiveTexture(GL_TEXTURE0 + index);
	glBindTexture(GL_TEXTURE_2D, ID);

	shader->setInt(name, index);
}

unsigned int Texture::GetID()
{
	return ID;
}