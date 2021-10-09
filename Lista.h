#pragma once
#include <iostream>
#include "Nodo.h"
#include "Registro.h"

using namespace std;
//
class Lista{
  public:
  //constructores
  Lista();

  //accesores
  Nodo* getHead();

  //modificadores
  void setHead(Nodo*);

  //insercion y buscadores
  void insertaOrden(Registro);
  int longitudLista();
  int buscaEnLista(string,int,string);

  //sobrecarga de operadores
  bool operator<(Registro);
  bool operator<=(Registro);
  bool operator>(Registro);
  friend ostream& operator<< (ostream&, Lista&);

  private:
  Nodo* head;//atributos
};


Lista::Lista(){//constructor por omisión
  head=NULL;
}

Nodo* Lista::getHead(){
  return head;
}

void Lista::setHead(Nodo* head_){
  head=head_;
}

void Lista::insertaOrden(Registro n){ // inserta un dato nuevo en orden, recibe un numero entero
  Nodo* nuevo = new Nodo(n) ;
  if (head==NULL){//caso en que la lista está vacía
    head=nuevo;
  }
  else{
    Nodo* antes=head;
    Nodo* aux=head;
    while(aux!=NULL && aux->getDato()<n){//colocar apuntadores
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
    else{//se inserta entre dos
      antes->setSig(nuevo);
      nuevo->setSig(aux);
    }
  }
}

int Lista::buscaEnLista(string croppedUBI, int year, string month){//busca coincidencias de UBI recortado, año y mes; si encuentra coincidencias, un contador se itera y al final se regresa 

  string cropped="", regMonth="";
  int regYear=0;
  int counter=0;

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
        counter++;//se incrementa el contador
      }
      nuevo = nuevo->getSig();
    }
  }
  return counter;//regreso del contador
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
    return contador;//regresa el contador
  }
}

ostream& operator<<(ostream& salida,  Lista& lis){//sobrecarga que recorre toda una lista ligada e imprime los objetos, con una sobrecarga en la clase Registro
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
