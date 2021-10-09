#include <fstream>
#include "Lista.h"
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
vector<int> sortYears(vector<int> YEARS)
{//función que regresa un vector con los años de todos los registros en el archivo de texto, ordenados y sin repeticiones
  int counter=0;
  vector<int> newYears;

  sort(YEARS.begin(),YEARS.end());
  YEARS.erase(std::unique(YEARS.begin(),YEARS.end()),YEARS.end());
  
  newYears=YEARS;
  return newYears;//regreso del nuevo vector
}
/////////////////////////////////////////////////////////////////////////////////
void ReadFile(Lista &listaM, Lista &listaR, string dataFile, vector<int> &sortedYears)
    {//función para leer los datos formateados en un archivo texto, e introducir objetos de tipo Registro en dos listas ligadas
        
    string day,year;
    string month, time, entry, ubi, fecha;
    vector<int> YEARS;

    ifstream archivo;
    archivo.open(dataFile);//abrir el archivo
    
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
      
      if(entry=="R"){listaR.insertaOrden(Registro(atoi(day.c_str()),month,atoi(year.c_str()),time,entry,ubi));}//caso de que entry sea R, se agrega en su respectiva lista

      else if(entry=="M"){listaM.insertaOrden(Registro(atoi(day.c_str()),month,atoi(year.c_str()),time,entry,ubi));}//caso de que entry sea M, se agrega en su respectiva lista

      YEARS.push_back(atoi(year.c_str()));//se guardan todos los años conforme se recorre el archivo

      day="";//reseteo de las variables 
      month="";
      year="";
    }

    sortedYears=sortYears(YEARS);//se obtienen los años ordenados
  }
/////////////////////////////////////////////////////////////////////////////////
  void validateFiles(Lista &listaM, Lista &listaR, string dataFile, vector<int> &sortedYears)
  {//Función para proporcionar el nombre del archivo en el cual se va a buscar
    while (true){
      cout<<"Enter the file name: "; cin>>dataFile;
      cout<<endl;
      ReadFile(listaM,listaR,dataFile,sortedYears);//se lee el archivo y guardan los datos en las listas

      if(listaM.longitudLista()>0 || listaR.longitudLista()>0){//romper el ciclo si el archivo tiene datos
        break;
      }
      else{//continuar el ciclo si el archivo no existe o no tiene datos
        cout<<"The file is empty or doesn't exist, try again"<<endl;
      }
    }
  }
/////////////////////////////////////////////////////////////////////////////////
  void UBIComparison(string &cropped, Lista &listaM, Lista &listaR, vector<int> &sortedYears )
  {//función para comparar un substring de 3 caracteres con un UBI (string de un objeto Registro)

    while (true){//comprobación de que el UBI ingresado sea de 3 caracteres
      cout<<"---------------------------------------------"<<endl;
      cout<<"Enter the first 3 caracters of the UBI: ";  
      cin>>cropped; 
      cout<<"---------------------------------------------"<<endl;
      if(cropped.length()==3){break;}
      else{cout<<"the UBI must be 3 caracters long, try again"<<endl;}
    }

    vector<string> meses={"jan","feb","mar","apr","may","jun","jul", "aug","sep","oct","nov","dec"};

    int mCounter=0, rCounter=0, printsCOUNTER=0;//contadores de repeticiones en Mediterráneo, Rojo y de impresiones
    bool gatoControl= false,perroControl=false,aveControl=false;//variables de control
    
    for(int t=0; t<sortedYears.size();t++){ //ciclo que se repite por cada año en el vector
      for(int u=0;u<12;u++){//ciclo que se repite por cada mes
        //se utiliza el método busca en lista para buscar el número de ocurrencias del UBI y se iguala en su respectivo contador 

        mCounter=(listaM.buscaEnLista(cropped, sortedYears[t], meses[u]));
        rCounter=(listaR.buscaEnLista(cropped, sortedYears[t], meses[u]));
        
        if(mCounter>0 || rCounter>0){//si alguno de los contadores es >0, significa que se va a imprimir todo ese año, entonces las variables de control se cambian a true y se rompe el ciclo para no trabajar de más
          gatoControl = true;perroControl=true;
          break;
        }
      }

      if(perroControl){cout<<"<month> <year> <M> <R>"<<endl;}//se imprime este encabezado 

      for(int u=0;u<12;u++){//se repite el mismo ciclo para imprimir si la variable de control es true
        mCounter=(listaM.buscaEnLista(cropped, sortedYears[t], meses[u]));
        rCounter=(listaR.buscaEnLista(cropped, sortedYears[t], meses[u]));
        
        if (gatoControl == true){
          cout<<"  "<<meses[u]<<"     "<<sortedYears[t]<<"    "<<mCounter<<"   "<<rCounter<<endl;
          printsCOUNTER++;//se incrementa el contador de impresiones
        }
        if(u==11){aveControl=true;}
      }

      if(gatoControl){
        cout<<endl;
      }

      gatoControl = false; perroControl=false;
      mCounter=0;
      rCounter=0;

      if(t==sortedYears.size()-1 && aveControl && printsCOUNTER==0){//si es el último año y último mes y no se imprimió nada, quiere decir que no hubieron coincidencias de UBI
        cout<<"The UBI searched for doesn't show coincidences, try another time!"<<endl<<endl;
      }

    }
  }
  /////////////////////////////////////////////////////////////////////////////////