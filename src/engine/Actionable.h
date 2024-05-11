#ifndef ACTIONABLE_H
#define ACTIONABLE_H

class RunContext;

class Actionable
{
public:
    virtual ~Actionable();
    virtual void action(RunContext* ctx);
};

#endif
