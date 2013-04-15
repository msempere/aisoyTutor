#ifndef LED_H_
#define LED_H_

#include "utils.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <aisoy1/bot.h>
#include <aisoy1/log.h>
#include <stdlib.h>

using namespace std;

class Led{
  private:
    int x;
    int y;
    int value;
  public:
    Led();
    Led(int xx,int yy,int v);
    ~Led();
    int GetX();
    int GetY();
    int Value();
    void Set(int xx,int yy,int v);
    void SetValue(int v);
    void SetX(int xx);
    void SetY(int yy);
    void SetRandom();
    bool operator==(Led &);
    Led & operator= (Led& derecha);
    
};

#endif
