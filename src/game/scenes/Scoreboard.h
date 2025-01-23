#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <iostream>
#include "../../engine/File.h"
#include "../../engine/Scene.h"
#include "Score.h"
using namespace std;

class Scoreboard{
protected:
    struct list {
        Score score;
        list *next;
    };
    typedef list *p_list;
    p_list list=NULL;
public :
    Scoreboard();
};

#endif //SCOREBOARD_H
