#ifndef TUTORSENTENCEFACTORY_H_
#define TUTORSENTECEFACTORY_H_

#include "tutorSentence.h"
#include <aisoy1/bot.h>
#include <aisoy1/log.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <sqlite3.h>


using namespace std;

class TutorSentenceFactory {
  private:
    
  public:
    static TutorSentence* GetTutorSentence(string);
};

#endif

