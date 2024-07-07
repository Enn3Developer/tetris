#ifndef SCORE_H
#define SCORE_H
#include <iostream>
#include <cstring>
using namespace std;

class Score{
protected:
    string name;
    int punteggio;
    sting tempo;
    public :
        Score (string n, int p, string t){
        name = n;
        punteggio = p;
        tempo = t;
    }

    string toString(){
        string ss;
        ss= name + " " + punteggio + " " + tempo;
        return ss;
    }

    void fromString(string s){
        name= input.find(' ');
        time= input.rfind(' ');
    }
};


#endif //SCORE_H
