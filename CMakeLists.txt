cmake_minimum_required(VERSION 3.26)
project(SandBox)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

add_executable(SandBox main.cpp
        Element.cpp
        Element.h
        Map.cpp
        Map.h
        Sand.cpp
        Sand.h
        definitions.h
        Water.cpp
        Water.h
        Smoke.cpp
        Smoke.h
        Spawner.cpp
        Spawner.h
        Fire.cpp
        Fire.h
        Stone.cpp
        Stone.h)

target_link_libraries(SandBox sfml-system)
target_link_libraries(SandBox sfml-graphics)
target_link_libraries(SandBox sfml-window)