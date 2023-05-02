cmake_minimum_required(VERSION 3.0)

project(Game)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES
    main.cpp
    Source/Display.h
    Source/Display.cpp
    Source/Scene.h
    Source/Scene.cpp
    Source/Geometry.h
    Source/Geometry.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
