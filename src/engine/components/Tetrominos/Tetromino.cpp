#include "Tetromino.h"

Tetromino::Tetromino(const ColorPair colorPair) {
    this->colorPair = colorPair;
}

void Tetromino::draw(DrawContext *ctx, const int x, const int y) {
    if (this->color == -1) {
        this->color = ctx->registerColorPair(this->colorPair);
    }
    const bool *shape = this->shape();
    ctx->enableColor(this->color);
    for (int selfX = 0; selfX < this->width(); selfX++) {
        for (int selfY = 0; selfY < this->height(); selfY++) {
            const int gridX = selfX + x;
            const int gridY = selfY + y;
            if (shape[gridY * this->width() + gridX]) {
                ctx->writeAt("0", gridX, gridY);
            }
        }
    }
    ctx->disableColor(this->color);
}

