cmake_minimum_required(VERSION 3.28)
project(winther_engine)

set(CMAKE_CXX_STANDARD 17)

# CMake module path
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

# Output directories
set(BASE_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BASE_OUTPUT_DIR}/static")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${BASE_OUTPUT_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BASE_OUTPUT_DIR}")

# Library paths

set(SDL3_DIR "C:/SDL3-3.1.3/x86_64-w64-mingw32/lib/cmake/SDL3")
set(spdlog_DIR "C:/spdlog-1.x/build1")

if(NOT TARGET SDL3)
    find_package(SDL3)

endif()
if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()




add_executable(WINTHER_SRC
        src/Client.cpp
        src/Engine.cpp include/Engine.h
        src/Log.cpp include/Log.h
        include/Core.h
        include/Winther.h
        include/Entrypoint.h
        include/Client.h
)

target_include_directories(WINTHER_SRC PUBLIC
        include)


add_library(WINTHER_LIB SHARED
        src/Client.cpp
        src/Engine.cpp include/Engine.h
        src/Log.cpp include/Log.h
        include/Core.h
        include/Winther.h
        include/Entrypoint.h
        ${WINTHER_SRC}
        include/Client.h)

target_include_directories(WINTHER_LIB PUBLIC
        include)

target_link_libraries(WINTHER_SRC
        SDL3::SDL3
        spdlog::spdlog)

target_link_libraries(WINTHER_LIB
        SDL3::SDL3
        ${SDL3_LIBRARIES}
        spdlog::spdlog)




set(CMAKE_EXE_LINKER_FLAGS "-Wl,-subsystem,console")

# Additional flags to ensure correct entry point
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mconsole")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -e mainCRTStartup")
