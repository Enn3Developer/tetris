#ifndef BUTTON_H
#define BUTTON_H
#include "../Actionable.h"
#include "../Drawable.h"

class Button final : public Drawable, public Actionable
{
private:
    int hoverColor;
    const char* txt;
    void (*click)(RunContext* ctx);

public:
    Button();
    ~Button() override;
    void setText(const char* txt);
    void setOnClick(void (*click)(RunContext* ctx));
    void draw(DrawContext* ctx) override;
    void action(RunContext* ctx) override;
};

#endif
