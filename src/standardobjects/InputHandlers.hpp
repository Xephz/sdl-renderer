#pragma once

#include "../Scene.hpp"
#include "../InputHandler.hpp"

namespace standardobjects{
    class CameraController : public InputHandler{
    public:
        void handleInput(Scene *scene){
            update();
            //translation
            if(isKeyDown(SDL_SCANCODE_S)){
                scene->translateCamera(glm::vec3(0.0f,0.1f,0.0f));
            }
            if(isKeyDown(SDL_SCANCODE_W)){
                scene->translateCamera(glm::vec3(0.0f,-0.1f,0.0f));
            }
            if(isKeyDown(SDL_SCANCODE_A)){
                scene->translateCamera(glm::vec3(0.1f,0.0f,0.0f));
            }
            if(isKeyDown(SDL_SCANCODE_D)){
                scene->translateCamera(glm::vec3(-0.1,0,0));
            }
            if(isKeyDown(SDL_SCANCODE_Q)){
                scene->translateCamera(glm::vec3(0,0,0.1));
            }
            if(isKeyDown(SDL_SCANCODE_E)){
                scene->translateCamera(glm::vec3(0,0,-0.1));
            }
            //rotation
            if(isKeyDown(SDL_SCANCODE_G)){
                scene->rotateCamera(glm::rotate(glm::mat4(1.0f),
                                                0.01f,
                                                glm::vec3(1,0,0)));
            }
            if(isKeyDown(SDL_SCANCODE_T)){
                scene->rotateCamera(glm::rotate(glm::mat4(1.0f),
                                                -0.01f,
                                                glm::vec3(1,0,0)));
            }
            if(isKeyDown(SDL_SCANCODE_H)){
                scene->rotateCamera(glm::rotate(glm::mat4(1.0f),
                                                0.01f,
                                                glm::vec3(0,1,0)));
            }
            if(isKeyDown(SDL_SCANCODE_F)){
                scene->rotateCamera(glm::rotate(glm::mat4(1.0f),
                                                -0.01f,
                                                glm::vec3(0,1,0)));
            }
            if(isKeyDown(SDL_SCANCODE_R)){
                scene->rotateCamera(glm::rotate(glm::mat4(1.0f),
                                                0.01f,
                                                glm::vec3(0,0,1)));
            }
            if(isKeyDown(SDL_SCANCODE_Y)){
                scene->rotateCamera(glm::rotate(glm::mat4(1.0f),
                                                -0.01f,
                                                glm::vec3(0,0,1)));
            }
        }
    };
}
