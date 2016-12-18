#pragma once

#include <iostream>

#include <GL/glew.h>
#include <SDL2/SDL.h>

class Window{
  
private:
  
  SDL_Window *_windowId;
  SDL_GLContext _contextId;
  GLuint _vao;
    
public: 
  
  Window();
  ~Window();
  void swapBuffers(){SDL_GL_SwapWindow(_windowId);}    
};