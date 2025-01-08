#include "Score.h"

Score::Score (string n, int p, string t){
    name=n;
    punteggio=p;
    tempo=t;
}

string Score::toString(){
    string ss;
    ss=ss+name+" ";
	string str_punteggio=to_string(punteggio);
	ss=ss+str_punteggio+" ";
	ss=ss+tempo;
    return ss;
}

void Score::fromString(string ss){
	string delimiter=" ";
	name=ss.substr(0, ss.find(delimiter));
	ss.erase(0, ss.find(delimiter) + delimiter.length());

	string str_punteggio=ss.substr(0, ss.find(delimiter));
	punteggio=stoi(str_punteggio);
	ss.erase(0, ss.find(delimiter) + delimiter.length());

	tempo=ss.substr(0, ss.find(delimiter));
}

