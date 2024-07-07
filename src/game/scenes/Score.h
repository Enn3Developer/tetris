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
        Score (char[] n, char[] p, char[] t){
        name = n;
        punteggio = p;
        tempo = t;
    }

    char toString(){
        char ss[45]="";
		strcat(ss, name);
		strcat(ss, " ");
		strcat(ss, punteggio);
		strcat(ss, " ");
		strcat(ss, tempo);
        return ss;
    }

    void fromString(char[] ss){

    }
};


#endif //SCORE_H
