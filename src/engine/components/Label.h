#ifndef LABEL_H
#define LABEL_H
#include "../Drawable.h"

class Label final : public Drawable
{
private:
    int color;
    ColorPair colorPair;
    const char* txt;

public:
    Label();
    ~Label() override;
    void setText(const char* txt);
    void setColor(ColorPair color);
    void draw(DrawContext* ctx) override;
};

#endif
