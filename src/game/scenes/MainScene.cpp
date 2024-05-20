#include "MainScene.h"
#include "../../engine/components/Label.h"

MainScene::MainScene()
{
    this->title.setText("Tetris");
    this->title.setPosition(37, 2);
    this->title.setColor(ColorPair(COLOR_RED, COLOR_CYAN));
    this->newGame.setText("New Game");
    this->newGame.setPosition(36, 8);
    this->newGame.setOnClick(newGameButton);
    this->leaderboard.setText("Leaderboard");
    this->leaderboard.setPosition(35, 11);
    this->exit.setText("Exit");
    this->exit.setPosition(38, 14);
    this->exit.setOnClick(exitButton);
    this->add(&this->title);
    this->add(&this->newGame);
    this->add(&this->leaderboard);
    this->add(&this->exit);
}

MainScene::~MainScene() = default;

const char* MainScene::getTitle()
{
    return "Menu";
}


void exitButton(RunContext* ctx)
{
    ctx->queueExit();
}

void newGameButton(RunContext* ctx)
{
    game = Game();
    ctx->queueScene(&game);
}
