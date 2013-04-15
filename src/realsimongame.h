#ifndef REALSIMONGAME_H_
#define REALSIMONGAME_H_

#include "utils.h"
#include "game.h"
#include "simongame.h"
#include "color.h"
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

class RealSimonGame : public SimonGame{
  private:
    Sequence secuencia_colores;
    bool EscucharRespuestas(Sequence secuencia_colores_generada);
    bool EscucharRespuestas(vector<Color>);
  public:
    RealSimonGame();
    ~RealSimonGame();
    virtual void Run(); 
};

#endif