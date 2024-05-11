#include "Drawable.h"

Drawable::Drawable()
{
    this->visible = true;
    this->hover = false;
}

bool Drawable::isVisible() const
{
    return this->visible;
}

void Drawable::setHover(const bool hover)
{
    this->hover = hover;
}

Drawable::~Drawable() = default;

void Drawable::draw(DrawContext* ctx)
{
}
