#ifndef GAME_H_
#define GAME_H_

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

class Game{
  private:
    string gameName;
  public:
    Game();
    Game(string name);
    ~Game();
    virtual void Run()=0;
    void SetName(string n){gameName=n;}
    string GetName(){return gameName;}
    
  
};

#endif