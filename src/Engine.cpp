//
// Created by komvu on 2024-12-06.
//

#include "Engine.h"
#include "Log.h"
#include <cstdio>
#include <Client.h>

#ifdef ENGINE_H

namespace Winther{

    void print()
    {
        printf("Welcome to the Winther Engine!");
    }
    Engine::Engine() : m_Data(nullptr) {}

    bool Engine::Init() {
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_CAMERA);
        return true;
    }

    void Engine::Quit() {
        SDL_DestroyRenderer(this->m_Renderer);
        SDL_DestroyWindow(this->m_Window);
        SDL_Quit();
        delete this;
    }

    void Engine::EventListener() {
        Log::getCoreLogger()->info("Handling events...");
    }

    void Engine::Read() {
        Log::getCoreLogger()->info("READING...");
    }



    Engine::~Engine()
    {
        delete this;
    };





};






#endif

