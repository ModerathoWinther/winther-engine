//
// Created by komvu on 2024-12-06.
//
#pragma once


#ifndef ENGINE_H
#define ENGINE_H
#define WINTHER_API





#include "Log.h"
#include "Client.h"
#include <SDL3/SDL.h>

namespace Winther{


    class Engine{
    public:
        Engine();

        static Engine* CreateApp();

        void Run(Engine engine);

        bool Init();
        void Quit();

        void Render();
        void EventListener();
        void Read();


        inline bool IsRunning(){
            return m_IsRunning;
        }

        inline SDL_Renderer* GetRenderer() {return m_Renderer;}

        ~Engine();
    private:
        SDL_Renderer* m_Renderer;
        SDL_Window* m_Window;
        bool m_IsRunning;
        int* m_Data;
    };

    class Client : public Engine
    {
    public:

        Client() = default;

        ~Client() = default;

    private:

    };

    Engine *Engine::CreateApp()  {
        return new Client;
    }






}

#endif //ENGINE_H
