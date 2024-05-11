#include "Button.h"

Button::Button()
{
    this->hoverColor = -1;
    this->txt = "";
}

Button::~Button() = default;

void Button::setText(const char* txt)
{
    this->txt = txt;
}

void Button::draw(DrawContext* ctx)
{
    if (this->hoverColor == -1)
    {
        this->hoverColor = ctx->registerColorPair(ColorPair(COLOR_BLACK, COLOR_WHITE));
    }
    if (this->hover)
    {
        ctx->enableColor(this->hoverColor);
    }
    ctx->writeAt(this->txt, this->x, this->y);
    if (this->hover)
    {
        ctx->disableColor(this->hoverColor);
    }
}

