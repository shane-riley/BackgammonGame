cmake_minimum_required(VERSION 3.16)

project(BackgammonGame
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

option(BACKGAMMON_BUILD_TESTS "Build unit tests" ON)

if(MSVC)
    set(BACKGAMMON_WARNINGS /W4 /permissive-)
else()
    set(BACKGAMMON_WARNINGS -Wall -Wextra -Wpedantic -Wshadow -Wconversion)
endif()

# Game sources, excluding main.cpp so the tests can compile them too
set(BACKGAMMON_SOURCES
    src/board.cpp
    src/game.cpp
    src/notation.cpp
    src/render.cpp
    src/rules.cpp
    src/version.cpp
)

add_executable(backgammon src/main.cpp ${BACKGAMMON_SOURCES})
target_include_directories(backgammon PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(backgammon PRIVATE ${BACKGAMMON_WARNINGS})

if(BACKGAMMON_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
