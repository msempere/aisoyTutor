#ifndef COLOR_H_
#define COLOR_H_

#include "utils.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>


using namespace std;



class Color{
  
  private:
    string nombre;
    int valor;
    bool erroneo;
  
  public:
    Color();
    Color(int v);
    Color(string n);
    ~Color();
    string GetNombre(){return nombre;}
    int GetValor(){return valor;}
    void SetNombre(string n){nombre=n;}
    void SetValor(int);
    void SetRandom();
    void Draw();
    void Say();
    Color& operator=(Color& c);
    bool Erroneo();
    void SetErroneo(bool e){erroneo=e;}
    void SetErroneo(){erroneo=true;}
    bool operator==(Color &);
};

#endif