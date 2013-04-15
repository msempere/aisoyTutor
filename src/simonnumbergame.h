#ifndef SIMONNUMBERGAME_H_
#define SIMONNUMBERGAME_H_

#include "utils.h"
#include "game.h"
#include "simongame.h"
#include "sequence.h"

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

class SimonNumberGame : public SimonGame{
  private:
    bool EscucharRespuestas(vector<int>);
  public:
    SimonNumberGame();
    ~SimonNumberGame();
    virtual void Run(); 
};

#endif