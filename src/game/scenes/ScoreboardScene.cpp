#include "ScoreboardScene.h"

string time_to_string(long time) {
    string str_time="";
    string hour, min, second;

    hour=to_string((time/3600/1000)%24);
    min=to_string((time/60/1000)%60);
    second=to_string((time/1000)%60);
    str_time=hour+"h"+min+"m"+second+"s";
    return str_time;
}

ScoreboardScene::ScoreboardScene()
{
    this->title.setText("Score board");
    this->title.setPosition(getCenteredX(&this->title), 2);
    this->title.setColor(ColorPair(COLOR_RED, COLOR_CYAN));
    this->add(&this->title);

    this->score.setText("rank"+"\t"+"name"+"\t"+"points"+"\t"+"time");
    this->score.setPosition(getCenteredX(&this->score), 8);
    this->add(&this->score);

    //inizio stampo
    int rank=1;
    int height=9;
    p_list print= Scoreboard::list;
    while(print!=NULL) {
        string str_time=time_to_string(print->score->tempo);
        string str_rank=to_string(rank);
        string score=str_rank+"\t"+print->score->name+"\t"+print->score->punteggio+"\t"+str_time;
        this->score.setText(score);
        this->score.setPosition(getCenteredX(&this->score), height);
        this->add(&this->score);
        rank=rank+1;
        height=height+1;
    }

    this->exit.setText("Exit");
    this->exit.setPosition(getCenteredX(&this->exit), height+6);
    this->exit.setOnClick(exitButton);
    this->add(&this->exit);
}

ScoreboardScene::~ScoreboardScene() = default;

void exitButton(RunContext* ctx)
{
    ctx->queueExit();
}
