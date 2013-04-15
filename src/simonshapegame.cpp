#include "simonshapegame.h"

SimonShapeGame::SimonShapeGame()
{
  SetName("Juego simon con figuras");
  bot.say("Vamos a jugar al "+this->GetName());
}


SimonShapeGame::~SimonShapeGame()
{

}


bool SimonShapeGame::EscucharRespuestas(vector<string> secuencia_generada)
{


    bot.setGrammar("cuadrado|circulo|mas|menos");
    AISoy1::Sentence sentence;

    for (int j=0;j<secuencia_generada.size();j++) {
        sentence=bot.listen();

        if (sentence.sentence().compare(secuencia_generada.at(j))==0){
            bot.say("si");
	    YesWithHead();
	}
        else {
            bot.say("no");
	    NoWithHead();
            return false;
        }

    }
    return true;



}


void SimonShapeGame::Run()
{
    bool fail=false;
    int rondas=1;
    int shape_size=5;
    Mouth m;
    vector<string> secuencia_generada;

    PutBlack();

    while (!fail) {

        bot.say("Ronda "+IntToString(rondas));

        //dibujamos y almacenamos las figuras mostradas
        for (int i=0;i<rondas;i++) {
            secuencia_generada.push_back(m.DrawRandomShape(shape_size));
            bot.mouthDraw(m.Get());
            sleep(1);
	    m.Fill();
	    bot.mouthDraw(m.Get());
	    sleep(1);
            m.Clear();
            bot.mouthDraw(m.Get());
        }

	//mostramos por consola secuencia
	cout<<"[ ";
        for (int j=0;j<secuencia_generada.size();j++)
            cout<<secuencia_generada.at(j)<<" ";
        cout<<" ]"<<endl;

	//escuchamos y actuamos en funcion de si son o no correctas las respuestas
        if (EscucharRespuestas(secuencia_generada)) {
            bot.say("Bien");
            rondas++;
        }
        else {
            bot.say("Mal");
            fail=true;
        }

        //reseteamo vectore
        secuencia_generada.clear();
    }
    
    bot.say("Has conseguido hacer "+IntToString(rondas-1)+" rondas");
}
