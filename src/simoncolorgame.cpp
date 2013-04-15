#include "simoncolorgame.h"

SimonColorGame::SimonColorGame()
{
  SetName("Juego simon con colores");
  bot.say("Vamos a jugar al "+this->GetName());
}


SimonColorGame::~SimonColorGame()
{

}


bool SimonColorGame::EscucharRespuestas(Sequence secuencia_generada)
{
  bot.setGrammar("rojo|verde|amarillo|rosa|blanco|azul");
  AISoy1::Sentence sentence;
  
  for(int i=0;i<secuencia_generada.Size();i++){
    sentence=bot.listen();
    
    cout<<"Escuchado: "<<sentence.sentence()<<" y debe ser "<<secuencia_generada.Get(i)->GetNombre()<<endl;
    
    if(secuencia_generada.Get(i)->GetNombre().compare(sentence.sentence())==0){
      bot.say("si");
      YesWithHead();
    }
    else{
      bot.say("no");
      NoWithHead();
      return false;
    }
    
  }
  return true;
}



void SimonColorGame::Run()
{
  bool fail=false;
  int rondas=1;
  Sequence s;
  
  PutBlack();
  
  while(!fail){
   
    for(int i=0;i<rondas;i++){
      Color *c=new Color();
      c->SetValor(GetRandom(0,6,3)); //colores del 0 al 5 que no sea el 3(blanco)
      s.Add(c);
    }
    
    bot.say("Ronda "+IntToString(rondas));
    
    PutBlack(); 
    s.ReproduceOnlyColors();
    PutBlack(); 
    
    s.Print();
    
    if(EscucharRespuestas(s)){
      bot.say("Bien");
      rondas++;
    }
    else{
      bot.say("Mal");
      fail=true;
    }
    
     s.Clear();
  }
  
  bot.say("Has conseguido hacer "+IntToString(rondas-1)+" rondas");
  
}


