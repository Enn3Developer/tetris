#ifndef SCENE_H
#define SCENE_H
#include "Drawable.h"
#include "context/DrawContext.h"
#include "context/InitContext.h"
#include "context/RunContext.h"

class Scene
{
protected:
    /// Lista per gestire tutti gli oggetti `Drawable`, non è circolare
    struct list
    {
        Drawable* drawable;
        list* next;
        list* prev;
    };

    typedef list* p_list;
    /// Testa della lista
    p_list h_drawables;
    /// Coda della lista
    p_list t_drawables;
    /// Numero di elementi nella lista
    int size;
    /// `Drawable` attualmente in focus
    p_list focus;

public:
    Scene();
    /// Registra un oggetto `Drawable`
    void add(Drawable* drawable);
    [[nodiscard]] Drawable* get(int idx) const;
    /// Sposta il focus verso la testa della lista
    void focusUp();
    /// Sposta il focus verso la coda della lista
    void focusDown();
    /// Chiamata una sola volta quando la scena diventa la scena attuale nell'engine
    virtual void init(InitContext& ctx);
    /// Chiamata ad ogni frame per eseguire la logica della scena
    virtual void run(RunContext* ctx);
    /// Chiamata ad ogni frame per disegnare la scena
    virtual void draw(DrawContext* ctx);
    virtual ~Scene();
};

#endif
