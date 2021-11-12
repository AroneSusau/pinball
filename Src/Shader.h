#pragma once

#include "Common.h"

#include <fstream>

#ifndef FRAG_SUBROUTINES
    #define FRAG_SUBROUTINES
    #define SELECT_MATERIAL   "SelectMaterial"
    #define CUBEMAP_MATERIAL  "CubeMapMaterial"
    #define FLAT_MATERIAL     "FlatMaterial"
    #define TEXTURED_MATERIAL "TexturedMaterial"
#endif

class Shader
{
public:
	Shader(std::string path, std::string vertex, std::string geometry, std::string fragement);
    Shader(std::string path, std::string vertex, std::string fragement);

	std::string Vertex;
	std::string Geometry;
	std::string Fragement;

	unsigned int ID;

	void Init();

	unsigned int Load(std::string path, GLenum shadertype);

    void Use();

    void setBool(const std::string& name, bool value);
    void setInt(const std::string& name, int value);
    void setFloat(const std::string& name, float value);

    void setVec2(const std::string& name, const glm::vec2& value);
    void setVec2(const std::string& name, float x, float y);

    void setVec3(const std::string& name, const glm::vec3& value);
    void setVec3(const std::string& name, float x, float y, float z);

    void setVec4(const std::string& name, const glm::vec4& value);
    void setVec4(const std::string& name, float x, float y, float z, float w);

    void setMat2(const std::string& name, const glm::mat2& mat);
    void setMat3(const std::string& name, const glm::mat3& mat);
    void setMat4(const std::string& name, const glm::mat4& mat);

    void setSubroutine(GLenum shadertype, const std::string& functionality, const std::string& selection);
};