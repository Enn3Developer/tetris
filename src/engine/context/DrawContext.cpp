#include "DrawContext.h"

DrawContext::DrawContext()
{
    this->win = nullptr;
    this->title = "";
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


void DrawContext::write(const char* txt) const
{
    wprintw(win, txt);
}


void DrawContext::writeAt(const char* txt, const int x, const int y) const
{
    mvwprintw(win, y, x, txt);
}
