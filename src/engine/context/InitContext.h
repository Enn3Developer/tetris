#ifndef INITCONTEXT_H
#define INITCONTEXT_H

class InitContext
{
private:
    /// Posizione della finestra rispetto al terminale
    int startX, startY;

public:
    InitContext();
    ~InitContext();
    /// Usato dall'engine per impostare la posizione della finestra rispetto al terminale
    void setStart(int x, int y);
    int* getStart() const;
};

#endif
