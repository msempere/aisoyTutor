#include "mouth.h"

Mouth::Mouth()
{
  Clear();
}


Mouth::~Mouth()
{
}

const char* Mouth::Get()
{
  return mouth;
}

int Mouth::GetLed(int x,int y)
{ 
  if(mouth[x+(y*KmaxX)]=='*')
    return 1;
  else 
    return 0;
}

int Mouth::GetLed(int x)
{ 
  if(mouth[x]=='*')
    return 1;
  else 
    return 0;
}


void Mouth::Clear()
{
  for(int i=0;i<KmaxMouth;i++)
    mouth[i]=' ';
}

void Mouth::Fill()
{
    for(int i=0;i<KmaxMouth;i++)
      mouth[i]='*';
}


void Mouth::MoveOneLeft()
{ 
  for(int i=0;i<KmaxMouth;i++){
      if(i%KmaxX==KmaxX-1)
	TurnOffLed(i);
      else
	mouth[i]=mouth[i+1];  
  }
}


void Mouth::MoveOneRight()
{
  for(int i=KmaxMouth-1;i>=0;i--){
      if(i%KmaxX==0)
	TurnOffLed(i);
      else
	mouth[i]=mouth[i-1];  
  }
}


void Mouth::MoveOneDown()
{
  for(int i=KmaxMouth;i>=0;i--){
    if(i<60){
      mouth[i+KmaxX]=mouth[i];
      mouth[i]=' ';
    }
  }
}


void Mouth::MoveOneUp()
{
  for(int i=0;i<KmaxMouth;i++){
    if(i>9){
      mouth[i-KmaxX]=mouth[i];
      mouth[i]=' ';
    }
  }
}


Mouth& Mouth::operator=(Mouth& m)
{
  if (this != &m){
    for(int i=0;i<KmaxMouth;i++)
      mouth[i]=m.Get()[i];
  }
  return *this;
}


ostream& operator<<(ostream& output,Mouth& m) {
    
    for(int i=0;i<KmaxMouth;i++){
      
      if(i%KmaxX==0)
	output<<m.Get()[i]<<endl;
      else
	output<<m.Get()[i];
    }
    return output;
}

void Mouth::Square(int x,int y,int t){
  
  for(int i=0;i<t;i++){
    TurnOnLed(x+i,y); 
    TurnOnLed(x,y+i); 
    TurnOnLed(x+(t-1),y+i); 
    TurnOnLed(x+i,y+(t-1)); 
  }
}

void Mouth::Rectangle(int x,int y, int xsize, int ysize){
  
  for(int i=0;i<xsize;i++){
    TurnOnLed(x+i,y);
    TurnOnLed(x+i,y+(ysize-1));
  }
  for(int j=0;j<ysize;j++){
    TurnOnLed(x,y+j);
    TurnOnLed(x+(xsize-1),y+j);
  }
}

void Mouth::Circle(int x, int y, int t)
{
  Square(x,y,t);
  TurnOffLed(x,y);
  TurnOffLed(x+t-1,y);
  TurnOffLed(x,y+t-1);
  TurnOffLed(x+t-1,y+t-1);
}

void Mouth::Wait(int milliseconds)
{
  boost::this_thread::sleep(boost::posix_time::milliseconds(milliseconds)); 
}


void Mouth::MoveLeft(bool* running)
{
  for(int j=0;j<KmaxX;j++){ 
    this->MoveOneLeft();
    bot.mouthDraw(this->Get());
    PerformanceManager::Sleep(300);
    if(!*running) 
      return;
  }
}

void Mouth::MoveRight(bool* running)
{
  for(int j=0;j<KmaxX;j++){ 
    this->MoveOneRight();
    bot.mouthDraw(this->Get());
    PerformanceManager::Sleep(300);
    if(!*running) 
      return;
  }
}

void Mouth::MoveLeft()
{
  for(int j=0;j<KmaxX;j++){ 
    this->MoveOneLeft();
    bot.mouthDraw(this->Get());
    PerformanceManager::Sleep(300);
  }
}

void Mouth::MoveRight()
{
  for(int j=0;j<KmaxX;j++){ 
    this->MoveOneRight();
    bot.mouthDraw(this->Get());
    PerformanceManager::Sleep(300);
  }
}

void Mouth::MoveDown()
{
  for(int j=0;j<KmaxY;j++){ 
    this->MoveOneDown();
    bot.mouthDraw(this->Get());
    PerformanceManager::Sleep(300);
  }
}


void Mouth::MoveUp()
{
  for(int j=0;j<KmaxY;j++){ 
    this->MoveOneUp();
    bot.mouthDraw(this->Get());
    PerformanceManager::Sleep(300);
  }
}


Mouth& Mouth::operator+(Mouth& m)
{
  for(int i=0;i<KmaxMouth;i++){
    if(m.GetLed(i)==1)
      TurnOnLed(i); 
  }
}


void Mouth::CreateBar()
{
  for(int i=0;i<KmaxX;i++)
    TurnOnLed(30+i);
}

void Mouth::TurnOnRandomLeds(int point_1_x, int point_1_y, int point_2_x, int point_2_y, int numLeds)
{
  int xy1=point_1_x+(point_1_y*KmaxX); //2-3 -> 2+(3*10)=32  0-4 0+(4*10)=40
  int xy2=point_2_x+(point_2_y*KmaxX); //4-3 -> 4+(3*10)=34  9-6 9+(6*10)=69
  int led=-1;
  vector<int> ocurrencias;

  for(int i=0;i<numLeds;i++){
    led=GetRandom(xy1,xy2,ocurrencias);
    TurnOnLed(led);
    ocurrencias.push_back(led);
  }
  
}

void Mouth::Mas(int x, int y, int t)
{
  int media=(int)t/2;
  
  for(int i=0;i<t;i++)
    TurnOnLed((x-media)+i,y);
  for(int j=0;j<t;j++)
    TurnOnLed(x,(y-media)+j);
}


void Mouth::Menos(int x, int y, int t)
{
  int media=(int)t/2;
  
  for(int i=0;i<t;i++)
    TurnOnLed((x-media)+i,y);
}

string Mouth::DrawRandomShape(int t)
{
  int random=GetRandom(0,4);
  string dev="";
  
  switch(random){
    case(0):
      Square(2,1,t);
      dev="cuadrado";
      break;
    case(1):
      Circle(2,1,t);
      dev="circulo";
      break;
    case(2):
      Mas(5,3,t);
      dev="mas";
      break;
    case(3):
      Menos(5,3,t);
      dev="menos";
      break;
  }
  return dev;
}

int Mouth::DrawRandomNumber()
{
    int n=GetRandom(1,9);

    switch (n) {
    case(1):
        bot.mouthPrint("1");
        break;
    case(2):
        bot.mouthPrint("2");
        break;
    case(3):
        bot.mouthPrint("3");
        break;
    case(4):
        bot.mouthPrint("4");
        break;
    case(5):
        bot.mouthPrint("5");
        break;
    case(6):
        bot.mouthPrint("6");
        break;
    case(7):
        bot.mouthPrint("7");
        break;
    case(8):
        bot.mouthPrint("8");
        break;
    case(9):
        bot.mouthPrint("9");
        break;
    }
  
    return n;
}


void Mouth::Draw()
{
  bot.mouthDraw(Get());
}

