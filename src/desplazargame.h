#ifndef DESPLAZARGAME_H_
#define DESPLAZARGAME_H_

#include "utils.h"
#include "game.h"
#include "performanceManager.h"
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

class DesplazarGame : public Game{
  private:
    int EscucharRespuesta();
  public:
    DesplazarGame();
    ~DesplazarGame();
    void Run(); 
};

#endif