#pragma once

#include <exception>
#include <ostream>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Shader.hpp"

class Program{
  
private:
    
  std::vector<Shader*> _shaders;
  bool _linked;
  GLuint _id;
   
public:
    
  Program();
  ~Program();
  //loads & compiles the shader and adds it to the end of the program
  void pushShader(std::string filename, GLenum shaderType);
  void link();
  GLuint getId(){return _id;}
  void updateUniform(std::string name, float data);
  void updateUniform(std::string name, glm::vec2 data);
  void updateUniform(std::string name, glm::vec3 data);
  void updateUniform(std::string name, glm::vec4 data);
  void updateUniform(std::string name, int data);
  void updateUniform(std::string name, glm::ivec2 data);
  void updateUniform(std::string name, glm::ivec3 data);
  void updateUniform(std::string name, glm::ivec4 data);
  void updateUniform(std::string name, unsigned int data);
  void updateUniform(std::string name, glm::uvec2 data);
  void updateUniform(std::string name, glm::uvec3 data);
  void updateUniform(std::string name, glm::uvec4 data);
  void updateUniform(std::string name, glm::mat2 data);
  void updateUniform(std::string name, glm::mat3 data);
  void updateUniform(std::string name, glm::mat4 data);
  void updateUniform(std::string name, glm::mat2x3 data);
  void updateUniform(std::string name, glm::mat3x2 data);
  void updateUniform(std::string name, glm::mat2x4 data);
  void updateUniform(std::string name, glm::mat4x2 data);
  void updateUniform(std::string name, glm::mat3x4 data);
  void updateUniform(std::string name, glm::mat4x3 data);
};