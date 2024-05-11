#ifndef LABEL_H
#define LABEL_H
#include "../Drawable.h"

class Label : public Drawable
{
private:
    int x, y;
    int color;
    ColorPair colorPair;
    const char* txt;

public:
    explicit Label(const char* txt);
    ~Label() override;
    void setPosition(int x, int y);
    void setColor(ColorPair color);
    void draw(DrawContext* ctx) override;
};

#endif
