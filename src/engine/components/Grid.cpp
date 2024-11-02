#include "Grid.h"

Grid::Grid(const int width, const int height) {
    this->grid_width = width;
    this->grid_height = height;
    this->h_drawables = nullptr;
    this->grid = new bool[height * width];
}

void Grid::spawn(GridDrawable *tetromino) {
    tetromino->setPosition(this->grid_width / 2, this->grid_height);
    const auto l = new list{tetromino, this->h_drawables, false, FALLING_SPEED};
    this->h_drawables = l;
}

bool Grid::has_fallen() const {
    if (this->h_drawables != nullptr) {
        return this->h_drawables->fallen;
    }
    return true;
}

void Grid::tick(RunContext *ctx) const {
    if (this->h_drawables != nullptr && !this->h_drawables->fallen) {
        this->h_drawables->counter_step -= 1;
        if (this->h_drawables->counter_step == 0) {
            const int *position = this->h_drawables->drawable->getPosition();
            int x = position[0];
            int y = position[1];
        }
    }
}

int Grid::width() {
    return this->grid_width;
}

int Grid::height() {
    return this->grid_height;
}

void Grid::draw(DrawContext *ctx) {
    p_list l = this->h_drawables;
    while (l != nullptr) {
        l->drawable->draw(ctx);
        l = l->next;
    }
}

GridDrawable::GridDrawable() {
    this->x = this->y = 0;
}

GridDrawable::~GridDrawable() = default;

void GridDrawable::setPosition(const int x, const int y) {
    this->x = x;
    this->y = y;
}

int *GridDrawable::getPosition() const {
    return new int[]{this->x, this->y};
}

int GridDrawable::width() {
    return 1;
}

int GridDrawable::height() {
    return 1;
}

bool *GridDrawable::shape() {
    return new bool{true};
}


void GridDrawable::draw(DrawContext *ctx) {
}
