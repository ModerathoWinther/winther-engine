//
// Created by komvu on 2024-12-06.
//
#ifndef CLIENT_CPP

#define CLIENT_CPP

#include <iostream>
#include "Engine.h"


namespace Winther
{

#include <SDL3/SDL_main.h>

	int main(int argc, char** argv)
	{

		auto client = Winther::Engine::CreateApp();
		if (client->Init())
		{
			client->LoadEntities();
			client->Run();
		}
		else return -3;

		return 0;

	};
}


#endif // CLIENT_CPP

