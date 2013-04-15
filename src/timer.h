#ifndef TIMER_H_
#define TIMER_H_


#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

class Timer{
  private:
    time_t tinicial;
    time_t tfinal;
  public:
    Timer();
    ~Timer();
    int Diferencia();
    int Restante(int);
    void Start();
    void Stop();
};

#endif