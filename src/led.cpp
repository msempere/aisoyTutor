#include "led.h"

Led::Led()
{
  Set(-1,-1,-1);
}

Led::Led(int xx,int yy,int v)
{
  SetX(xx);
  SetY(yy);
  value=v;
}

Led::~Led()
{
  value=0;
}

void Led::Set(int xx, int yy, int v)
{
  SetX(xx);
  SetY(yy);
  value=v;
}

void Led::SetValue(int v)
{
  value=v;
}

int Led::Value()
{
  return value;
}



int Led::GetX()
{
  return x;
}

int Led::GetY()
{
  return y;
}


void Led::SetX(int xx)
{
  if(xx<=KmaxX-1)
    x=xx;
}

void Led::SetY(int yy)
{
  if(yy<=KmaxY-1)
    y=yy;
}


void Led::SetRandom()
{
  SetX(GetRandom(0,KmaxX-1));
  SetY(GetRandom(0,KmaxY-1));
  SetValue(1);
}

bool Led::operator==(Led &derecha)
{ 
  if(GetX()==derecha.GetX() && GetY()==derecha.GetY() && Value()==derecha.Value())
    return true;
  return false; 
}

Led& Led::operator=(Led& derecha)
{
  if (this == &derecha) 
    return *this;
  else{
    Set(derecha.GetX(),derecha.GetY(),derecha.Value());
  }
    
}



