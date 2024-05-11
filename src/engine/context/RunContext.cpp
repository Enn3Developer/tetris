#include "RunContext.h"

RunContext::RunContext()
{
    this->input = NONE;
    this->switchScene = nullptr;
    this->exit = false;
}

RunContext::~RunContext() = default;

void RunContext::setInput(const Keyboard input)
{
    this->input = input;
}

Keyboard RunContext::getInput() const
{
    return this->input;
}

void RunContext::queueExit()
{
    this->exit = true;
}

void RunContext::queueScene(Scene* scene)
{
    this->switchScene = scene;
}

bool RunContext::exitQueued() const
{
    return this->exit;
}

bool RunContext::sceneQueued() const
{
    return this->switchScene != nullptr;
}

Scene* RunContext::newScene() const
{
    return this->switchScene;
}
