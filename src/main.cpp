#include "engine/Engine.h"
#include "game/scenes/MainScene.h"

int main() {
    const auto engine = new Engine(30, 80, 40, 2);
    const auto scene = new MainScene();
    engine->start(scene);
    return 0;
}
