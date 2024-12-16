//
// Created by komvu on 2024-12-10.
//
#pragma once

#include "Engine.h"
#include <spdlog/logger.h>
#include "spdlog/sinks/stdout_color_sinks.h"


#ifdef ENGINE_H

#ifndef WINTHER_API_LOG_H
#define WINTHER_API_LOG_H







namespace Winther {

    class Log
    {
    public:
        Log();

        static void init();

        inline static std::shared_ptr<spdlog::logger>& getCoreLogger();
        inline static std::shared_ptr<spdlog::logger>& getClientLogger();
        ~Log();

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;

    };
    std::shared_ptr<spdlog::logger> &Log::getCoreLogger() {
        return s_CoreLogger;
    }

    std::shared_ptr<spdlog::logger> &Log::getClientLogger() {
        return s_ClientLogger;
    }



}

#endif //WINTHER_API_LOG_H

#endif //ENGINE_H

