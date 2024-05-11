#include "RunContext.h"

RunContext::RunContext()
{
    this->input = NONE;
}

RunContext::~RunContext() = default;

void RunContext::setInput(const Keyboard input)
{
    this->input = input;
}

Keyboard RunContext::getInput()
{
    return this->input;
}
