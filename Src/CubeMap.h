#pragma once

#include "Camera.h"
#include "Common.h"
#include "Geometry.h"
#include "Shader.h"

class CubeMap
{
public:

	CubeMap(std::string path, std::string ext, GLenum type);

	void Init();
	void Draw(Shader* shader, Camera* camera);

	void Apply();

	unsigned int GetID();

private:

	unsigned int ID;

	Cube* Map;

	GLenum Type;

	std::string Path;

	std::vector<std::string> Faces;
};