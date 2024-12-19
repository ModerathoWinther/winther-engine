//
// Created by komvu on 2024-12-06.
//
#include "Engine.h"
#include <iostream>

#define DEBUG
#ifdef ENGINE_H


namespace Winther
{

	Engine::Engine() :  m_Event(nullptr), m_Window(nullptr), m_Renderer(nullptr), m_Data(nullptr), m_IsRunning(true)
	{
	};

	SDL_Renderer* Engine::GetRenderer()
	{
		return m_Renderer;
	}

	bool Engine::IsRunning()
	{
		return m_IsRunning;
	}


	/*
	* Initializes the game engine...
	*/
	bool Engine::Init()
	{



		Log::Init();

		if (!SDL_Init(SDL_INIT_VIDEO))
		{
			Winther::Log::GetCoreLogger()->info("SDL_Init error...");
			SDL_Log("SDL_Log = SDL_Init error. \n Error: {0}", SDL_GetError());
			return false;
		}
		// Logs result of Init()
		Winther::Log::GetCoreLogger()->info("SDL Initialized correctly.");

		SDL_GPUDevice* gpu = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_DXIL, true, NULL);

		if (!gpu) {
			Log::GetCoreLogger()->info("Failed to initialize GPU device. \n Error: {0}", SDL_GetError());
		}
		else Log::GetCoreLogger()->info("GPU device was successfully initialized.\nGPU device drivers = {0}", SDL_GetGPUDeviceDriver(gpu));


		int w = 1280;
		int h = 720;

		const SDL_DisplayMode* display = SDL_GetDesktopDisplayMode(SDL_GetPrimaryDisplay());
		if (display == nullptr)
		{
			Log::GetCoreLogger()->info(
					"Failed to retrieve primary display resolution. Setting window resolution to 720p. \n Error: {0}",
					SDL_GetError());
		}
		else
		{
			w = display->w;
			h = display->h;
		}


		if (!SDL_CreateWindowAndRenderer("Winther Engine", w, h, 0, &m_Window, &m_Renderer))
		{
			Log::GetCoreLogger()->info("Failed to initialize window and renderer. \n Error: {0}", SDL_GetError());
			return false;
		}

		if(!SDL_ClaimWindowForGPUDevice(gpu, m_Window)){
			Log::GetCoreLogger()->info("Failed to claim window for GPU device. {}", SDL_GetError());
		}

		return m_IsRunning = true;

	}

	// Main game loop.
	void Engine::Run()
	{
		while (m_IsRunning)
		{
			m_EntityManager.Update();
			HandleInputs();
			EventListener();
			SDL_RenderClear(m_Renderer);
			SDL_SetRenderDrawColor(m_Renderer, 0xFF, 0x00, 0x00, 0x10);
			SDL_RenderPresent(m_Renderer);


//            engine.Render();
//            engine.Read();
		}
		SDL_Quit();
		delete this;
	}

	/*
	 *  Quits safely
	 */

	void Engine::Quit()
	{
		m_IsRunning = false;
		m_Data = nullptr;
		SDL_DestroyRenderer(GetRenderer());
		SDL_DestroyWindow(m_Window);
	}

	/*
	 *  Listens to events
	 */

	void Engine::EventListener()
	{
		int counter = 0;
		SDL_Event event;
		if(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT)
			{
				Quit();
			}
			if(event.type == SDL_EVENT_MOUSE_MOTION){
				SDL_SetRenderDrawColorFloat(m_Renderer, event.motion.x/1000, event.motion.y/1000, event.motion.y/1000, event.motion.x/1000);
			}
			if(event.type== SDL_EVENT_MOUSE_BUTTON_DOWN)
				SDL_SetRenderDrawColor(m_Renderer, 00, 00,00,00);
		}
		counter++;
		return;
		if (counter % 100 == 0)
		{
			Log::GetCoreLogger()->info("Handling events...");
		}
	}

	/*
	 *  Reads incoming data...
	 */

	void Engine::Read()
	{
		Log::GetCoreLogger()->info("READING...");
	}

	/*
	 * Renders frames
	 */

	void Engine::Render()
	{
	}


	/*
	 * Client game loop.
	 */



	Engine* Engine::CreateApp()
	{
		return new Client;
	}

	void Engine::HandleInputs()
	{

	}

	void Engine::LoadEntities()
	{
		m_EntityManager->LoadFile(std::string filename);

	}



	Engine::~Engine() = default;


	Client::Client() = default;
};


#endif

