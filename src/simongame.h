#ifndef SIMONGAME_H_
#define SIMONGAME_H_

#include "utils.h"
#include "game.h"
#include "mouth.h"
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

class SimonGame : public Game{
  private:
    
  public:
    SimonGame();
    ~SimonGame();
    virtual void Run(); 
    bool EscucharRespuestas(Sequence);
};

#endif