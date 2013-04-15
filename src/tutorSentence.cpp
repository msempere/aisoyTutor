#include "tutorSentence.h"

const string TutorSentence::Kparam="{{param}}";
const string TutorSentence::database_path="data/aisoytutor.sqlite";
int first_row;

TutorSentence::TutorSentence()
{

}

TutorSentence::TutorSentence(const string &tipo, int tipo_sentence)
{
  SetIdioma("es");
  
  if(tipo.compare("ledsgame")==0){
    SetTabla(tipo+"_sentences");
  }
  else if(tipo.compare("mathsgame")==0){ 
    SetTabla(tipo+"_sentences");
  }
  else
    SetTabla("system_sentences");
    
  
  GetSentenceFromDB(tipo_sentence);
}



void TutorSentence::Replace(string reemplazada, string reemplazador)
{
  //int posicion=this->GetSentence().find(reemplazada);
  //this->GetSentence().replace(posicion,reemplazada.length(),reemplazador);
  
  cout<<"Reemplazar "<<reemplazada<<" por "<<reemplazador<<" en "<<this->GetSentence()<<endl;
  
  size_t index;
  while((index = this->GetSentence().find(reemplazada)) != string::npos)
    this->GetSentence().replace(index, reemplazada.length(), reemplazador);
  
  cout<<"Resultado de Fill: "<<this->GetSentence()<<endl;
  
}


TutorSentence& TutorSentence::Fill(string param)
{
  this->Replace(Kparam,param);
  return *this;
}


int TutorSentence::GetNumParameters()
{
  int posicion=this->GetSentence().find(Kparam);
  int cont=0;
  
  while(posicion!=string::npos){
    cont++;
    posicion=this->GetSentence().find(Kparam,posicion+1); 
  }
  return cont;
}


string TutorSentence::TipoSentenceToString(int tipo_sentence)
{
  if(tipo_sentence==TipoSentence::SALUDO)
    return "saludo";
  else
    if(tipo_sentence==TipoSentence::DESPEDIDA)
      return "despedida";
    else
      if(tipo_sentence==TipoSentence::PUNTUACION)
	return "puntuacion";
      else{
	cerr<<"Error al transformar TipoSentence to String"<<endl;
	return "error";
      }
	
}

/*
int TutorSentence::Select_callback(void *p_data, int num_fields, char **p_fields, char **p_col_names) {

  int i;

  int* nof_records = (int*) p_data;
  (*nof_records)++;

  if (first_row) {
    first_row = 0;

    for (i=0; i < num_fields; i++) {
      printf("%20s", p_col_names[i]);
    }

    printf("\n");
    for (i=0; i< num_fields*20; i++) {
      printf("=");
    }
    printf("\n");
  }

  for(i=0; i < num_fields; i++) {
    if (p_fields[i]) {
      printf("%20s", p_fields[i]);
    }
    else {
      printf("%20s", " ");
    }
  }

  printf("\n");
  return 0;
  
}

void TutorSentence::Select_stmt() {
  char *errmsg;
  int   ret;
  int   nrecs = 0;

  first_row = 1;

  ret = sqlite3_exec(database, stmt, Select_callback, &nrecs, &errmsg);

  if(ret!=SQLITE_OK) 
    cerr<<"Error al hacer el select statement "<<stmt<<" "<<errmsg<<endl;
  else
    cout<<"Devueltas "<<nrecs<<" filas"<<endl;
}*/

//http://www.adp-gmbh.ch/sqlite/bind_insert.html
//http://books.google.es/books?id=VsZ5bUh0XAkC&pg=PA226&lpg=PA226&dq=sqlite3_bind_text++quotes&source=bl&ots=u55Hkq0-w5&sig=Wilg1Oi1ZiziyutKChvSIFJq48c&hl=es&sa=X&ei=GzdwT7KSIcL80QXcnomOAg&ved=0CFYQ6AEwBQ#v=onepage&q=sqlite3_bind_text%20%20quotes&f=false
//sqlite3_bind_text  quotes
string TutorSentence::GetSentenceFromDB(int tipo_sentence)
{
  string tipo=TipoSentenceToString(tipo_sentence);
  string select="SELECT sentencia FROM "+tabla+" WHERE idioma='?' AND tipo='?' ORDER BY RANDOM() LIMIT 1";
  
  
    if (sqlite3_open(database_path.c_str(),&database)==SQLITE_OK) {

        if (sqlite3_prepare(database,select.c_str(), -1,&stmt,0)!= SQLITE_OK) 
	{
            cerr<<"No se pudo preparar el statement."<<endl;
            return "";
        }
        else { //si el prepare fue correcto

            cout<<"Tenemos "<<sqlite3_bind_parameter_count(stmt)<<" wilcards."<<endl;

            //bind del tipo de sentencia
            if (sqlite3_bind_text(stmt,2,tipo.c_str(),tipo.length(),SQLITE_STATIC)!= SQLITE_OK) {
                cerr<<"No se pudo hacer el bind del TIPO de sentencia"<<endl;
                return "";
            }

            //bind del idioma
            if (sqlite3_bind_text(stmt,1,idioma.c_str(),idioma.length(),SQLITE_STATIC)!= SQLITE_OK) {
                cerr<<"No se pudo hacer el bind del IDIOMA de la sentencia"<<endl;
                return "";
            }

	  //una vez preparada la sentencia y los bind, realizamos la consulta
	  int r=sqlite3_step(stmt);
	  cout<<"R: "<<r<<endl;
	  
	  if(r==SQLITE_ROW){
	    cout<<"---> "<<sqlite3_column_text(stmt, 0)<<endl;
	    sentencia=string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
	    cout<<"Respuesta: "<<sentencia<<endl;
	    return sentencia;
	  }
	  else{
	    cerr<<"Imposible obtener consulta"<<endl;
	    return "";
	  }
	  
        }
        sqlite3_close(database);
    }
    else {
        cerr<<"Imposible abrir DB"<<endl;
        return "";
    }
}

/*
string TutorSentence::GetSentenceFromDB(int tipo_sentence)
{
  
  
  const char* siguiente;
  sqlite3_stmt *resultado;
  
  if(sqlite3_open("data/aisoytutor.sqlite",&database)==SQLITE_OK){
    
    string consulta="SELECT sentencia FROM "+tabla+" WHERE idioma='"+idioma+"' AND tipo='"+TipoSentenceToString(tipo_sentence)+"' ORDER BY RANDOM() LIMIT 1;";
    
    
    cout<<"Consulta: "<<consulta<<endl;
    
    if(sqlite3_prepare(database,consulta.c_str(),consulta.length(),&resultado,&siguiente)==SQLITE_OK){
      
      int r=sqlite3_step(resultado);
      cout<<"R: "<<r<<endl;
      
      if(r==SQLITE_ROW){
	cout<<"---> "<<sqlite3_column_text(resultado, 0)<<endl;
	sentencia=string(reinterpret_cast<const char*>(sqlite3_column_text(resultado, 0)));
	cout<<"Respuesta: "<<sentencia<<endl;
      }
      else
	cerr<<"Imposible obtener consulta"<<endl;
    }
    else
      cerr<<"Imposible preparar la consulta"<<endl;
  }
  else
    cerr<<"Imposible abrir DB"<<endl;
  
  sqlite3_finalize(resultado);
  sqlite3_close(database);
  return sentencia;
}
*/


void TutorSentence::Say()
{
  bot.say(sentencia);
}




