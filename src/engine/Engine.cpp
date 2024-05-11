#include "Engine.h"
#include "Scene.h"

Engine::Engine(const int height, const int width, const int startX, const int startY)
{
    initscr();
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    start_color();
    const auto win = newwin(height, width, startY, startX);
    refresh();
    box(win, 0, 0);
    wrefresh(win);
    this->scene = nullptr;
    this->drawContext = DrawContext();
    this->drawContext.setWindow(win);
}

Engine::~Engine()
{
    endwin();
}

void Engine::setTitle(const char* title)
{
    this->drawContext.setTitle(title);
}

void Engine::start(Scene* scene)
{
    this->scene = scene;
    auto ctx = InitContext();
    this->scene->init(ctx);
    this->run();
}

void Engine::run()
{
    while (true)
    {
        auto ctx = RunContext();
        this->scene->run(ctx);
        this->draw();
    }
}

void Engine::draw()
{
    this->drawContext.prepare();
    this->scene->draw(&this->drawContext);
    this->drawContext.refresh();
}
