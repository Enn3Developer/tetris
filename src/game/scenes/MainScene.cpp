#include "MainScene.h"

MainScene::MainScene()
{
    this->drawn = false;
}

MainScene::~MainScene() = default;

void MainScene::init(InitContext& ctx)
{
}

bool MainScene::run(RunContext& ctx)
{
    return !drawn;
}

void MainScene::draw(DrawContext* ctx)
{
    ctx->writeAt("MainScene", 10, 10);
    this->drawn = true;
}

