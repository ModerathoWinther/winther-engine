//
// Created by komvu on 2024-12-10.
//

#include "Log.h"
#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/ansicolor_sink.h"
#include <string>

namespace Winther {

    Log::Log()= default;

    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;



    void Log::init() {

        spdlog::set_pattern("%^[%T] %n: %v %$");
        s_CoreLogger = spdlog::stdout_color_mt("ENGINE");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("CLIENT");
        s_ClientLogger->set_level(spdlog::level::trace);
    }

    Log::~Log() = default;

}

//
//Winther::Log::Log() {
//
//}
//
//Winther::Log::~Log() {
//    delete this;
//}
//std::shared_ptr<spdlog::logger>& Winther::Log::getCoreLogger(){
//    return s_CoreLogger;
//}
//std::shared_ptr<spdlog::logger>& Winther::Log::getClientLogger()
//{
//    return s_ClientLogger;
//}
//
//void Winther::Log::init()
//{
//    spdlog::set_pattern("%^[%T] %n: %v%$");
//    s_CoreLogger = spdlog::stdout_color_mt("ENGINE");
//    s_CoreLogger->set_level(spdlog::level::trace);
//
//    s_ClientLogger = spdlog::stdout_color_mt("CLIENT");
//    s_ClientLogger ->set_level(spdlog::level::trace);
//}



