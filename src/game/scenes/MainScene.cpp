#include "MainScene.h"

MainScene::MainScene() = default;

MainScene::~MainScene() = default;

void MainScene::init(InitContext& ctx)
{
}

void MainScene::run(RunContext& ctx)
{
}

void MainScene::draw(DrawContext* ctx)
{
    ctx->writeAt("MainScene", 10, 10);
}

