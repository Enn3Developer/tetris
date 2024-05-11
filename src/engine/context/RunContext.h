#ifndef RUNCONTEXT_H
#define RUNCONTEXT_H

class Scene;

typedef enum keyboard
{
    NONE,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    CONFIRM,
    ESCAPE,
} Keyboard;

class RunContext
{
private:
    Keyboard input;
    Scene* switchScene;
    bool exit;
    bool redraw;

public:
    RunContext();
    ~RunContext();
    void setInput(Keyboard input);
    [[nodiscard]] Keyboard getInput() const;
    void queueScene(Scene* scene);
    void queueExit();
    void forceRedraw();
    [[nodiscard]] bool sceneQueued() const;
    [[nodiscard]] bool exitQueued() const;
    bool redrawForced();
    [[nodiscard]] Scene* newScene() const;
};

#endif
