#include "Scene.h"

Scene::Scene()
{
    this->h_drawables = nullptr;
    this->t_drawables = nullptr;
    this->size = 0;
}

void Scene::add(Drawable* drawable)
{
    const auto l = new list{drawable, nullptr};
    if (this->h_drawables == nullptr)
    {
        this->h_drawables = l;
        this->t_drawables = l;
    }
    else
    {
        this->t_drawables->next = l;
        this->t_drawables = l;
    }
    this->size++;
}

Drawable* Scene::get(int idx) const
{
    p_list l = this->h_drawables;
    while (idx > 0 && l != nullptr)
    {
        l = l->next;
        idx--;
    }
    if (l == nullptr) return nullptr;
    return l->drawable;
}

Scene::~Scene() = default;

void Scene::draw(DrawContext* ctx)
{
    p_list l = this->h_drawables;
    while (l != nullptr)
    {
        if (l->drawable->isVisible())
        {
            l->drawable->draw(ctx);
        }
        l = l->next;
    }
}

void Scene::init(InitContext& ctx)
{
}

void Scene::run(RunContext& ctx)
{
}


