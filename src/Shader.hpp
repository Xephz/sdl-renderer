#pragma once

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <GL/glew.h>

class Shader{
  
private:

  GLenum _shaderType;
  std::string _source;
  GLuint _id;
    
public:
  //loads from FileName and compiles shader on construction
  Shader(std::string fileName, GLenum type);
  ~Shader();
  GLuint getId(){return _id;}
};