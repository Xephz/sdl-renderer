#pragma once

#include <glm/glm.hpp>
#include <SDL2/SDL.h>

#define MAX_KEY 282
#define MOUSE_BUTTON_MAX 5

class InputHandler{
  
    
private:
  
  bool _quit;
  bool _keyPressed[MAX_KEY];
  bool _keyReleased[MAX_KEY];
  const uint8_t *_keystate;
//  bool _mousePressed[MOUSE_BUTTON_MAX];
//  bool _mouseReleased[MOUSE_BUTTON_MAX];
//  bool _mouseState[MOUSE_BUTTON_MAX];
  
public:
  
      
  InputHandler();
  
  //update should be called in each frame before reading values
  void update();
  
  //check keyboard events
  bool isKeyDown(int scancode);
  bool wasKeyPressed(int scancode);
  bool wasKeyReleased(int scancode);
  
  //checks mouse events
//  glm::ivec2 mousePos();
 // bool isMouseDown(MouseButton button);
 // bool wasMousePressed(MouseButton button);
 // bool wasMouseReleased(MouseButton button);
  
  bool quit(){return _quit;}
};
