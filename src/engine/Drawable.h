#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "context/DrawContext.h"

class Drawable
{
private:
    bool visible;
    bool hover;
    int x, y;

public:
    Drawable();
    [[nodiscard]] bool isVisible() const;
    void setHover(bool hover);
    void setPosition(int x, int y);
    virtual ~Drawable();
    virtual void draw(DrawContext* ctx);
};

#endif
