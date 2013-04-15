#ifndef SIMONSHAPEGAME_H_
#define SIMONSHAPEGAME_H_

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

class SimonShapeGame : public SimonGame{
  private:
    bool EscucharRespuestas(vector<string>);
  public:
    SimonShapeGame();
    ~SimonShapeGame();
    virtual void Run(); 
};

#endif