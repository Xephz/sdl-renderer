#include "Program.hpp"

Program::Program(){
  _id = glCreateProgram();
  _linked = false;
}

Program::~Program(){
  while(_shaders.empty() == false){
    glDetachShader(_id, _shaders.back()->getId());
    delete _shaders.back();
    _shaders.pop_back();
  }
  
  glDeleteProgram(_id);
  
  //TODO figure out why this throws an error
  /*
  GLenum GLerr = glGetError();
  if(GLerr != GL_NO_ERROR){
    std::cout << "Error deleting program:" << (int)GLerr << "\n";
  }*/
}

void Program::pushShader(std::string filename, GLenum shaderType){
  if(_linked == true){
    std::cout << "Cannot add shader to linked program\n";
    return;
  }
  
  glUseProgram(_id);
  Shader *s;
  try{
    s = new Shader(filename, shaderType);
    _shaders.push_back(s);
    glAttachShader(_id, s->getId());
  }
  catch(std::exception){
    std::cout << "Shader " << filename << " could not be added to program\n";
  }
}

void Program::link(){
  if(_linked == true){
    std::cout << "Program already linked cannot link again\n";
    return;
  }
  
  glLinkProgram(_id);

  GLint GLerr;
  glGetProgramiv(_id, GL_LINK_STATUS, &GLerr);
  if(GLerr == GL_FALSE){
    std::cout << "Error linking program\n";
  }
  else{
    _linked = true;
  }
}

void Program::updateUniform(std::string label, float data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniform1fv(location, 1, &data);
}

void Program::updateUniform(std::string label, glm::vec2 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniform2fv(location, 1, (float*)&data);
}

void Program::updateUniform(std::string label,  glm::vec3 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniform3fv(location, 1, (float*)&data);
}

void Program::updateUniform(std::string label, glm::vec4 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniform4fv(location, 1, (float*)&data);
}

void Program::updateUniform(std::string label, int data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniform1iv(location, 1, &data);
}

void Program::updateUniform(std::string label, glm::ivec2 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniform2iv(location, 1, (int*)&data);
}

void Program::updateUniform(std::string label,  glm::ivec3 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniform3iv(location, 1, (int*)&data);
}

void Program::updateUniform(std::string label, glm::ivec4 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniform4iv(location, 1, (int*)&data);
}

void Program::updateUniform(std::string label, unsigned int data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniform1uiv(location, 1, &data);
}

void Program::updateUniform(std::string label, glm::uvec2 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniform2uiv(location, 1, (unsigned int*)&data);
}

void Program::updateUniform(std::string label,  glm::uvec3 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniform3uiv(location, 1, (unsigned int*)&data);
}

void Program::updateUniform(std::string label, glm::uvec4 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniform4uiv(location, 1, (unsigned int*)&data);
}

void Program::updateUniform(std::string label, glm::mat2 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniformMatrix2fv(location, 1, GL_FALSE, (float*)&data);
}

void Program::updateUniform(std::string label, glm::mat3 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniformMatrix3fv(location, 1, GL_FALSE, (float*)&data);
}

void Program::updateUniform(std::string label, glm::mat4 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniformMatrix4fv(location, 1, GL_FALSE, (float*)&data);
}

void Program::updateUniform(std::string label, glm::mat2x3 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniformMatrix2x3fv(location, 1, GL_FALSE, (float*)&data);
}

void Program::updateUniform(std::string label, glm::mat3x2 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniformMatrix3x2fv(location, 1, GL_FALSE, (float*)&data);
}

void Program::updateUniform(std::string label, glm::mat2x4 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniformMatrix2x4fv(location, 1, GL_FALSE, (float*)&data);
}

void Program::updateUniform(std::string label, glm::mat4x2 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniformMatrix4x2fv(location, 1, GL_FALSE, (float*)&data);
}

void Program::updateUniform(std::string label, glm::mat3x4 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniformMatrix3x4fv(location, 1, GL_FALSE, (float*)&data);
}

void Program::updateUniform(std::string label, glm::mat4x3 data){
  glUseProgram(_id);
  GLuint location = glGetUniformLocation(_id, label.c_str());
  glUniformMatrix4x3fv(location, 1, GL_FALSE, (float*)&data);
}
