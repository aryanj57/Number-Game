#include "highscore.h";

int compare(int &x,int &y,int &z,int &sc)
{
    if(sc<=x)
    {
        return 0;
    }
    else if(sc>x && sc<=y)
    {
        x=sc;
        return 1;
    }
    else if(sc>y && sc<=z)
    {
        x=y;
        y=sc;
        return 1;
    }
    else
    {
        x=y;
        y=z;
        z=sc;
        return 1;
    }
}
void score(player p)
{

    fstream hs;
    hs.open("highscore.txt");

    if(!hs)
    {
        cerr<<"Cannot open highscore file";
        exit(1);
    }

    string s;
    int sc = p.getscore();
    getline(hs,s);
    int z = stoi(s);
    getline(hs,s);
    int y = stoi(s);
    getline(hs,s);
    int x = stoi(s);
    if(compare(x,y,z,sc))
    {
        cout<<"\nCongrats! You have made a new highscore...\n";
        ofstream tempf("temp.txt");

        if(!tempf)
        {
            cerr<<"Cannot open temp file";
            exit(1);
        }

        tempf<<z<<endl<<y<<endl<<x;
        hs.close();
        tempf.close();
        remove("highscore.txt");
        rename("temp.txt", "highscore.txt");
        hs.open("highscore.txt");
    }
    cout<<"\t\tHighscores:"<<endl;
    cout<<"\t\t"<<z<<"\n\t\t"<<y<<"\n\t\t"<<x<<endl;

    hs.close();

    cout<<endl<<endl<<setw(50)<<"GAME OVER!";
    Sleep(10000);
    exit(1);
}

void win(player x)
{
    system("cls");
    cout<<"\n\t\t\t\tYour score: "<<x.getscore()<<"\n\n";
    cout<<"\n\t\t**********************************************************"<<endl;

    score(x);
}

void tie()
{
    cout<<"\n\t\t***************************** Game Tied !... *****************************\n\n"<<endl;
}
