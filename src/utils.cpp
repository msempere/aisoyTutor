#include <string.h>
#include "utils.h"
#include <stdlib.h>

AISoy1::Bot bot;

void DeleteChar(char str[],char c){
  
  char temp[sizeof str];
  int temp_index = 0;
  
  for (int i = 0; str[i]; ++i) {
      if (str[i] != c) {
         temp[temp_index++] = str[i];
      }
   }
   
   temp[temp_index] = '\0';
   //strcpy_s(str, sizeof(str), temp);
   memcpy(str, temp, sizeof(str));
}




void PutRed(){bot.setColor(true,false,false);}

void PutGreen(){bot.setColor(false,true,false);}

void PutBlue(){bot.setColor(false,false,true);}

void PutWhite(){bot.setColor(true,true,true);}

void PutYellow(){bot.setColor(true,true,false);}

void PutPink(){bot.setColor(true,false,true);}

void PutBlack(){bot.setColor(false,false,false);}


int Chartoint(const char str[]) {

    int i,no=0;
    int len = strlen(str);

    for (i = 0; i < len; i++)
        if (str[i]>='0' && str[i]<='9')
            no=no*10+str[i]-48;
    return no;
}

int Chartoint(char str[]) {

    int i,no=0;
    int len = strlen(str);

    for (i = 0; i < len; i++)
        if (str[i]>='0' && str[i]<='9')
            no=no*10+str[i]-48;
    return no;
}

string IntToString(int i){
  
  string s;
  stringstream out;
  out << i;
  s = out.str();
  return s;
}


int GetRandom(int min, int max) {
  
    int r=min+(rand() % max);
  
    while(r<min || r>max)
      r=min+(rand() % max);
    
    return  r;
}


int GetRandom(int min,int max,int no){
    int n=GetRandom(min,max);
    
    while(n==no)
      n=GetRandom(min,max);
      
    return n;
}

int GetRandom(int min, int max, vector<int> o){
    int r=GetRandom(min,max);
    bool encontrado=true;

    vector<int>::iterator found;
    found=find(o.begin(), o.end(), r);
     
    
    if (found != o.end()) {
        while(encontrado){
	  r=GetRandom(min,max);
	  found=find(o.begin(), o.end(), r);
	  
	  if(found==o.end())
	    encontrado=false;
	  else
	    encontrado=true;
	    
	}
    } else {
        return r;
    }
    return r;
  
}


void NoWithHead(){

  bot.moveServo(AISoy1::HeadHorizontal,0,0.1);
  bot.moveServo(AISoy1::HeadHorizontal,1,0.1);
  bot.moveServo(AISoy1::HeadHorizontal,0.5,0.1);
}

void YesWithHead(){
  
  for(int i=0;i<2;i++){
    bot.moveServo(AISoy1::Eyebrows,0,0.1);
    bot.moveServo(AISoy1::Eyebrows,1,0.1);
  }
  bot.moveServo(AISoy1::Eyebrows,0.8,0.1);
}

