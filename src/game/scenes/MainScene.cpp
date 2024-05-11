#include "MainScene.h"
#include "../../engine/components/Label.h"

MainScene::MainScene()
{
    this->title.setText("Tetris");
    this->title.setPosition(37, 2);
    constexpr int x = 35;
    this->title.setColor(ColorPair(COLOR_RED, COLOR_CYAN));
    this->newGame.setText("New Game");
    this->newGame.setPosition(x, 8);
    this->leaderboard.setText("Leaderboard");
    this->leaderboard.setPosition(x, 11);
    this->exit.setText("Exit");
    this->exit.setPosition(x, 14);
    this->exit.setOnClick(exitButton);
    this->add(&this->title);
    this->add(&this->newGame);
    this->add(&this->leaderboard);
    this->add(&this->exit);
}

MainScene::~MainScene() = default;

void exitButton(RunContext* ctx)
{
    ctx->queueExit();
}
