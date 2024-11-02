#ifndef TETROMINO_H
#define TETROMINO_H
#include "../Grid.h"

class Tetromino : public GridDrawable {
protected:
    int color;

public:
    explicit Tetromino(int color);
};

#endif
