#pragma once
#include <iostream>
#include <string>
#include "Registro.h"
using namespace std;

class Nodo{
  private:
  //atributos
  Registro registro;
  Nodo *sig;
  
  public:
  Nodo(Registro,Nodo*);
  Nodo(Registro);
  //getters
  Registro getDato();
  Nodo* getSig();
  //setters
  void setDato(Registro);
  void setSig(Nodo *);
};

Nodo::Nodo(Registro _registro, Nodo *sig_){//constructor con objeto y nodo
  registro=_registro;
  sig=sig_;
}

Nodo::Nodo(Registro dato_){//constructor con objeto
  registro=dato_;
  sig=NULL;
}

Registro Nodo::getDato(){//regresa el objeto
  return registro;
}

Nodo* Nodo::getSig(){//regresa el siguiente nodo
  return sig;
}

void Nodo::setDato(Registro dato_){//modifica el dato_
  registro=dato_;
}

void Nodo::setSig(Nodo *sig_){//modifica el nodo siguiente
  sig=sig_;
}