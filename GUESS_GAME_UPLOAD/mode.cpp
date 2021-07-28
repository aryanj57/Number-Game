#include "player.h"
#include "mode.h"
#include "result.h"

void BEEP()
{
    Beep(400,100000);
}

void timer()
{
    int mins=1,seconds=30;
    while(1)
    {

        if(seconds==0&&mins==0)
        {
            system("cls");
            thread t2(BEEP);
            t2.detach();

            cout<<"\n\t\t\tTime's up :(\n\n";
            cout<<"\t\t\tPress 0 to continue...\n\n"<<endl;
            cout<<"\n\t\t**********************************************************\n\n";
        }

        if(seconds==0&&mins!=0)
        {
            cout<<"\n\nWARNING: Only 1 minute left!\n\n";
            mins--;
            seconds=60;

        }

        Sleep(1000);
        seconds--;

    }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

void time_mode(int que,ifstream &in)
{
    ifstream ans;
    int x,guess_value;
    string str;

    //int seconds=0;
    player p;

    system("cls");

    cout<<"Enter player name: ";p.getname();cout<<endl;

    system("cls");

    cout<<"\n\t\t\tYou have 1:30 seconds\n\n";
    cout<<"\n\t\t\tGo ";p.showname();cout<<" !\n\n"<<endl;


    thread t1(timer);
    t1.detach();

    ans.open("answer.txt");
    if(!ans)
    {
        cerr<<"Cannot open answer file";
        exit(1);
    }

     for(int i=1;i<=que;i++)
     {
        getline(in,str);
        cout<<"Q"<<i<<". "<<str<<endl;
        cout<<"Enter Guess: ";cin>>guess_value;
        ans>>x;

        if(guess_value==0)
            break;

        if(guess_value=='2')
            break;

        //cout<<"Your Guess Difference: "<<guess_value-x<<endl;
        cout<<endl;

        if(abs(guess_value-x)<=10)
            p++;


     }

    cout<<endl<<"Finished !...";
    Sleep(5000);
    win(p);


}


void vs_mode(int que,ifstream &in)
{
    ifstream ans;
    //ifstream money;

    int x,guess_value,m;

    string str;
    system("cls");

                player p1,p2;
                cout<<"Enter player 1 name: ";p1.getname();

                system("cls");

                ans.open("answer.txt");
                //money.open("money_list.txt");

                if(!ans)
                {
                    cerr<<"Cannot open answer file";
                    exit(1);
                }


                cout<<"\n\t\t\tGo ";p1.showname();cout<<" !\n\n"<<endl;

                for(int i=1;i<=que;i++)
                {
                    //money>>m;
                    //cout<<"$"<<m<<endl<<endl;

                    getline(in,str);
                    cout<<"Q"<<i<<". "<<str<<endl;
                    cout<<"Enter Guess: ";cin>>guess_value;
                    ans>>x;

                    //cout<<"Your Guess Difference: "<<guess_value-x<<endl;
                    cout<<endl;

                    if(abs(guess_value-x)<=10)
                        p1++;

                }

                cout<<endl<<"Finished !...";

                in.clear();
                in.seekg(0);
                ans.clear();
                ans.seekg(0);

                Sleep(5000);

                system("cls");

                cout<<"Enter player 2 name: ";p2.getname();

                system("cls");

                cout<<"\n\t\t\tGo ";p2.showname();cout<<" !\n\n"<<endl;

                for(int i=1;i<=que;i++)
                {
                    getline(in,str);
                    cout<<"Q"<<i<<". "<<str<<endl;
                    cout<<"Enter Guess: ";cin>>guess_value;
                    ans>>x;
                    //cout<<"Your Guess Difference: "<<guess_value-x<<endl;
                    cout<<endl;

                    if(abs(guess_value-x)<=10)
                        p2++;
                }

                cout<<endl<<"Finished !...";

                Sleep(5000);
                system("cls");

                //cout<<p1.getscore();cout<<p2.getscore()<<endl;

                if(p1.getscore()>p2.getscore())
                {
                    cout<<"Player 1: ";
                    p1.showname();
                    cout<<" won!"<<endl;
                    Sleep(5000);
                    win(p1);
                }
                else if(p1.getscore()<p2.getscore())
                {
                    cout<<"Player 2: ";
                    p2.showname();
                    cout<<" won!"<<endl;
                    Sleep(5000);
                    win(p2);
                }
                else
                {
                    tie();
                }


}

///////////////////////////////////////////////////////////////////////////////////////////////////////

void mode(int que,ifstream& in)
{
    int choice;
    cout<<"\n\t\t***************************** MODE *****************************\n\n";
    cout<<"Choose mode: "<<endl<<endl;
    cout<<"1. Versus mode (2 Player)"<<endl;
    cout<<"2. Rapid Fire (1 Player)"<<endl;

    cin>>choice;


    switch(choice)
    {
        case 1:
            {
                vs_mode(que,in);
                break;
            }
        case 2:
            {
                time_mode(que,in);
                break;
            }

    }


}
