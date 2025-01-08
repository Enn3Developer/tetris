#ifndef SCORE_H
#define SCORE_H
#include <iostream>
#include <string>

using namespace std;

class Score{
protected:
    string name;
    int punteggio;
    string tempo;
public :
	Score (string n, int p, string t);

    string toString();

    void fromString(string ss);
};


#endif //SCORE_H
