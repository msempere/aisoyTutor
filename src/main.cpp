#include "sequence.h"
#include "utils.h"
#include "tutorSentence.h"
#include "gameFactory.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv) {
    srand(time(NULL));
    bot.moveServo(AISoy1::Eyes,0.8,0.1);
    
    TutorSentence ts=TutorSentence("system",TipoSentence::SALUDO);
    ts.Say();
    
    

    /*
    cout<<"Cogemos el juego a traves del GameFactory"<<endl;

    Game *g=GameFactory::GetGame("realsimon");

    cout<<"Ejecutamos: "<<g->GetName()<<endl;

    g->Run();

    cout<<"Fin ejecucion"<<endl;
    */
    /*
    int r=-1;
    Game *g;

    
    AISoy1::Sentence sentence;

    while (true) {
	bot.say("A que tipo de juego quieres jugar?");
	bot.say("<break time=300ms />Puede ser agudeeza <break time=300ms /> caalculo <break time=300ms /> o memoria");

	bot.setGrammar("agudeza|calculo|memoria");
        sentence=bot.listen();

        if (sentence.sentence()=="agudeza") {
            r=GetRandom(0,3);

            if (r==0)
                g=GameFactory::GetGame("ledsgame");
            else if (r==1)
                g=GameFactory::GetGame("colorandleds");
            else if (r==2)
                g=GameFactory::GetGame("barra");
        }

        else if (sentence.sentence()=="calculo") {
            r=GetRandom(0,2);

            if (r==0)
                g=GameFactory::GetGame("mathsgame");
            else
                g=GameFactory::GetGame("desplazar");


        } else if (sentence.sentence()=="memoria") {
            r=GetRandom(0,4);

            if (r==0)
                g=GameFactory::GetGame("simoncolorgame");
            else if (r==1)
                g=GameFactory::GetGame("simonshapegame");
            else if (r==2)
                g=GameFactory::GetGame("simonnumbergame");
            else if (r==3)
                g=GameFactory::GetGame("realsimon");

        }

        g->Run();
    }

    return 0;
    */
}
