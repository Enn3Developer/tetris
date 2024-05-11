#include "MainScene.h"
#include "../../engine/components/Label.h"

MainScene::MainScene()
{
    this->label.setText("Main Scene");
    this->label.setPosition(10, 10);
    this->label.setColor(ColorPair(COLOR_RED));
    this->exit.setText("Exit");
    this->exit.setPosition(10, 15);
    this->exit.setOnClick(exitButton);
    this->add(&this->label);
    this->add(&this->exit);
}

MainScene::~MainScene() = default;

void exitButton(RunContext* ctx)
{
    ctx->queueExit();
}
