#include <iostream>
#include <fstream>
#include "Lista.h"
#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> storeYears(vector<int> YEARS){
  int counter=0;
  vector<int> newYears;

  sort(YEARS.begin(),YEARS.end());
  YEARS.erase(std::unique(YEARS.begin(),YEARS.end()),YEARS.end());
  
  newYears=YEARS;

  return newYears;
}

/////////////////////////////////////////
void ReadFile(Lista &listaM, Lista &listaR, string dataFile, vector<int> &sortedYears)
    {//función para leer los datos formateados en un archivo texto, y armar objetos de tipo Registro con esos datos
        

    string day,year;
    string month, time, entry, ubi, fecha;
    vector<int> YEARS;

    
    ifstream archivo;//abrir el archivo
    archivo.open(dataFile);
    

    while(archivo>>fecha>>time>>entry>>ubi){//ciclo para acomodar los datos en las variables  
      for(int o=0;o<9;o++){
        if(o<2){
          day+=fecha[o];
        }
        else if(o>2 && o<6){
          month+=fecha[o];
        }
        else if (o>6){
          year+=fecha[o];
        }
      }
      
      if(entry=="R"){listaR.insertaOrden(Registro(atoi(day.c_str()),month,atoi(year.c_str()),time,entry,ubi));}
      else{listaM.insertaOrden(Registro(atoi(day.c_str()),month,atoi(year.c_str()),time,entry,ubi));}

      
      YEARS.push_back(atoi(year.c_str()));

      day="";//reseteo de las variables 
      month="";
      year="";
    }

    sortedYears=storeYears(YEARS);

  }

  void validateFiles(Lista &listaM, Lista &listaR, string dataFile, vector<int> &sortedYears)
  {//Función para proporcionar el nombre del archivo en el cual se va a buscar
    while (true){
      cout<<"Ingrese el nombre del archivo: "; cin>>dataFile;
      cout<<endl;
      ReadFile(listaM,listaR,dataFile,sortedYears);

      if(listaM.longitudLista()>0 || listaR.longitudLista()>0){//romper el ciclo si el archivo tiene datos
        break;
      }
      else{//continuar el ciclo si el archivo no existe o no tiene datos
        cout<<"El archivo no contiene datos o no existe, intente nuevamente"<<endl;
      }
    }
  }

  void UBIComparison(string cropped, Lista &listaM, Lista &listaR, vector<int> &sortedYears )
  {//función para comparar un substring de 3 caracteres con un UBI (string de un objeto Registro)

    cout<<"--------------------------------"<<endl;
    cout<<"Ingrese los primeros tres caracteres de UBI: ";  
    cin>>cropped; 
    cout<<"--------------------------------"<<endl;
    
    int mCounter=0, rCounter=0;

    for(int t=0; t<sortedYears.size();t++){


      
    }


  }


int main() {
  Lista listaM;
  Lista listaR;
  string dataFile="",cropped="";
  vector<int> sortedYears;

  validateFiles(listaM,listaR,dataFile,sortedYears);

  //cout<<listaM<<endl;
  //cout<<listaR<<endl;
  
  for(int z=0; z<sortedYears.size();z++){cout<<sortedYears[z]<<endl;}




}