#ifndef GAME_H
#define GAME_H
#include "../../engine/Scene.h"
#include "../../engine/components/Grid.h"
#include "../../engine/components/Label.h"

class Game final : public Scene {
protected:
    Label *startLabel;
    Grid grid;
    bool started;

public:
    Game();

    ~Game() override;

    void run(RunContext *ctx) override;

    const char *getTitle() override;
};


#include "MainScene.h"
inline MainScene *mainScene;

#endif
