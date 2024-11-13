#ifndef SCORE_H
#define SCORE_H
#include <iostream>
#include <cstring>
using namespace std;

class Score{
protected:
    char[20] name;
    int punteggio;
    char[10] tempo;
public :
	Score (char[] n, int p, char[] t);

    char* toString();

    static void fromString(char[] ss);
};


#endif //SCORE_H
