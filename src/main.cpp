#include "engine/Engine.h"
#include "game/scenes/MainScene.h"

int main()
{
    auto engine = Engine(30, 80, 40, 2);
    auto scene = MainScene();
    engine.start(&scene);
    return 0;
}
