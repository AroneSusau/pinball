#pragma once

#include <glad/glad.h>
#include <sdl/SDL.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "Shader.h"
#include "Texture.h"

struct Material
{
	std::string Name;
	glm::vec4 Ambient;
	glm::vec4 Diffuse;
	glm::vec4 Specular;
	float Shininess;

	Material(std::string name, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, float shininess);

	virtual void Apply(Shader* shader);
};

struct TexturedMaterial : Material
{
	std::string Name;
	glm::vec4 Ambient;
	Texture* Diffuse;
	Texture* Specular;
	float Shininess;

	bool  Reflects      = false;
	float ReflectFactor = 0.0;

	TexturedMaterial(Texture* diffuse, Texture* specular, float shininess, bool reflects, float reflectFactor);

	void Apply(Shader* shader);

	static TexturedMaterial* Make(std::string root, std::string name, float shininess, GLenum type, bool refects, float reflectFactor)
	{
		Texture* diffuse  = new Texture(root, name + "_d.jpg", "uDiffuse", type);
		Texture* specular = new Texture(root, name + "_s.jpg", "uSpecular", type);

		diffuse->Init();
		specular->Init();

		return new TexturedMaterial(diffuse, specular, shininess, refects, reflectFactor);
	}
};

namespace CommonMaterials
{
	extern Material* Red;
	extern Material* Green;
	extern Material* Blue;
	extern Material* Silver;
	extern Material* Tin;
	extern Material* Yellow;
	extern Material* White;
};
