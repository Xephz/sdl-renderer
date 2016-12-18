#include "Window.hpp"

Window::Window()
:_windowId(NULL), _contextId(NULL){

  //init SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    std::cout << "error initialising SDL:" << SDL_GetError() << "\n";
  }
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  _windowId = SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				  800, 450, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  _contextId = SDL_GL_CreateContext(_windowId);

  //init glew
  glewExperimental = GL_TRUE;
  GLenum glewError = glewInit();
  if(glewError != GLEW_OK){
    std::cout << "error initialising glew:" << (int)glewError << "\n";
  }

  //make the vao
  glGenVertexArrays(1, &_vao);
  glBindVertexArray(_vao);
  GLenum GLError = glGetError();
  if(GLError != GL_NO_ERROR){
    //std::cout << "error creating VAO:" << (int)GLError << "\n";
    //TODO: figure out why this gives a bad enum error
  }
  
  //face culling options 
  glEnable(GL_CULL_FACE);
  glCullFace(GL_FRONT);
  glFrontFace(GL_CCW);

  //depth options
  glEnable(GL_DEPTH_TEST);
  glDepthMask(GL_TRUE);
  glDepthFunc(GL_LEQUAL);
  glDepthRange(0, 1);
}

Window::~Window(){

  //deal with the vao
  glBindVertexArray(0);
  glDeleteVertexArrays(1, &_vao);
  GLenum GLError = glGetError();
  if(GLError != GL_NO_ERROR){
    std::cout << "error deleting VAO:" << (int)GLError << "\n";
  }

  //close SDL
  SDL_GL_DeleteContext(_contextId);
  SDL_DestroyWindow(_windowId);
  SDL_Quit();
}
