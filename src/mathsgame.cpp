#include "mathsgame.h"

MathsGame::MathsGame()
{
  SetName("Juego de operaciones matematicas");
  bot.say("Vamos a jugar al "+this->GetName());
}

MathsGame::~MathsGame()
{

}

int MathsGame::GenerateOperandos(int& operando1, int& operando2, int operacion)
{
  int dev=0;
  
    if (operacion==0) {
        operando1=GetRandom(0,10);
        operando2=GetRandom(0,10);
	dev=operando1+operando2;
	
    } else if (operacion==1) {
        int aux=-1;
        operando1=GetRandom(0,10);
        operando2=GetRandom(0,10);

        if (operando2>operando1) {
            aux=operando1;
            operando1=operando2;
            operando2=aux;
        }
        dev=operando1-operando2;
        
    } else if (operacion==2) {

        operando1=GetRandom(0,10);
        operando2=GetRandom(0,10);
	
	dev=operando1*operando2;
	
    } else if (operacion==3) {
        operando1=GetRandom(0,10);
        operando2=GetRandom(0,10);

        while (operando1<operando2 || operando1%operando2!=0 || operando2==0 || operando1==0) {
            operando1=GetRandom(1,10);
            operando2=GetRandom(1,10);
        }
        
        dev=operando1/operando2;
    }

  return dev;
}

void MathsGame::DecirPregunta(int operando1, int operando2, int operacion)
{
  string op=IntToString(operando1);
  if(operacion==0)
    op+=" mas ";
  else if(operacion==1)
    op+=" menos ";
  else if(operacion==2)
    op+=" por ";
  else if(operacion==3)
    op+=" entre ";
  
  op+=IntToString(operando2);
  bot.say(op);
}

int MathsGame::EscucharRespuesta()
{
    bot.setGrammarFile("./numbers.bnf");
    AISoy1::Sentence sentence;

    sentence=bot.listen();

    char *tmp=strdupa(sentence.sentence().c_str());
    DeleteChar(tmp,'D');

    return Chartoint(tmp);
}


void MathsGame::Run()
{
  int numRondas=3;
  int operacion=-1;
  int operando1=-1;
  int operando2=-1;
  int solucion=-1;
  
  for(int i=0;i<numRondas;i++){
    
    bot.say("Ronda "+IntToString(i+1));
    
    operacion=GetRandom(0,4);
    solucion=GenerateOperandos(operando1,operando2,operacion);
    DecirPregunta(operando1,operando2,operacion);
    
    if(EscucharRespuesta()==solucion){
      bot.say("Bien!");
      YesWithHead();
    }
    else{
      bot.say("Mal");
      NoWithHead();
    }
  }
  
}
