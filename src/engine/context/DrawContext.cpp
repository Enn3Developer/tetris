#include "DrawContext.h"

DrawContext::DrawContext()
{
    this->win = nullptr;
    this->title = "";
    this->colors = new ColorPair[MAX_COLORS]{DEFAULT_COLOR_PAIR};
    this->registeredColors = 0;
    this->registerColorPair(DEFAULT_COLOR_PAIR);
}

DrawContext::~DrawContext() = default;

void DrawContext::setWindow(WINDOW* win)
{
    this->win = win;
}

void DrawContext::prepare() const
{
    werase(this->win);
    box(this->win, 0, 0);
    mvwprintw(this->win, 0, 1, this->title);
}


void DrawContext::refresh() const
{
    wrefresh(this->win);
}


void DrawContext::setTitle(const char* title)
{
    this->title = title;
}

int DrawContext::registerColorPair(const ColorPair colorPair)
{
    for (int i = 0; i < this->registeredColors; i++)
    {
        if (this->colors[i] == colorPair)
        {
            return i + 1;
        }
    }
    if (this->registeredColors >= MAX_COLORS)
    {
        printw("REACHED MAXIMUM REGISTERED COLORS");
        refresh();
        exit_curses(1);
    }
    this->colors[this->registeredColors] = colorPair;
    init_pair(this->registeredColors, colorPair.foreground, colorPair.background);
    this->registeredColors += 1;
    return this->registeredColors;
}

void DrawContext::enableColor(const int color)
{
    attron(COLOR_PAIR(color));
}

void DrawContext::disableColor(const int color)
{
    attroff(COLOR_PAIR(color));
}


void DrawContext::write(const char* txt) const
{
    wprintw(win, txt);
}


void DrawContext::writeAt(const char* txt, const int x, const int y) const
{
    mvwprintw(win, y, x, txt);
}
