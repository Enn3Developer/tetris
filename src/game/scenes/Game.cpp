#include "Game.h"

Game::Game(): grid(10, 20) {
    this->started = false;
    this->startLabel = new Label();
    this->startLabel->setText("Press CONFIRM key to start");
    this->startLabel->setPosition(getCenteredX(this->startLabel), 2);
    this->startLabel->setColor(ColorPair(COLOR_WHITE, COLOR_CYAN));
    this->add(this->startLabel);
    this->add(&this->grid);
}

Game::~Game() = default;

const char *Game::getTitle() {
    return "Tetris";
}

void Game::run(RunContext *ctx) {
    if (ctx->getInput() == ESCAPE) {
        mainScene = new MainScene();
        ctx->queueScene(mainScene);
        return;
    }
}
