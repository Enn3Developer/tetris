#ifndef GAME_H
#define GAME_H
#include "../../engine/Scene.h"

class Game : public Scene
{
public:
    const char* getTitle() override;
};

#endif
