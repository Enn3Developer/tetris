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
        src/engine/ColorPair.cpp
        src/engine/components/Button.h
        src/engine/components/Button.cpp
        src/engine/Actionable.h
        src/engine/Actionable.cpp
        src/game/scenes/Game.h
        src/game/scenes/Game.cpp
        src/game/scenes/Score.h
        src/game/scenes/Score.cpp
        src/engine/File.cpp
        src/engine/File.h
        src/engine/components/Tetrominos/Tetromino.h
        src/engine/components/Tetrominos/Tetromino.cpp
        src/engine/components/Grid.cpp
        src/engine/components/Grid.h
        src/engine/components/Tetrominos/SquareTetromino.cpp
        src/engine/components/Tetrominos/SquareTetromino.h
        src/game/scenes/Scoreboard.cpp
        src/game/scenes/Scoreboard.h)
target_link_libraries(Tetris ${CURSES_LIBRARIES})