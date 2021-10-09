#pragma once
#include <iostream>
#include <string>
#include "Registro.h"
using namespace std;

class Nodo{
  private:
  Registro registro;
  Nodo *sig;
  
  public:
  Nodo(Registro,Nodo*);
  Nodo(Registro);
  ~Nodo();
  //getters
  Registro getDato();
  Nodo* getSig();
  //setters
  void setDato(Registro);
  void setSig(Nodo *);
  //impirimir
  void imprimirDato();
};

#include "Nodo.h"

Nodo::Nodo(Registro _registro, Nodo *sig_){
  registro=_registro;
  sig=sig_;
}

Nodo::Nodo(Registro dato_){
  registro=dato_;
  sig=NULL;
}

Nodo::~Nodo(){}

Registro Nodo::getDato(){
  return registro;
}

Nodo* Nodo::getSig(){
  return sig;
}

void Nodo::setDato(Registro dato_){
  registro=dato_;
}

void Nodo::setSig(Nodo *sig_){
  sig=sig_;
}

void Nodo::imprimirDato(){
  cout<<"El dato del nodo es: "<<registro<<", la dirección al nodo siguiente es: "<<sig<<endl;
}