#include "MainScene.h"
#include "../../engine/components/Label.h"

MainScene::MainScene()
{
    this->label.setText("Main Scene");
    this->label.setPosition(10, 10);
    this->add(&this->label);
}

MainScene::~MainScene() = default;
