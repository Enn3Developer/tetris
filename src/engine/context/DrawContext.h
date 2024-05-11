#ifndef DRAWCONTEXT_H
#define DRAWCONTEXT_H
#include <ncurses.h>

#include "../ColorPair.h"

constexpr int MAX_COLORS = 32;
const auto DEFAULT_COLOR_PAIR = ColorPair(COLOR_WHITE);

class DrawContext
{
private:
    WINDOW* win;
    const char* title;
    ColorPair* colors;
    short registeredColors;

public:
    DrawContext();
    ~DrawContext();
    void setWindow(WINDOW* win);
    void refresh() const;
    void prepare() const;
    void setTitle(const char* title);
    int registerColorPair(ColorPair colorPair);
    void enableColor(int color);
    void disableColor(int color);
    void write(const char* txt) const;
    void writeAt(const char* txt, int x, int y) const;
};

#endif
