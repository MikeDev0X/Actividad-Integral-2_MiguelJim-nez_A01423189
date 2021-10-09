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
  //void borrarDato(Registro);
  //void imprimeLista();

  int longitudLista();//Te regresa el tamaño en entero de la lista
  //vector<Barco> buscaeEnLista(string);

  bool operator<(Registro);
  bool operator<=(Registro);
  bool operator>(Registro);

  friend ostream& operator<< (ostream&, Lista&);

  private:
  Nodo* head;
};


#include "Lista.h"
//print(hello world);

using namespace std;

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
/*
int Lista::buscaeEnLista(int num){ // busca un dato dentro de la lista, recibe un numero entero, regresa un entero
  int cat=0;
  if(head == NULL){ // caso si la lista esta vacia
    cout<<"La Lista esta vacía"<<endl;
   return -1;
  }
  else{ // hay elementos en la lista
    Nodo *nuevo = head;
    while(nuevo != NULL && nuevo->getDato() != num){ // while para recorrer la lista
      nuevo = nuevo->getSig();
      cat++;
    }
    if(nuevo == NULL){ // el dato solicitado no existe
      cout << "No se encontró el valor buscado" << endl;
      return -1;
    }
    else{ // el dato solicitado existe
      cout<< "Se encontró"<<endl;
      return cat;
    }
  }
}
*/


int Lista::longitudLista(){//Te regresa el tamaño en entero de la lista
  if(head == NULL){//Caso en que esté vacía la lista
    cout<<"La Lista esta vacía"<<endl;
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
/*
void Lista::borrarDato(Registro num){ // recibe un numero entero, lo busca dentro de la lista y lo borra 
  if(head == NULL){
    cout<<"La lista esta vacía"<<endl;
  }
  else{
    Nodo *aux1=head,*aux2=head;
    while(aux2 != NULL && aux2->getDato() != num){
      aux1=aux2;
      aux2= aux2-> getSig();
    }
    if(aux2 == NULL){
      cout<<"No se encontró dicho dato"<<endl;
    }
    else if(aux1== aux2){
      head = head->getSig();
      delete aux2;
    }
    else{
      aux1->setSig(aux2->getSig());
      delete aux2;
    }
  }
}
*/
/*
void Lista::imprimeLista(){
  Nodo* current_nodo=head;
  while(true){
      Registro reg;
      if(current_nodo->getSig()==NULL){
        reg=current_nodo->getDato();
        cout<<reg<<endl;
        break;
      }
      else{
        reg=current_nodo->getDato();
        cout<<reg<<endl;
        current_nodo=current_nodo->getSig();
      }
    }
}*/


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
