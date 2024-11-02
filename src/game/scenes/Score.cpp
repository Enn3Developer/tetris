#include "Score.h"

Score::Score (char[] n, char[] p, char[] t){
    strcpy(name,n);
    strcpy(punteggio, p);
    strcpy(tempo, t);
}

char* Score::toString(){
    char ss[45]="";
    strcat(ss, name);
	strcat(ss, " ");
	strcat(ss, punteggio);
	strcat(ss, " ");
    strcat(ss, tempo);
    return ss;
}

static void Score::fromString(char[] ss){
    char* p;
    p=strtok (ss," ");
    strcpy(name, p);
    p=strtok (NULL," ");
    strcpy(punteggio, p);
    p=strtok (NULL," ");
    strcpy(tempo, p);
}

