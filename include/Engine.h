//
// Created by komvu on 2024-12-06.
//
#pragma once


#ifndef ENGINE_H
#define ENGINE_H
#define WINTHER_API


#include "Log.h"
#include "Client.h"
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL.h>
#include <string>
#include <EntityManager.h>

namespace Winther
{


	class Engine
	{
	public:
		Engine();

		static Engine* CreateApp();

		void Run();

		bool Init();

		bool InitWindowAndRenderer(int& w, int& h);

		bool InitDevice();

		bool InitSDL();

		bool InitDisplay(int& w, int& h);

		void Quit();

		void Render();

		void EventListener();

		void Read();

		inline bool IsRunning();

		inline SDL_Renderer* GetRenderer();


		~Engine();

		void LoadEntities();

	private:
		SDL_DisplayMode* m_DisplayMode;
		SDL_GPUDevice* m_Device;
		SDL_Event* m_Event;
		SDL_Renderer* m_Renderer;
		SDL_Window* m_Window;
		EntityManager m_EntityManager;
		bool m_IsRunning;
		int* m_Data;


		void HandleInputs();
	};

	class Client : public Engine
	{
	public:

		Client();

		~Client() = default;

	private:

	};

} // Winther


#endif //ENGINE_H
