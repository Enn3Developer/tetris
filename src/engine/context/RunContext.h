#ifndef RUNCONTEXT_H
#define RUNCONTEXT_H
#include "../Engine.h"

class RunContext
{
private:
    Keyboard input;

public:
    RunContext();
    ~RunContext();
    void setInput(Keyboard input);
    Keyboard getInput();
};

#endif
