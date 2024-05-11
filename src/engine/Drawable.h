#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "context/DrawContext.h"

class Drawable
{
private:
    bool visible;
    bool hover;

public:
    Drawable();
    [[nodiscard]] bool isVisible() const;
    void setHover(bool hover);
    virtual ~Drawable();
    virtual void draw(DrawContext* ctx);
};

#endif
