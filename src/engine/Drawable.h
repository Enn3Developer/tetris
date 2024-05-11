#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "context/DrawContext.h"

class Drawable
{
protected:
    /// Visibilità
    bool visible;
    /// Vero se l'elemento è in focus
    bool hover;
    /// Posizione
    int x, y;

public:
    Drawable();
    [[nodiscard]] bool isVisible() const;
    void setHover(bool hover);
    void setPosition(int x, int y);
    virtual ~Drawable();
    /// Chiamato per disegnare il singolo elemento
    virtual void draw(DrawContext* ctx);
};

#endif
