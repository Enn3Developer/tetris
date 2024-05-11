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

void Engine::input(RunContext* ctx)
{
    const auto c = getch();
    Keyboard input;
    switch (c)
    {
    case KEY_UP:
        input = UP;
        break;
    case KEY_DOWN:
        input = DOWN;
        break;
    case KEY_LEFT:
        input = LEFT;
        break;
    case KEY_RIGHT:
        input = RIGHT;
        break;
    case KEY_ENTER:
    case ' ':
        input = CONFIRM;
        break;
    default:
        input = NONE;
    }
    ctx->setInput(input);
}


void Engine::run()
{
    while (true)
    {
        auto ctx = RunContext();
        this->input(&ctx);
        this->scene->run(ctx);
        if (ctx.sceneQueued())
        {
            this->scene = ctx.newScene();
            continue;
        }
        if (ctx.exitQueued())
        {
            break;
        }
        this->draw();
    }
}

void Engine::draw()
{
    this->drawContext.prepare();
    this->scene->draw(&this->drawContext);
    this->drawContext.refresh();
}
