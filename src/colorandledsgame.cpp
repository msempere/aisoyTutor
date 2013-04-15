#include "colorandledsgame.h"

ColorAndLedsGame::ColorAndLedsGame()
{
  SetName("Juego de preguntas sobre luces y colores");
  bot.say("Vamos a jugar al "+this->GetName());
}

ColorAndLedsGame::~ColorAndLedsGame()
{

}

void ColorAndLedsGame::MostrarPregunta(std::vector< int > colores, std::vector< int > leds)
{
  Color c;
  Mouth m;
  
  for(int i=0;i<colores.size();i++){
    
    Color c;
    c.SetValor(colores.at(i));
    
    cout<<"[ "<<c.GetNombre()<<" - "<<leds.at(i)<<" ] ";
    
    c.SetValor(colores.at(i));
    c.Draw();
    m.TurnOnRandomLeds(0,0,9,6,leds.at(i));
    bot.mouthDraw(m.Get());
    sleep(5);
    PutBlack();
    m.Clear();
    bot.mouthDraw(m.Get());
  }
  cout<<endl;
}

bool ColorAndLedsGame::EscucharRespuestas(std::vector< int > colores, std::vector< int > leds, int maximo, int minimo)
{
  bot.setGrammar("rojo|verde|amarillo|rosa|blanco|azul");
  AISoy1::Sentence sentence;
  Color c2;
  
  //generamos aleatoriamente la pregunta a realizar
  int pregunta=GetRandom(0,2);
  
  //mas puntos iluminados
  if(pregunta==0){
    bot.say("Cual es el color que mas puntos ha iluminado?");
    c2.SetValor(colores.at(maximo));
  }
  //menos puntos iluminados
  else{
    bot.say("Cual es el color que menos puntos ha iluminado?");
    c2.SetValor(colores.at(minimo));
  }
  
  
  sentence=bot.listen();
  Color c1(sentence.sentence());
  
  cout<<"Se escucho: "<<c1.GetNombre()<<" Se esperaba: "<<c2.GetNombre()<<endl;
  
  if(c1==c2){
    bot.say("bien");
    YesWithHead();
    return true;
  }
  bot.say("mal");
  NoWithHead();
  return false;
  
}



void ColorAndLedsGame::Run()
{
  PutBlack();
  
  vector<int> colores;
  vector<int> leds;
  int maximo=-1000;
  int indice_maximo=-1;
  int minimo=1000;
  int indice_minimo=-1;
  int l=-1;
  int tamSecuencia=-1;
  int numRondas=2;
  
  
    for (int i=0;i<numRondas;i++) {

      
      bot.say("Ronda "+IntToString(i+1));
      tamSecuencia=GetRandom(2,6);

        //generamos la pregunta
        for (int i=0;i<tamSecuencia;i++) {
            colores.push_back(GetRandom(0,6,colores));
            l=GetRandom(0,21,l);
            leds.push_back(l);

            if (l<minimo) {
                minimo=l;
                indice_minimo=i;
            }
            else if (l>maximo) {
                maximo=l;
                indice_maximo=i;
            }
        }

        MostrarPregunta(colores,leds);
        EscucharRespuestas(colores,leds,indice_maximo,indice_minimo);



        colores.clear();
        leds.clear();
        PutBlack();
        maximo=-1000;
        minimo=1000;
        indice_maximo=indice_minimo=-1;
    }
}
