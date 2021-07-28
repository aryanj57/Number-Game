#include "player.h"


    void player::getname()
    {
        cin>>name;
    }
    int player::getscore()
    {
        return score;
    }
    void player::showname()
    {
        cout<<name;
    }
    player player::operator ++(int)
    {
        score+=10;
        return player(name,score);
    }


