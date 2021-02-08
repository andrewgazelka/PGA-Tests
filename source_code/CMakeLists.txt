cmake_minimum_required(VERSION 3.17)
project(proj1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMAKE")

find_package(SDL2 REQUIRED)
Message(STATUS "FINDING SDL2")
IF (${SDL2_FOUND})
    Message(STATUS "SDL2_FOUND: " ${SDL2_FOUND})
    Message(STATUS "SDL2_INCLUDE_DIR:" ${SDL2_INCLUDE_DIR})
    Message(STATUS "SDL2_LIBRARY: " ${SDL2_LIBRARY})
ELSE ()
    Message(STATUS "SDL2_FOUND: " ${SDL2_FOUND})
    Message(FATAL_ERROR "SDL2 NOT FOUND")
ENDIF ()

include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCES
        src/primitives.h
        src/multivector.h
        src/glad/glad.c
        src/glad/glad.h
        src/pga.h
        src/glad/khrplatform.h
        src/squareStarter.cpp
        src/helper.cc
        src/helper.h
        src/config.h
        )


add_executable(proj1 ${SOURCES})

include_directories(proj1 ${SDL2_INCLUDE_DIRS})
target_link_libraries(proj1 ${SDL2_LIBRARIES})