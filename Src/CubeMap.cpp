#include "CubeMap.h"
#include <stb/stb_image.h>

CubeMap::CubeMap(std::string path, std::string ext, GLenum type)
{
	auto temp = std::string(path);
	auto base = temp.substr(0, temp.length() - 4);
	
	this->Path = base + "Assets\\CubeMap\\";

	this->Faces.insert(this->Faces.begin(), {
		this->Path + "right." + ext,
		this->Path + "left." + ext,

		this->Path + "top." + ext,
		this->Path + "bottom." + ext,

		this->Path + "front." + ext,
		this->Path + "back." + ext,
	});

	this->Type = type;

	this->Map = new Cube({ glm::vec2(1.0f), glm::vec2(1.0f), glm::vec2(1.0f) }, glm::vec3(1.0f));
	this->Map->Init();

	this->Map->vertices = {
		glm::vec3(-1.0f,  1.0f, -1.0f),
		glm::vec3(-1.0f, -1.0f, -1.0f),
		glm::vec3( 1.0f, -1.0f, -1.0f),
		glm::vec3( 1.0f, -1.0f, -1.0f),
		glm::vec3( 1.0f,  1.0f, -1.0f),
		glm::vec3(-1.0f,  1.0f, -1.0f),

		glm::vec3(-1.0f, -1.0f,  1.0f),
		glm::vec3(-1.0f, -1.0f, -1.0f),
		glm::vec3(-1.0f,  1.0f, -1.0f),
		glm::vec3(-1.0f,  1.0f, -1.0f),
		glm::vec3(-1.0f,  1.0f,  1.0f),
		glm::vec3(-1.0f, -1.0f,  1.0f),

		glm::vec3( 1.0f, -1.0f, -1.0f),
		glm::vec3( 1.0f, -1.0f,  1.0f),
		glm::vec3( 1.0f,  1.0f,  1.0f),
		glm::vec3( 1.0f,  1.0f,  1.0f),
		glm::vec3( 1.0f,  1.0f, -1.0f),
		glm::vec3( 1.0f, -1.0f, -1.0f),

		glm::vec3(-1.0f, -1.0f,  1.0f),
		glm::vec3(-1.0f,  1.0f,  1.0f),
		glm::vec3( 1.0f,  1.0f,  1.0f),
		glm::vec3( 1.0f,  1.0f,  1.0f),
		glm::vec3( 1.0f, -1.0f,  1.0f),
		glm::vec3(-1.0f, -1.0f,  1.0f),

		glm::vec3(-1.0f,  1.0f, -1.0f),
		glm::vec3( 1.0f,  1.0f, -1.0f),
		glm::vec3( 1.0f,  1.0f,  1.0f),
		glm::vec3( 1.0f,  1.0f,  1.0f),
		glm::vec3(-1.0f,  1.0f,  1.0f),
		glm::vec3(-1.0f,  1.0f, -1.0f),

		glm::vec3(-1.0f, -1.0f, -1.0f),
		glm::vec3(-1.0f, -1.0f,  1.0f),
		glm::vec3( 1.0f, -1.0f, -1.0f),
		glm::vec3( 1.0f, -1.0f, -1.0f),
		glm::vec3(-1.0f, -1.0f,  1.0f),
		glm::vec3( 1.0f, -1.0f,  1.0f)
	};
}

void CubeMap::Init()
{
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, ID);

	int width, height, nrChannels;
	for (unsigned int i = 0; i < Faces.size(); i++)
	{
		unsigned char* data = stbi_load(Faces[i].c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, this->Type, width, height, 0, this->Type, GL_UNSIGNED_BYTE, data);
			stbi_image_free(data);
		}
		else
		{
			std::cout << "Cubemap texture failed to load at path: " << Faces[i] << std::endl;
			stbi_image_free(data);
		}
	}

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

void CubeMap::Draw(Shader* shader, Camera* camera)
{
	glDepthFunc(GL_LEQUAL);
	glCullFace(GL_FRONT);

	shader->setMat4("uView", glm::mat4(glm::mat3(camera->view->matrix)));
	shader->setMat4("uModel", glm::identity<glm::mat4>());

	shader->setInt("uCubeMap", 0);
	shader->setBool("isCubeMap", 1);

	glBindVertexArray(this->Map->GetVAO());

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, this->ID);

	glDrawArrays(GL_TRIANGLES, 0, 36);

	shader->setBool("isCubeMap", 0);

	glBindVertexArray(0);

	glCullFace(GL_BACK);
	glDepthFunc(GL_LESS);

	glUseProgram(0);
	glBindVertexArray(0);
}

unsigned int CubeMap::GetID()
{
	return this->ID;
}