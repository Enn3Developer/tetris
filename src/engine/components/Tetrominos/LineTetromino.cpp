#include "LineTetromino.h"

LineTetromino::LineTetromino(): Tetromino(ColorPair(COLOR_WHITE, COLOR_BLUE)) {
    this->shape = new bool[]{true, true, true, true};
    this->width = 1;
    this->height = 4;
}

void LineTetromino::rotate(bool left) {
    this->width = 4;
    this->height = 1;
}
