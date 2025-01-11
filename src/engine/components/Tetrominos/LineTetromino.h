#ifndef LINETETROMINO_H
#define LINETETROMINO_H
#include "Tetromino.h"

class LineTetromino final : Tetromino {
public:
    LineTetromino();

    void rotate(bool left) override;
};

#endif
