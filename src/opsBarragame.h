#ifndef OPSBARRAGAME_H_
#define OPSBARRAGAME_H_

#include "utils.h"
#include "game.h"
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

class OpsBarraGame : public Game{
  private:
    int EscucharRespuesta();
  public:
    OpsBarraGame();
    ~OpsBarraGame();
    void Run(); 
};

#endif