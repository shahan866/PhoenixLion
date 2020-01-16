#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Component.h"

namespace EH
{
	/**
	*Represents Shader Component
	*/

  class Shader : public Component 
  {

  public:
    unsigned int ID;///<Program ID

    //Constructor reads and builds Shader

	/**
	*\brief Read vertex shader and fragment shaders onInit
	*/
    void onInit(const GLchar* vertexShaderFilePath, const GLchar* fragmentShaderFilePath);


	/**
	*\brief Activate the shader
	*/
    void onDisplay();

	/**
	*\brief Utility Uniform Functions
	*/
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec2(const std::string &name, const glm::vec2 &value) const;
    void setVec2(const std::string &name, float x, float y) const;
    void setVec3(const std::string &name, const glm::vec3 &value) const;
    void setVec3(const std::string &name, float x, float y, float z) const;
    void setVec4(const std::string &name, const glm::vec4 &value) const;
    void setVec4(const std::string &name, float x, float y, float z, float w);
    void setMat2(const std::string &name, const glm::mat2 &mat) const;
    void setMat3(const std::string &name, const glm::mat3 &mat) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;
  };
}

/*

REFRRENCE

LearnOpenGL, 2016. CoordinateSystems [online]. Available from:
https://learnopengl.com/Getting-started/Coordinate-Systems [Accessed on:
14th January 2020].

*/