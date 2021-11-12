#include "Shader.h"

Shader::Shader(std::string path, std::string vertex, std::string geometry, std::string fragement) : 
    Vertex(path + vertex),
    Geometry(path + geometry),
    Fragement(path + fragement),
    ID(0)
{}

Shader::Shader(std::string path, std::string vertex, std::string fragement) :
    Vertex(path + vertex),
    Geometry(""),
    Fragement(path + fragement),
    ID(0)
{}

void Shader::Init()
{
    unsigned int vertex = Load(Vertex, GL_VERTEX_SHADER);
    unsigned int geometry = 0;
    unsigned int fragement = Load(Fragement, GL_FRAGMENT_SHADER);

    int err_ok;
    char err_info[512];

    ID = glCreateProgram();

    glAttachShader(ID, vertex);

    if (Geometry != "")
    {
        geometry = Load(Geometry, GL_GEOMETRY_SHADER);
        glAttachShader(ID, geometry);
    }

    glAttachShader(ID, fragement);
    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &err_ok);

    if (!err_ok) {
        glGetProgramInfoLog(ID, 512, NULL, err_info);
        std::cout << "RTR:ERROR: Shader Program failed to link. Error: " << err_info << std::endl;
    }

    if (Geometry != "")
    {
        glDeleteShader(geometry);
    }

    glDeleteShader(vertex);
    glDeleteShader(fragement);
}

unsigned int Shader::Load(std::string path, GLenum shadertype)
{
	std::ifstream in(path.c_str());
	std::string shader((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

	int err_ok;
    char err_info[512];
    
    const char* source = shader.c_str();
    unsigned int id = glCreateShader(shadertype);

    glShaderSource(id, 1, &source, nullptr);
    glCompileShader(id);
    glGetShaderiv(id, GL_COMPILE_STATUS, &err_ok);

    if (!err_ok) {
        glGetShaderInfoLog(id, 512, nullptr, err_info);
        std::cout << "RTR:ERROR: Shader failed to compile. Error: " << err_info << std::endl;
    }

    return id;
}

void Shader::Use()
{
    glUseProgram(ID);
}

void Shader::setBool(const std::string& name, bool value)
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string& name, int value)
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value)
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setVec2(const std::string& name, const glm::vec2& value)
{
    glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}
void Shader::setVec2(const std::string& name, float x, float y)
{
    glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
}

void Shader::setVec3(const std::string& name, const glm::vec3& value)
{
    glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}
void Shader::setVec3(const std::string& name, float x, float y, float z)
{
    glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
}

void Shader::setVec4(const std::string& name, const glm::vec4& value)
{
    glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::setVec4(const std::string& name, float x, float y, float z, float w)
{
    glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
}

void Shader::setMat2(const std::string& name, const glm::mat2& mat)
{
    glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setMat3(const std::string& name, const glm::mat3& mat)
{
    glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setMat4(const std::string& name, const glm::mat4& mat)
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setSubroutine(GLenum shadertype, const std::string& functionality, const std::string& selection)
{
    GLuint funcIndex = glGetSubroutineIndex(ID, shadertype, functionality.c_str());
    GLuint selectIndex = glGetSubroutineIndex(ID, shadertype, selection.c_str());

    glUniformSubroutinesuiv(shadertype, 1, &funcIndex);
    glUniformSubroutinesuiv(shadertype, 1, &selectIndex);
}