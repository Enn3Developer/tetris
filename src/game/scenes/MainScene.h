#ifndef MAINSCENE_H
#define MAINSCENE_H
#include "../../engine/Scene.h"
#include "../../engine/components/Button.h"
#include "../../engine/components/Label.h"

class MainScene final : public Scene
{
    Label title;
    Button newGame;
    Button leaderboard;
    Button exit;

public:
    MainScene();
    ~MainScene() override;
    const char* getTitle() override;
};

void exitButton(RunContext* ctx);

#endif
