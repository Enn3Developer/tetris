#include "SquareTetromino.h"

SquareTetromino::SquareTetromino(): Tetromino(ColorPair(COLOR_WHITE, COLOR_YELLOW)) {
    this->shape = new bool[]{true, true, true, true};
    this->width = 2;
    this->height = 2;
}
