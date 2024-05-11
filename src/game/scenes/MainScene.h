#ifndef MAINSCENE_H
#define MAINSCENE_H
#include "../../engine/Scene.h"
#include "../../engine/components/Label.h"

class MainScene final : public Scene
{
    Label label;

public:
    MainScene();
    ~MainScene() override;
};

#endif
