#ifndef ENGINE_H
#define ENGINE_H
#include "Scene.h"

class Engine
{
private:
    DrawContext drawContext;
    Scene* scene;

public:
    Engine(int height, int width, int startX, int startY);
    void start(Scene* scene);
    void input(RunContext* ctx);
    void run();
    void draw();
    void setTitle(const char* title);
    ~Engine();
};

#endif
