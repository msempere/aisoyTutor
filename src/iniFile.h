#ifndef INIFILE_H_
#define INIFILE_H_

#include "utils.h"
#include "SimpleIni.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;


class IniFile{
  private:
    string filePath;
    CSimpleIniA iniFile;
  public:
    IniFile();
    IniFile(string);
    ~IniFile();
    int GetIntKeyValue(string, string);
    int GetIntKeyValueFromActualLevel(string);
    int GetLevel();
    void UpdateKeyValue(string, string, string);
    void ResetIntKey(string,string);
    void ResetStringKey(string,string);
    string getFilePath(){return filePath;}
    
};


#endif