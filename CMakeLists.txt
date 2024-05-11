cmake_minimum_required(VERSION 3.25)
project(Tetris)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(Tetris src/main.cpp
        src/engine/Engine.h
        src/engine/Engine.cpp
        src/engine/Scene.h
        src/engine/Scene.cpp
        src/engine/context/DrawContext.h
        src/engine/context/DrawContext.cpp
        src/engine/context/InitContext.h
        src/engine/context/InitContext.cpp
        src/engine/context/RunContext.h
        src/engine/context/RunContext.cpp
        src/game/scenes/MainScene.h
        src/game/scenes/MainScene.cpp
        src/engine/Drawable.h
        src/engine/Drawable.cpp
        src/engine/components/Label.h
        src/engine/components/Label.cpp
        src/engine/ColorPair.h
        src/engine/ColorPair.cpp)
target_link_libraries(Tetris ${CURSES_LIBRARIES})