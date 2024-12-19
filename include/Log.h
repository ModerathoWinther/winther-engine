//
// Created by komvu on 2024-12-10.
//
#pragma once

#include "Engine.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <spdlog/logger.h>


#ifdef ENGINE_H

#ifndef WINTHER_API_LOG_H
#define WINTHER_API_LOG_H

namespace Winther
{

	class Log
	{
	public:
		Log();

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger();

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger();

		~Log();

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

	std::shared_ptr<spdlog::logger>& Log::GetCoreLogger()
	{
		return s_CoreLogger;
	}

	std::shared_ptr<spdlog::logger>& Log::GetClientLogger()
	{
		return s_ClientLogger;
	}


} // Winther

#endif //WINTHER_API_LOG_H

#endif //ENGINE_H

