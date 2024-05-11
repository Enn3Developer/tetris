#ifndef MAINSCENE_H
#define MAINSCENE_H
#include "../../engine/Scene.h"

class MainScene : public Scene
{
public:
    MainScene();
    ~MainScene() override;
    void init(InitContext& ctx) override;
    void run(RunContext& ctx) override;
    void draw(DrawContext* ctx) override;
};

#endif
