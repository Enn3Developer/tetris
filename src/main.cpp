#include "engine/Engine.h"
#include "game/scenes/MainScene.h"

int main()
{
    auto engine = Engine(40, 80, 2, 2);
    auto scene = MainScene();
    engine.setTitle("Menu");
    engine.start(&scene);
    return 0;
}
