//
// Created by komvu on 2024-12-06.
//
#ifndef CLIENT_CPP

#define CLIENT_CPP

#include <iostream>
#include "Engine.h"
#include <SDL3/SDL_main.h>
#include <Client.h>



namespace Winther {

    void Engine::Run(Engine engine) {
        engine.Init();

        while (engine.IsRunning()) {
            engine.Read();
            engine.EventListener();
        }

        engine.Quit();
    }



    int main(int argc, char **argv) {
        int running = 1;

        Winther::Log::init();


        int result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
        if (result < 0) {
            Winther::Log::getCoreLogger()->info("SDL_Init error...");
            SDL_Log("SDL_Log = SDL_Init error. %s", SDL_GetError());
        } else Winther::Log::getCoreLogger()->info("SDL Initialized correctly.");


        SDL_Window *window = SDL_CreateWindow("Winther Game Engine", 1920, 1080, SDL_WINDOW_OPENGL);
        SDL_Renderer *renderer = SDL_CreateRenderer(window, "Winther Engine");

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_Delay(1000);


        SDL_RenderPresent(renderer);


        Winther::Log::getClientLogger()->info("Log initialized.");
        Winther::Log::getCoreLogger()->info("Log initialized.");


        auto app = Winther::Engine::CreateApp();
        app->Run(*app);

        delete app;
        SDL_Quit();

        return 0;


    };
}


#endif // CLIENT_CPP

