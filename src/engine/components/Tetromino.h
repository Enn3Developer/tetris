#ifndef TETROMINO_H
#define TETROMINO_H

constexpr int TETROMINO_TYPES = 2;
constexpr int MAX_TETROMINOS = 7;

typedef enum tetromino_type
{
    O,
    I,
    L,
    J,
    S,
    Z,
    T
} TetrominoType;

class Tetromino
{
    struct model
    {
        const char* rappresentation;
        unsigned int grid_size;
        int* paddings;
    };

    struct tetromino_data
    {
        model* models;
        int color;
        char c;
    };

protected:
    static tetromino_data data[MAX_TETROMINOS];

    int color;
    model* p_model;
    model** rotations;
    unsigned int rotations_size;
    unsigned int current_rotation;
    char c;

public:
    static void registerTetromino(const char** rappresentation, unsigned int rappresentation_size,
                                  unsigned int grid_size, char c, short color, TetrominoType type);
};

#endif
