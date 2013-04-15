#ifndef LEDSGAME_H_
#define LEDSGAME_H_

#include "game.h"
#include "iniFile.h"
#include "timer.h"
#include "led.h"
#include "mouth.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <aisoy1/bot.h>
#include <aisoy1/log.h>
#include <stdlib.h>

using namespace std;

class LedsGame : public Game{
  private:
    vector<Led> mouth;
  public:
    LedsGame();
    ~LedsGame();
    void Run();   
    void GenerateMouth();
    void DrawMouth();
    int EscucharRespuesta();
    int GetLedsON();
};

#endif