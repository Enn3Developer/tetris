#ifndef GRID_H
#define GRID_H
#include "../Drawable.h"

#define FALLING_SPEED 10

class RunContext;
class Tetromino;

class GridDrawable {
protected:
    /// posizione all'interno della griglia partendo dall'angolo basso sinistro
    int x, y;

public:
    GridDrawable();

    void setPosition(int x, int y);

    [[nodiscard]] int *getPosition() const;

    [[nodiscard]] int getX() const;

    [[nodiscard]] int getY() const;

    virtual int width();

    virtual int height();

    /// Il primo elemento si trova nell'angolo in basso a sinistra
    virtual bool *shape();

    virtual void draw(DrawContext *ctx, int x, int y);

    virtual ~GridDrawable();
};

class Grid final : public Drawable {
    struct list {
        GridDrawable *drawable;
        list *next;
        bool fallen;
        int counter_step;
    };

    typedef list *p_list;

protected:
    int grid_width, grid_height;
    /// Per accedere al punto P(x,y) bisogna fare grid[y * grid_width + x]
    bool *grid;
    p_list h_drawables;

    bool collides(GridDrawable *drawable) const;

    void addToGrid(GridDrawable *drawable) const;

public:
    Grid(int width, int height);

    void spawn(GridDrawable *tetromino);

    [[nodiscard]] bool has_fallen() const;

    void tick(RunContext *ctx) const;

    int width() override;

    int height() override;

    void draw(DrawContext *ctx) override;
};

#endif
