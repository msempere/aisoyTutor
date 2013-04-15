#ifndef TUTORSENTENCE_H_
#define TUTORSENTENCE_H_

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <sqlite3.h>


#include "utils.h"
#include "tipoSentence.h"

using namespace std;



class TutorSentence {
  
  private:
    sqlite3 *database;
    string tabla;
    string idioma;
    string sentencia;
    static const string Kparam;
    static const string database_path;
    sqlite3_stmt *stmt;
    //void Select_stmt();
    //int Select_callback(void *, int, char **, char **);
    void Replace(string reemplazada, string reemplazador);
    string TipoSentenceToString(int);
    
  public:
    TutorSentence();
    TutorSentence(const string&, int);
    TutorSentence& Fill(string);
    string GetSentenceFromDB(int);
    string GetSentence(){return sentencia;};
    int GetNumParameters();
    void SetTabla(string t){tabla=t;};
    void SetIdioma(string i){idioma=i;};
    string ToString(){return sentencia;};
    void Say();
    
};

#endif