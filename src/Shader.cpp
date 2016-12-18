#include "Shader.hpp"

Shader::Shader(std::string fileName, GLenum type)
: _id(0){
  
  //check the shader type
  if(!(type == GL_FRAGMENT_SHADER ||//check that the type is valid
       type == GL_VERTEX_SHADER ||
       type == GL_GEOMETRY_SHADER)){
    std::cout << "Shader type invalid\n";
    throw std::exception();
  }
  
  //load the shader
  std::ifstream fp(fileName);
  if(fp.is_open()){
    std::stringstream buffer;
    buffer << fp.rdbuf();
    if((_id = glCreateShader(type)) != 0){
      _source = buffer.str();
      const char* sourceCstr = _source.c_str();
      glShaderSource(_id, 1, &sourceCstr, NULL);
    }
    else{
      std::cout << "OpenGL could not create shader\n";
      throw std::exception();
    }
  }
  else{
    std::cout << "GLSL source not found\n";
    throw std::exception();
  }
  
  //compile the shader  
  glCompileShader(_id);
  GLint status = 0;
  glGetShaderiv(_id, GL_COMPILE_STATUS, &status);
  if(status == GL_FALSE){
    GLint infoLogLenth;
    glGetShaderiv(_id, GL_INFO_LOG_LENGTH, &infoLogLenth);
    GLchar infoLog[infoLogLenth + 1];
    glGetShaderInfoLog(_id, infoLogLenth, NULL, infoLog);
    std::cout << "Shader could not compile:" << infoLog << "\n";
    throw std::exception();
  }
}

Shader::~Shader(){
  glDeleteShader(_id);
}