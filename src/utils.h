#ifndef UTILS_H_
#define UTILS_H_

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <aisoy1/bot.h>
#include <aisoy1/log.h>
#include <algorithm>


using namespace std;

extern AISoy1::Bot bot;
extern void DeleteChar(char str[],char c);
extern void PutRed();
extern void PutGreen(); 
extern void PutBlue();
extern void PutWhite();
extern void PutYellow();
extern void PutPink();
extern void PutBlack();
extern int Chartoint(const char str[]);
extern int Chartoint(char str[]);
extern string IntToString(int i);
extern  int GetRandom(int min, int max);
extern int GetRandom(int min,int max,int no);
extern int GetRandom(int min, int max, vector<int> o);
extern void NoWithHead();
extern void YesWithHead();

#endif