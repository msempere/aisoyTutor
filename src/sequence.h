#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include "color.h"
#include "errorColor.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>


using namespace std;


class Sequence{
  private:
    vector<Color*> contenedor;
  public:
    Sequence();
    Sequence(int,int);
    ~Sequence();
    void Add(Color*);
    void Reproduce();
    void ReproduceOnlySounds();
    void ReproduceOnlyColors();
    void Print();
    void Clear();
    Color* Get(int i);
    int Size();
    int GetNumErroneos();
    Sequence GetErroneos();
    int GetNumErrorColorsEqual(Sequence s);
    bool operator==(const Sequence &)const;
    bool CompareErrors(Sequence s);
    Sequence &operator= (Sequence &s);
    void GenerateRandomSequence(int total, int erroneos);
};


#endif