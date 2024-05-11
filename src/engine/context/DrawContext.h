#ifndef DRAWCONTEXT_H
#define DRAWCONTEXT_H
#include <ncurses.h>

class DrawContext
{
private:
    WINDOW* win;
    const char* title;

public:
    DrawContext();
    ~DrawContext();
    void setWindow(WINDOW* win);
    void refresh() const;
    void prepare() const;
    void setTitle(const char* title);
    void write(const char* txt) const;
    void writeAt(const char* txt, int x, int y) const;
};

#endif
