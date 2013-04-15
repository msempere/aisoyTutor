#include "realsimongame.h"

RealSimonGame::RealSimonGame()
{
  SetName("Juego simon original");
  bot.say("Vamos a jugar al "+this->GetName());
}


RealSimonGame::~RealSimonGame()
{

}


bool RealSimonGame::EscucharRespuestas(Sequence secuencia_colores_generada)
{
  bot.setGrammar("rojo|verde|amarillo|rosa|blanco|azul");
  AISoy1::Sentence sentence;
  
  for(int i=0;i<secuencia_colores_generada.Size();i++){
    sentence=bot.listen();
    
    if(sentence.sentence()!=secuencia_colores_generada.Get(i)->GetNombre())
      return false;
    else
      bot.say("Si");
  }
  return true;
}

bool RealSimonGame::EscucharRespuestas(vector< Color > secuencia)
{
  bot.setGrammar("rojo|verde|amarillo|rosa|blanco|azul");
  AISoy1::Sentence sentence;
  
  for(int i=0;i<secuencia.size();i++){
    PutBlack();
    sentence=bot.listen();
    
    if(sentence.sentence()!=secuencia.at(i).GetNombre())
      return false;
    else
      bot.say("Si");
  }
  return true;
}


void RealSimonGame::Run()
{
    bool fallo=false;
    vector<Color> secuencia;
    
    PutBlack();
    
    while (!fallo) {
      
      Color c;
      c.SetRandom();
      secuencia.push_back(c);
      //secuencia_colores.Add(c);
      //secuencia_colores.Reproduce();
      
      cout<<"-------------"<<endl;
      for(int i=0;i<secuencia.size();i++){
	secuencia.at(i).Draw();
	cout<<secuencia.at(i).GetNombre()<<endl;
	sleep(1);
	PutBlack();
	sleep(1);
      }
      cout<<"-------------"<<endl;
      
      
      
      if(EscucharRespuestas(secuencia)){
	bot.say("Bien");
	PutBlack();
	YesWithHead();
      }
      else{
	fallo=true;
	bot.say("Mal");
	PutBlack();
	NoWithHead();
      }
      
      sleep(1);
      PutBlack();
    }
}
