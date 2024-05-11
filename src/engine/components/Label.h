#ifndef LABEL_H
#define LABEL_H
#include "../Drawable.h"

class Label : public Drawable
{
private:
    int color;
    ColorPair colorPair;
    const char* txt;

public:
    explicit Label(const char* txt);
    Label();
    ~Label() override;
    void setText(const char* txt);
    void setColor(ColorPair color);
    void draw(DrawContext* ctx) override;
};

#endif
