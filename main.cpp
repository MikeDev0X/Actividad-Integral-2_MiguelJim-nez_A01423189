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
      cout<<"Enter the file name: "; cin>>dataFile;
      cout<<endl;
      ReadFile(listaM,listaR,dataFile,sortedYears);

      if(listaM.longitudLista()>0 || listaR.longitudLista()>0){//romper el ciclo si el archivo tiene datos
        break;
      }
      else{//continuar el ciclo si el archivo no existe o no tiene datos
        cout<<"The file is empty or doesn't exist, try again"<<endl;
      }
    }
  }

  void UBIComparison(string &cropped, Lista &listaM, Lista &listaR, vector<int> &sortedYears )
  {//función para comparar un substring de 3 caracteres con un UBI (string de un objeto Registro)

    cout<<"--------------------------------"<<endl;
    cout<<"Enter the first 3 caracters of the UBI: ";  
    cin>>cropped; 
    cout<<"--------------------------------"<<endl;

    vector<string> meses={"jan","feb","mar","apr","may","jun","jul", "aug","sep","oct","nov","dec"};

    int mCounter=0, rCounter=0;
    bool gatoControl= false,perroControl=false;

    for(int t=0; t<sortedYears.size();t++){ 
      for(int u=0;u<12;u++){
        mCounter=((listaM.buscaEnLista(cropped, sortedYears[t], meses[u])).size());
        rCounter=((listaR.buscaEnLista(cropped, sortedYears[t], meses[u])).size());
        
        if(mCounter>0 || rCounter>0){
          gatoControl = true;perroControl=true;
        }
      }

      if(perroControl){cout<<"<month> <year> <M> <R>"<<endl;}

      for(int u=0;u<12;u++){
        mCounter=((listaM.buscaEnLista(cropped, sortedYears[t], meses[u])).size());
        rCounter=((listaR.buscaEnLista(cropped, sortedYears[t], meses[u])).size());
        
        if (gatoControl == true){
          
          cout<<"  "<<meses[u]<<"     "<<sortedYears[t]<<"    "<<mCounter<<"   "<<rCounter<<endl;
        }
      }

      if(gatoControl){
        cout<<endl;
      }
      gatoControl = false; perroControl=false;

      mCounter=0;
      rCounter=0;

    }
  }

int main() {
  Lista listaM;
  Lista listaR;
  string dataFile="",cropped="";
  string mainOption="";
  vector<int> sortedYears;

  validateFiles(listaM,listaR,dataFile,sortedYears);

  while(true){
    string UpperOption="";

    cout<<"Main: "<<endl;
    cout<<"A: Search for UBI Coincidences"<<endl;
    cout<<"B: Exit"<<endl; cin>>mainOption; cout<<endl;

    for(int z=0;z<mainOption.size();z++){
      UpperOption+=toupper(mainOption[z]);
    }

    if(UpperOption=="A"){
      UBIComparison(cropped,listaM,listaR,sortedYears);
    }
    else if(UpperOption=="B"){break;}
    else{cout<<"Incorrect option, try again"<<endl; continue;}
  }
}