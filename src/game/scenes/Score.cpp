#include "Score.h"

Score::Score (string n, int p, long t){
    name=n;
    punteggio=p;
    tempo=t;
}

string Score::toString(){
    string ss;
    ss=ss+name+" ";
	string str_punteggio=to_string(punteggio);
	ss=ss+str_punteggio+" ";
	string str_tempo=to_string(tempo);
	ss=ss+str_tempo;
    return ss;
}

Score Score::fromString(string ss){
	string delimiter=" ";
	string name=ss.substr(0, ss.find(delimiter));
	ss.erase(0, ss.find(delimiter) + delimiter.length());

	string str_punteggio=ss.substr(0, ss.find(delimiter));
	int punteggio=stoi(str_punteggio);
	ss.erase(0, ss.find(delimiter) + delimiter.length());

	string str_tempo=ss.substr(0, ss.find(delimiter));
	long tempo=stol(str_tempo);
	return new Score(name, punteggio,tempo);
}

