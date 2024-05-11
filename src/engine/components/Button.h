#ifndef BUTTON_H
#define BUTTON_H
#include "../Drawable.h"

class Button final : public Drawable
{
private:
    int hoverColor;
    const char* txt;

public:
    Button();
    ~Button() override;
    void setText(const char* txt);
    void draw(DrawContext* ctx) override;
};

#endif
