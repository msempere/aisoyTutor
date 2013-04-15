#include "timer.h"

Timer::Timer()
{

}

Timer::~Timer()
{

}

void Timer::Start()
{
  tinicial = time(0);
}

void Timer::Stop()
{
  tfinal = time(0);
}

int Timer::Diferencia()
{
  return difftime(tfinal, tinicial);
}



int Timer::Restante(int t)
{
  int restante=t-Diferencia();
  
  if(restante<0)
    return 0;
  return restante;

}
