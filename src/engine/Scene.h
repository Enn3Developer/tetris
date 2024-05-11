#ifndef SCENE_H
#define SCENE_H
#include "context/DrawContext.h"
#include "context/InitContext.h"
#include "context/RunContext.h"

class Scene
{
public:
    virtual void init(InitContext& ctx);
    virtual bool run(RunContext& ctx);
    virtual void draw(DrawContext* ctx);
    virtual ~Scene();
};

#endif
