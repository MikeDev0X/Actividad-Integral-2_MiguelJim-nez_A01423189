#pragma once
#include <iostream>
#include <string>
#include "Nodo.h"
#include "Registro.h"

using namespace std;
//.I.
class Lista{
  public:
  Lista();
  ~Lista();
  //getters
  Nodo* getHead();
  //setters
  void setHead(Nodo*);
  void insertaIncicio(Registro);
  void insertaFinal(Registro);
  void insertaOrden(Registro);

  int longitudLista();//Te regresa el tamaño en entero de la lista
  int buscaEnLista(string,int,string);

  bool operator<(Registro);
  bool operator<=(Registro);
  bool operator>(Registro);

  friend ostream& operator<< (ostream&, Lista&);

  private:
  Nodo* head;
};


Lista::Lista(){
  head=NULL;
}

Lista::~Lista(){

}

Nodo* Lista::getHead(){
  return head;
}

void Lista::setHead(Nodo* head_){
  head=head_;
}

// inserta un dato al inicio de la lista, recibe un numero entero
void Lista::insertaIncicio(Registro I){
  Nodo* nodo=new Nodo(I);
  if (head==NULL){ // caso si la lista esta vacia
    head=nodo;
  }
  else{ // caso si ya hay dantos dentro de la lista
    nodo->setSig(head);
    head=nodo;
  }
}

void Lista::insertaFinal(Registro I){ // inserta dato al final de la lista, recibe un numero entero
  Nodo* nodo=new Nodo(I);
  if (head==NULL){ // caso si el primer elemento esta vacio
    head=nodo;
  }
  else{ // caso si hay elementos en la lista
    Nodo* current_nodo=head;
    while(true){
      if(current_nodo->getSig()==NULL){
        current_nodo->setSig(nodo);
        break;
      }
      else{
        current_nodo=current_nodo->getSig();
      }
    }
  }
}

void Lista::insertaOrden(Registro n){ // inserta un dato nuevo en orden, recibe un numero entero
  Nodo* nuevo = new Nodo(n) ;
  if (head==NULL){
    head=nuevo;
  }
  else{
    Nodo* antes=head;
    Nodo* aux=head;
    while(aux!=NULL && aux->getDato()<n){
      antes=aux;
      aux=aux->getSig();
    }
    if (antes==aux){ //caso insertar al inicio
      nuevo->setSig(head);
      head=nuevo;
    }
    else if (aux==NULL){//caso insertar al final
      antes->setSig(nuevo);
    }
    else{//se inserta entre dos :)
      antes->setSig(nuevo);
      nuevo->setSig(aux);
    }
  }
}

int Lista::buscaEnLista(string croppedUBI, int year, string month){ 
  string cropped="", regMonth="";
  int regYear=0;
  int counter=0;

  vector<Registro> reg;

  if(head == NULL){ // caso si la lista esta vacia
    cout<<"The list is empty"<<endl;
   return 0;
  }

  else{ // hay elementos en la lista
    Nodo *nuevo = head;
    while(nuevo != NULL){ // while para recorrer la lista
      cropped=nuevo->getDato().getCroppedUBI(); 
      regMonth=nuevo->getDato().getMonth(); 
      regYear=nuevo->getDato().getYear(); 

      if(cropped==croppedUBI && regMonth==month && regYear==year){
        //reg.push_back(nuevo->getDato());
        counter++;
      }

      nuevo = nuevo->getSig();
    }
  }
  return counter;
}



int Lista::longitudLista(){//Te regresa el tamaño en entero de la lista
  if(head == NULL){//Caso en que esté vacía la lista
    cout<<"The list is empty"<<endl;
    return 0;
  }
  else{//Caso donde hay un elemento al menos
    Nodo *curr=head;
    int contador=0;
    while(curr != NULL){
      curr = curr->getSig();//Cuenta cada vez que recorre la lista
      contador++;
    }
    return contador;//regresa el contador de elementos final
  }
}

ostream& operator<<(ostream& salida,  Lista& lis){
  salida << "|| Contenido de la lista ligada||"<<"\n"<< "==========================="<<endl; 
  Nodo  *curr = lis.head,*aux;
  Registro reg;

    while(curr != NULL){
      reg=curr->getDato();
      salida << reg <<endl;

      curr=curr->getSig();//el apuntador a head avanza
    }

  return salida;//regresa todos los datos
}
