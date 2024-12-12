#ifndef TETROMINO_H
#define TETROMINO_H
#include "../Grid.h"

class Tetromino : public GridDrawable {
protected:
    int color = -1;
    ColorPair colorPair;

public:
    explicit Tetromino(ColorPair colorPair);

    void draw(DrawContext *ctx, int x, int y) override;
};

#endif
