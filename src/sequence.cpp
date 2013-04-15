#include "sequence.h"

void Sequence::Reproduce()
{
  for(int i=0;i<contenedor.size();i++){
    contenedor.at(i)->Draw();
    contenedor.at(i)->Say();
  }
}


void Sequence::ReproduceOnlySounds()
{
  for(int i=0;i<contenedor.size();i++){
    //contenedor.at(i)->Draw();
    contenedor.at(i)->Say();
  }
}

void Sequence::ReproduceOnlyColors()
{
  for(int i=0;i<contenedor.size();i++){
    contenedor.at(i)->Draw();
    sleep(1);
    PutBlack();
  }
}

void Sequence::Print(){
  
  string dev="SEQUENCE: ";
  
  for(int i=0;i<contenedor.size();i++)
    dev+="["+contenedor.at(i)->GetNombre()+" # "+IntToString(contenedor.at(i)->GetValor())+"] ";
  dev+"\n";
  
  cout<<dev<<endl;
}

Sequence::Sequence()
{

}


void Sequence::GenerateRandomSequence(int total, int erroneos){
    
  Color *arrayColors[total];
  
   //-1=error, 1=correcto
  int colores[total];
  
  //iniciamos vector
  for(int j=0;j<total;j++)
    colores[j]=0;
   
  //colocamos los erroneos
  for(int i=0;i<erroneos;i++){
    
    int pos=GetRandom(0,total);
    
    while(colores[pos]==-1)
      pos=GetRandom(0,total);
    
    Color *c=new ErrorColor();
    arrayColors[pos]=c;
    colores[pos]=-1;    
  }

  
  cout<<"ERRONEOS: [ ";
  for(int m=0;m<total;m++)
    cout<<colores[m]<<" ";
  cout<<" ]"<<endl;
  
  
  //colocamos los correctos
  for(int k=0;k<total;k++){
    
    if(colores[k]!=-1){
      Color *c=new Color();
      c->SetRandom();
      //contenedor[k]=c;
      arrayColors[k]=c;
      colores[k]=1;
    }
  }
  
  //respaldamos el array final sobre el contenedor del objeto secuencia
  for(int m=0;m<total;m++)
    contenedor.push_back(arrayColors[m]); 
}

/**
   Generate a color sequence with n colors and m erroneus colors
   @param total is the total number of colors
   @param erroneos is the number of erroneus colors
*/
Sequence::Sequence(int total, int erroneos){
  
  Color *arrayColors[total];
  
   //-1=error, 1=correcto
  int colores[total];
  
  //iniciamos vector
  for(int j=0;j<total;j++)
    colores[j]=0;
   
  //colocamos los erroneos
  for(int i=0;i<erroneos;i++){
    
    int pos=GetRandom(0,total);
    
    while(colores[pos]==-1)
      pos=GetRandom(0,total);
    
    Color *c=new ErrorColor();
    arrayColors[pos]=c;
    colores[pos]=-1;    
  }

  
  cout<<"ERRONEOS: [ ";
  for(int m=0;m<total;m++)
    cout<<colores[m]<<" ";
  cout<<" ]"<<endl;
  
  
  //colocamos los correctos
  for(int k=0;k<total;k++){
    
    if(colores[k]!=-1){
      Color *c=new Color();
      c->SetRandom();
      //contenedor[k]=c;
      arrayColors[k]=c;
      colores[k]=1;
    }
  }
  
  //respaldamos el array final sobre el contenedor del objeto secuencia
  for(int m=0;m<total;m++)
    contenedor.push_back(arrayColors[m]); 
}

Sequence::~Sequence()
{
  for(int i=0;i<Size();i++)
    delete Get(i);
}


Color* Sequence::Get(int i)
{
  return contenedor[i];
}

int Sequence::Size()
{
  return contenedor.size();
}

int Sequence::GetNumErroneos()
{
  int num=0;
  
  for(int i=0;i<Size();i++){
    if(Get(i)->Erroneo())
      num++;
  }
  return num;
}

void Sequence::Add(Color* c)
{
  contenedor.push_back(c);
}


Sequence Sequence::GetErroneos(){
  
  Sequence seq;
  
  for(int i=0;i<Size();i++){
    if(Get(i)->Erroneo()){
      seq.Add(Get(i));
    }
  }
  return seq;
}


bool Sequence::operator==(const Sequence &derecha) const
{
  bool dev=true;
  
  if(contenedor.size()>=derecha.contenedor.size())
  {
    for(int i=0;i<contenedor.size();i++)
    {
      if(contenedor.at(i)->GetNombre().compare(derecha.contenedor.at(i)->GetNombre())!=0)
	return false;
    }
  }
  else{
    for(int i=0;i<derecha.contenedor.size();i++)
    {
      if(contenedor.at(i)->GetNombre().compare(derecha.contenedor.at(i)->GetNombre())!=0)
	return false;
    }
  }
  return dev;
}


bool Sequence::CompareErrors(Sequence s)
{
  if(GetErroneos()==s.GetErroneos())
    return true;
  return false;
}


int Sequence::GetNumErrorColorsEqual(Sequence s)
{
  int count=0;
  Sequence err1=GetErroneos();
  Sequence err2=s.GetErroneos();
  
  if(err1.Size()>=err2.Size()){
    for(int i=0;i<Size();i++){
      if(err1.Get(i)->GetNombre().compare(err2.Get(i)->GetNombre()))
	count++;
    }
  }
  else{
    for(int i=0;i<err2.Size();i++){
      if(err1.Get(i)->GetNombre().compare(err2.Get(i)->GetNombre()))
	count++;
    }
  }
  return count;
}

void Sequence::Clear()
{
  contenedor.clear();
}

Sequence& Sequence::operator=(Sequence& s)
{
  for(int i=0;i<s.Size();i++){
    Color *c=new Color();
    c->SetValor(s.Get(i)->GetValor());
    c->SetNombre(s.Get(i)->GetNombre());
    
    if(s.Get(i)->Erroneo())
      c->SetErroneo();
    
    Add(c);
  }
  
  return *this;
}



