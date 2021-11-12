#include "Material.h"

Material::Material(std::string name, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, float shininess) :
	Name(name),
	Ambient(ambient),
	Diffuse(diffuse),
	Specular(specular),
	Shininess(shininess)
{};

void Material::Apply(Shader* shader)
{
	shader->setBool("uReflection", false);
	shader->setFloat("uReflectFactor", 0.0);

	shader->setVec4("Colour.Ambient", Ambient);
	shader->setVec4("Colour.Diffuse", Diffuse);
	shader->setVec4("Colour.Specular", Specular);
	shader->setFloat("Colour.Shininess", Shininess);
	shader->setSubroutine(GL_FRAGMENT_SHADER, SELECT_MATERIAL, FLAT_MATERIAL);
}

TexturedMaterial::TexturedMaterial(Texture* diffuse, Texture* specular, float shininess, bool reflects, float reflectFactor) :
	Name("Colour"),
	Ambient(glm::vec4(0.0f)),
	Diffuse(diffuse),
	Specular(specular),
	Shininess(shininess),
	Reflects(reflects),
	ReflectFactor(reflectFactor),
	Material("Colour", glm::vec4(0.0f), glm::vec4(0.0f), glm::vec4(0.0f), shininess)
{};

void TexturedMaterial::Apply(Shader* shader)
{
	shader->setBool("uReflection", Reflects);
	shader->setFloat("uReflectFactor", ReflectFactor);

	Diffuse->Apply(1, shader);
	shader->setInt("uDiffuse", 1);

	Specular->Apply(2, shader);
	shader->setInt("uSpecular", 2);

	shader->setFloat("Colour.Shininess", Shininess);
	shader->setSubroutine(GL_FRAGMENT_SHADER, SELECT_MATERIAL, TEXTURED_MATERIAL);
}

namespace CommonMaterials
{
	Material* Red = new Material(
		"Red",
		glm::vec4(0.5f, 0.0f, 0.2f, 1.0f),
		glm::vec4(0.5f, 0.0f, 0.0f, 1.0f),
		glm::vec4(0.55f, 0.45f, 0.45f, 1.0f),
		10.0f
	);

	Material* Green = new Material(
		"Green",
		glm::vec4(0.0f, 0.5f, 0.0f, 1.0f),
		glm::vec4(0.1f, 0.35f, 0.1f, 1.0f),
		glm::vec4(0.45f, 0.55f, 0.45f, 1.0f),
		70.0f
	);

	Material* Blue = new Material(
		"Blue",
		glm::vec4(0.0f, 0.50980392f, 0.50980392f, 1.0f),
		glm::vec4(0.0f, 0.50980392f, 0.50980392f, 1.0f),
		glm::vec4(0.45f, 0.55f, 0.45f, 1.0f),
		75
	);

	Material* Silver = new Material(
		"Silver",
		glm::vec4(0.23125f, 0.43125f, 0.23125f, 1.0f),
		glm::vec4(0.2775f, 0.2775f, 0.2775f, 1.0f),
		glm::vec4(0.196078f, 0.196078f, 0.196078f, 1.0f),
		90
	);

	Material* Tin = new Material(
		"Tin",
		glm::vec4(0.105882f, 0.058824f, 0.753725f, 1.0f),
		glm::vec4(0.427451f, 0.470588f, 0.541176f, 1.0f),
		glm::vec4(0.4911f, 0.43911f, 0.4911f, 1.0f),
		25
	);

	Material* Yellow = new Material(
		"Yellow",
		glm::vec4(1.0, 1.0, 0.2, 1.0f),
		glm::vec4(1.0, 1.0, 0.2, 1.0f),
		glm::vec4(1.0, 1.0, 0.2, 1.0f),
		5.0
	);

	Material* White = new Material(
		"White",
		glm::vec4(1.0, 1.0, 1.0, 1.0f),
		glm::vec4(1.0, 1.0, 1.0, 1.0f),
		glm::vec4(1.0, 1.0, 1.0, 1.0f),
		100.0f
	);
};
