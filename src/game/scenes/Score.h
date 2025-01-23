#ifndef SCORE_H
#define SCORE_H
#include <iostream>
#include <string>

using namespace std;

class Score{
protected:
    string name;
    int punteggio;
    long tempo;
public :
	Score (string n, int p, long t);

    string toString();

    static Score fromString(string ss);
};


#endif //SCORE_H
