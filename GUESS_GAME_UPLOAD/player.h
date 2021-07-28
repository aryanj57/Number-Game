#pragma once
#include <iostream>
#include <string>
using namespace std;
class player
{
private:
    string name;
    int score;
public:
    player(){name="";score=0;}
    player(string n,int s):name(n),score(s){}
    void getname();
    int getscore();
    void showname();

    player operator ++(int);


};
