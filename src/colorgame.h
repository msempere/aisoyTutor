#ifndef COLORGAME_H_
#define COLORGAME_H_

#include <boost/bind.hpp>

#include "game.h"
#include "iniFile.h"
#include "sequence.h"
#include "timer.h"
#include "performanceManager.h"

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

class ColorGame : public Game{
  private:
    void GenerarPregunta();
    void EscucharRespuesta();
    Sequence pregunta;
    Sequence respuesta;
  public:
    ColorGame();
    ~ColorGame();
    void Run();
    
    void Red(bool*);
    void Blue(bool*);
    
  
};

#endif