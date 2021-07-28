#pragma once
#include<iostream>
#include<iomanip>
#include <string>
#include <process.h>
#include <windows.h>
#include <fstream>
#include "player.h"

using namespace std;

void score(player);

int compare(int &x,int &y,int &z,int &score);

void win(player);

void tie();

