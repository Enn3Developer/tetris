#include "Scene.h"

Scene::~Scene() = default;

void Scene::draw(DrawContext* ctx)
{
    ctx->writeAt("sus", 10, 10);
}

void Scene::init(InitContext& ctx)
{
}

void Scene::run(RunContext& ctx)
{
}


