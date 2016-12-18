#include "InputHandler.hpp"

InputHandler::InputHandler():
_keystate(nullptr),
_quit(false){
    update();
}

void InputHandler::update(){

    for(int i; i < MAX_KEY; i++){
        _keyPressed[i] = false;
        _keyReleased[i] = false;
    }

    SDL_Event event;
    
            //TODO Figure out how frequently the SDL_GetKeyboardState
            //actually needs updating
        _keystate = SDL_GetKeyboardState(nullptr);
    while(SDL_PollEvent(&event)){
        
        switch(event.type){
            
            case SDL_KEYUP:
                _keyReleased[event.key.keysym.scancode] = true;
                break;
                
            case SDL_KEYDOWN:
                _keyPressed[event.key.keysym.scancode] = true;
                break;
                
            case SDL_MOUSEBUTTONUP:
                break;
                
            case SDL_MOUSEBUTTONDOWN:
                break;
                
            case SDL_MOUSEMOTION:
                break;
            
            case SDL_QUIT:
                _quit = true;
                break;
                
            default:
                break;
        }
    }
}

bool InputHandler::isKeyDown(int scancode){
    if(_keystate[scancode] == 1){
        return true;
    }
    return false;
}

bool InputHandler::wasKeyPressed(int scancode){
    if(scancode > MAX_KEY || scancode < 0){
        return false;
    }
    return _keyPressed[scancode];
}

bool InputHandler::wasKeyReleased(int scancode){
    if(scancode > MAX_KEY || scancode < 0){
        return false;
    }
    return _keyReleased[scancode];
}
/*
glm::ivec2 InputHandler::mousePos(){
}

bool InputHandler::isMouseDown(MouseButton button){
}

bool InputHandler::wasMousePressed(MouseButton button){
}

bool InputHandler::wasMouseReleased(MouseButton button){
}
*/
