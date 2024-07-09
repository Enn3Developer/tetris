#ifndef SCORE_H
#define SCORE_H
#include <iostream>
#include <cstring>
using namespace std;

class Score{
protected:
    char name[20];
    char punteggio[10];
    char tempo[10];
    public :
        Score (char[] n, char[] p, char[] t);

    char* toString();

    static void fromString(char[] ss);
};


#endif //SCORE_H
