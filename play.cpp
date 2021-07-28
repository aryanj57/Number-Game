#include "player.h"
#include "mode.h"

void play()
{
    int choice;

    cout<<"\n\t\t***************************** Difficulty *****************************\n\n";
    cout<<"Choose Diffculty: "<<endl<<endl;
    cout<<"1. Easy (10 questions)"<<endl;
    cout<<"2. Medium (15 questions)"<<endl;
    cout<<"3. Hard (20 questions)"<<endl;

    cin>>choice;

    switch(choice)
    {
        case 1:
            {
                system("cls");
                int que=10;
                ifstream in("easy.txt");
                mode(que,in);
                break;
            }
        case 2:
            {
                system("cls");
                int que=15;
                ifstream in("medium.txt");
                if(!in)
                {
                    cerr<<"Cannot open file"<<endl;
                    exit(1);
                }
                mode(que,in);
                break;
            }
        case 3:
            {
                system("cls");
                int que=20;
                ifstream in("hard.txt");
                if(!in)
                {
                    cerr<<"Cannot open file"<<endl;
                    exit(1);
                }
                mode(que,in);
                break;
            }

    }
}
