#ifndef ENGINE_H
#define ENGINE_H
#include "Scene.h"

class Engine
{
private:
    /// Contesto grafico
    DrawContext drawContext;
    /// Scena attuale
    Scene* scene;

public:
    /// Prepara ncurses e crea la finestra principale
    Engine(int height, int width, int startX, int startY);
    /// Punto d'avvio del gioco
    void start(Scene* scene);
    /// Legge l'input dall'utente e lo salva nel `RunContext`
    void input(RunContext* ctx);
    /// Eseguita in loop costante, richiama `input` e `draw` oltre a gestire il `RunContext`
    void run();
    /// Prepara e chiama la funzione `draw` della scena attualmente in uso
    void draw(bool redraw);
    /// Cambia il titolo della finestra
    void setTitle(const char* title);
    ~Engine();
};

#endif
