#ifndef MAINSCENE_H
#define MAINSCENE_H
#include "../../engine/Scene.h"

class MainScene : public Scene
{
private:
    bool drawn;

public:
    MainScene();
    ~MainScene() override;
    void init(InitContext& ctx) override;
    bool run(RunContext& ctx) override;
    void draw(DrawContext* ctx) override;
};

#endif
