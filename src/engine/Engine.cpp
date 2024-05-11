#include "Engine.h"
#include "Scene.h"
#include <ctime>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

Engine::Engine(const int height, const int width, const int startX, const int startY)
{
    initscr();
    noecho();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    curs_set(0);
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
    Keyboard input = NONE;
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
    case '\n':
    case ' ':
        input = CONFIRM;
        break;
    case 27: // ESCAPE or ALT
        if (getch() == ERR)
        {
            input = ESCAPE;
        }
        break;
    default:
        input = NONE;
        break;
    }
    ctx->setInput(input);
}


void Engine::run()
{
    while (true)
    {
        const int64_t start = millis();
        auto ctx = RunContext();
        input(&ctx);
        this->scene->run(&ctx);
        if (ctx.sceneQueued())
        {
            this->scene = ctx.newScene();
            auto initCtx = InitContext();
            this->scene->init(initCtx);
            continue;
        }
        if (ctx.exitQueued())
        {
            break;
        }
        this->draw(ctx.redrawForced());
        if (const int64_t end = millis();
            end - start <= MILLIS_PER_FRAME)
        {
            sleep(MILLIS_PER_FRAME - (end - start));
        }
    }
}

void Engine::draw(const bool redraw)
{
    this->drawContext.prepare(redraw);
    this->scene->draw(&this->drawContext);
    this->drawContext.refresh();
}

void Engine::sleep(unsigned int millis)
{
#ifdef _WIN32
    Sleep(millis);
#else
    usleep(millis * 1000);
#endif
}

int64_t Engine::millis()
{
    timespec now{};
    timespec_get(&now, TIME_UTC);
    return now.tv_sec * 1000 + now.tv_nsec / 1000000;
}
