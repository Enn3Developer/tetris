#ifndef SCENE_H
#define SCENE_H
#include "Drawable.h"
#include "context/DrawContext.h"
#include "context/InitContext.h"
#include "context/RunContext.h"

class Scene
{
private:
    struct list
    {
        Drawable* drawable;
        list* next;
    };

    typedef list* p_list;
    p_list h_drawables;
    p_list t_drawables;
    int size;

public:
    Scene();
    void add(Drawable* drawable);
    [[nodiscard]] Drawable* get(int idx) const;
    virtual void init(InitContext& ctx);
    virtual void run(RunContext& ctx);
    virtual void draw(DrawContext* ctx);
    virtual ~Scene();
};

#endif
