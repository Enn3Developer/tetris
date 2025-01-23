#include "Scoreboard.h"

struct split_list {
    string val;
    split_list *next;
};
typedef split_list *p_split_list;

void push(p_split_list p, string val) {
    p_split_list last;
    last=p;
    p_split_list l=NULL;
    while(last!=NULL) {
        l=last;
        last=last->next;
    }
    if(l=NULL) {
        p_split_list list= new p_split_list{val,NULL};
        p=list;
        return;
    }
    p_split_list list= new p_split_list{val,NULL};
    l->next=list;
}

p_split_list split(string s,string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    p_split_list res=NULL;

    while ((pos_end = s.find(delimiter, pos_start))!=string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        push(res, token);
    }
    push(res,s.substr (pos_start));
    return res;
}

string time_to_string(long time) {
    string str_time="";
    string hour, min, second;

    hour=to_string(time/3600/1000)%24;
    min=to_string(time/60/1000)%60;
    second=to_string(time/1000)%60;
    str_time=hour+"hours"+min+"minutes"+second+"seconds";
    return str_time;
}

Scoreboard::Scoreboard() {
    File file= new File("Score.txt");
    string text=file.read_file();
    p_split_list list= split(text, "\n");

    while(list!=NULL) {
        Score score=Score::fromString(text);
        if(this->list==NULL) {
            this->list= new p_list{score, NULL};
        }else {
            p_list l= this->list;
            while(l->next!=NULL) {
                l=l->next;
            }
            l->next=new p_list{score, NULL};
        }
    }

    //inizio sort
    if(this->list==NULL) {
        return;
    };

    p_list before, now, next;
    bool swapped;

    do {
        swapped = false;
        before=this->list;
        if(before->next==NULL) {
            return;
        }
        now = before->next;

        while (before->next->next!=NULL) {
            next = now->next;

            // confronta e ordina
            if (now->score->punteggio < next->score->punteggio ||
                (now->score->punteggio == next->score->punteggio && now->score->tempo > next->score->tempo)) {
                before->next=next;
                now->next=next->next;
                next->next=now;
                swapped = true;
                }
            before = before->next;
        }
    } while (swapped==true);

    //inizio stampo
    p_list print=this->list;
    while(print!=NULL){}
    string str_time=time_to_string(print->score->tempo);
    cout << "Name: " << print->score->name
             << ", Point: " << print->score->punteggio
             << ", Time: " << str_time<< endl;
    print=print->next;
}


