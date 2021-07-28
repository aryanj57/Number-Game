#include "menu.h"

void info()
{
  system("cls");
  ifstream in;
  in.open("guide.txt");
  string s;
    while(getline(in,s))
    {
         cout<<s<<endl;
    }
    Sleep(30000);
    system("cls");
    menu();
}

void menu()
{

    int choice;

    system("title GUESS GAME");
    system("Color B0");

    cout<<"\n\t\t***************************** MAIN MENU *****************************\n\n";
    cout<<"1. Play"<<endl;
    cout<<"2. How to Play"<<endl;
    cout<<"3. Exit"<<endl;

    cin>>choice;

    switch(choice)
    {
    case 1:
        {
            system("cls");
            play();
            break;
        }

    case 2:
        {
            info();
            break;
        }

    case 3:
        {
            system("cls");
            cout<<endl<<endl<<setw(50)<<"GAME OVER!";
            while(1)
            {
               system("Color CA");
               system("Color AC");
               system("Color BE");
               system("Color DB");
               system("Color EF");
            }

            Sleep(10000);
            exit(1);
            break;
        }

    }
}

