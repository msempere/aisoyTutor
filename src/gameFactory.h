#ifndef GAMEFACTORY_H_
#define GAMEFACTORY_H_

#include "game.h"
#include "colorgame.h"
#include "desplazargame.h"
#include "opsBarragame.h"
#include "simoncolorgame.h"
#include "simonshapegame.h"
#include "simonnumbergame.h"
#include "colorandledsgame.h"
#include "realsimongame.h"
#include "mathsgame.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

class GameFactory {
  private:
    
  public:
    static Game* GetGame(string);
};

#endif