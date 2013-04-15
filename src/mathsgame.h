#ifndef MATHSGAME_H_
#define MATHSGAME_H_

#include "utils.h"
#include "game.h"
#include "sequence.h"
#include "simongame.h"

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

class MathsGame : public Game{
  private:
    int GenerateOperandos(int &operando1, int &operando2, int operacion);
    void DecirPregunta(int operando1, int operando2, int operacion);
    int EscucharRespuesta();
  public:
    MathsGame();
    ~MathsGame();
    void Run();   
};

#endif