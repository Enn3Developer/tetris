#include "Label.h"

Label::Label(const char* txt)
{
    this->txt = txt;
    this->x = this->y = 0;
    this->color = 1;
    this->colorPair = DEFAULT_COLOR_PAIR;
}

Label::~Label() = default;

void Label::setPosition(const int x, const int y)
{
    this->x = x;
    this->y = y;
}


void Label::setColor(ColorPair color)
{
    this->colorPair = color;
    this->color = -1;
}

void Label::draw(DrawContext* ctx)
{
    if (this->color == -1)
    {
        this->color = ctx->registerColorPair(this->colorPair);
    }
    ctx->enableColor(this->color);
    ctx->writeAt(this->txt, x, y);
    ctx->disableColor(this->color);
}

