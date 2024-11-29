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

bool Grid::collides(GridDrawable *drawable) const {
    const bool *shape = drawable->shape();
    const int startX = drawable->getX();
    // spostiamo la Y di 1 verso il basso per poter trovare tutti i punti in cui
    // la shape tocca i blocchettini gia' presenti nella griglia
    const int startY = drawable->getY() - 1;

    for (int x = 0; x < drawable->width(); x++) {
        for (int y = 0; y < drawable->height(); y++) {
            const int gridX = startX + x;
            const int gridY = startY + y;
            const bool gridValue = this->grid[gridY * this->grid_width + gridX];
            const bool shapeValue = shape[y * drawable->width() + x];
            // se la shape tocca la griglia, il nand tra di loro e' true quindi possiamo ritornare subito true
            if (!(gridValue && shapeValue)) {
                return true;
            }
        }
    }

    return false;
}

void Grid::addToGrid(GridDrawable *drawable) const {
    const bool *shape = drawable->shape();
    const int startX = drawable->getX();
    const int startY = drawable->getY();
    for (int x = 0; x < drawable->width(); x++) {
        for (int y = 0; y < drawable->height(); y++) {
            const int gridX = startX + x;
            const int gridY = startY + y;
            this->grid[gridY * this->grid_width + gridX] = shape[y * drawable->width() + x];
        }
    }
}

void Grid::tick(RunContext *ctx) const {
    if (this->h_drawables != nullptr && !this->h_drawables->fallen) {
        this->h_drawables->counter_step -= 1;
        if (this->h_drawables->counter_step == 0) {
            GridDrawable *drawable = this->h_drawables->drawable;
            if (this->collides(drawable)) {
                this->addToGrid(drawable);
            } else {
                const int *position = drawable->getPosition();
                const int x = position[0];
                const int y = position[1];
                drawable->setPosition(x, y - 1);
                this->h_drawables->fallen = true;
                this->h_drawables->counter_step = FALLING_SPEED;
            }
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

int GridDrawable::getX() const {
    return this->x;
}

int GridDrawable::getY() const {
    return this->y;
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
