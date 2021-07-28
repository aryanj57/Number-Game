#include "result.h";
#include "highscore.h"


void win(player x)
{
    //system("cls");
    cout<<"You score: "<<x.getscore()<<endl;
    score(x);

    /*
    fstream hs;
    hs.open("highscore.txt");
    string s;
    int score;
    score=x.getscore();
    while(getline(hs,s))
    {
        int v=stoi(s);
        if(v<score)
        {
            cout<<"New Highscore";break;
        }
    }

    */
}

void tie()
{
    cout<<"It was a tie"<<endl;
}
