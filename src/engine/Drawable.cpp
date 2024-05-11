#include "Drawable.h"

Drawable::Drawable()
{
    this->visible = true;
}

bool Drawable::isVisible() const
{
    return this->visible;
}

Drawable::~Drawable() = default;

void Drawable::draw(DrawContext* ctx)
{
}
