#include "iniFile.h"

IniFile::IniFile()
{
  filePath="./data/minigames.ini";
  iniFile.SetUnicode();
  iniFile.LoadFile(filePath.c_str());
}


IniFile::IniFile(string f)
{
  filePath=f;
  iniFile.SetUnicode();
  iniFile.LoadFile(f.c_str());
}


IniFile::~IniFile()
{
  filePath="";
}



int IniFile::GetIntKeyValue(string section, string key){
  return Chartoint(iniFile.GetValue(section.c_str(), key.c_str(), NULL));
}

int IniFile::GetIntKeyValueFromActualLevel(string key)
{
  string actualLevel=IntToString(GetLevel());
  string section="Level"+actualLevel;
  return GetIntKeyValue(section,key);
}


void IniFile::UpdateKeyValue(string section, string key, string value){ 
  
  const char* s=section.c_str();
  const char* k=key.c_str();
  const char* v=value.c_str();
  
  iniFile.SetValue(s,k,v,NULL,true);
  iniFile.SaveFile(getFilePath().c_str());
}


void IniFile::ResetIntKey(string section, string key){
  UpdateKeyValue(section,key,"0");
}


void IniFile::ResetStringKey(string section, string key){
  UpdateKeyValue(section,key,"NULL");
}



int IniFile::GetLevel()
{
  return GetIntKeyValue("UserStadistics","nivelActual");
}

