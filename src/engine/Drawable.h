#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "context/DrawContext.h"

class Drawable
{
private:
    bool visible;

public:
    Drawable();
    [[nodiscard]] bool isVisible() const;
    virtual ~Drawable();
    virtual void draw(DrawContext* ctx);
};

#endif
