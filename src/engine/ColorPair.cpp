#include "ColorPair.h"

#include <ncurses.h>

ColorPair::ColorPair(const short foreground, const short background)
{
    this->foreground = foreground;
    this->background = background;
}

ColorPair::ColorPair(const short foreground): foreground(foreground), background(COLOR_BLACK)
{
}

ColorPair::ColorPair(): foreground(COLOR_WHITE), background(COLOR_BLACK)
{
}

bool ColorPair::operator==(const ColorPair& color_pair) const
{
    return this->foreground == color_pair.foreground && this->background == color_pair.background;
}

