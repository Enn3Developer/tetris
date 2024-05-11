#ifndef RUNCONTEXT_H
#define RUNCONTEXT_H

class Scene;

typedef enum keyboard
{
    NONE,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    CONFIRM,
    ESCAPE,
} Keyboard;

class RunContext
{
private:
    /// L'input attuale da tastiera
    Keyboard input;
    /// Puntatore ad un'eventuale richiesta di cambiamento di scena
    Scene* switchScene;
    /// Richiesta di chiusura da parte dell'engine
    bool exit;
    /// Forza l'engine a usare il `clear()` anziché di `werase(WINDOW*)`
    bool redraw;

public:
    RunContext();
    ~RunContext();
    /// Usato dall'engine per impostare l'input attuale
    void setInput(Keyboard input);
    [[nodiscard]] Keyboard getInput() const;
    void queueScene(Scene* scene);
    void queueExit();
    void forceRedraw();
    /// Usato dall'engine per controllare l'eventuale presenza di cambio di scena
    [[nodiscard]] bool sceneQueued() const;
    /// Usato dall'engine per controllare se è stata richiesta la chiusura dell'applicazione
    [[nodiscard]] bool exitQueued() const;
    /// Usato dall'engine per controllare se deve forzare il `clear()`
    bool redrawForced();
    /// Puntatore alla nuova scena da usare
    [[nodiscard]] Scene* newScene() const;
};

#endif
