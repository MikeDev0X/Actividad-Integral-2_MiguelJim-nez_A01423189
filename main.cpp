//Miguel Jiménez Padilla A01423189
//Actividad Integral estructura de datos lineales (Evidencia Competencia)
#include "myFunctions.cc"

int main() {
  Lista listaM;//lista ligada mar Mediterráneo
  Lista listaR;//lista ligada mar Rojo
  string dataFile="",cropped="";
  string mainOption="";
  vector<int> sortedYears;

  validateFiles(listaM,listaR,dataFile,sortedYears);//llenar las listas con el archivo de texto, obtener todos los años del archivo, ordenados y sin repeticiones
  
  while(true){
    string UpperOption="";

    cout<<"Main: "<<endl;
    cout<<"A: Search for UBI Coincidences"<<endl;
    cout<<"B: Exit"<<endl; cin>>mainOption; cout<<endl;

    for(int z=0;z<mainOption.size();z++){//pasar el string a Upper cases
      UpperOption+=toupper(mainOption[z]);
    }

    if(UpperOption=="A"){//buscar un UBI
      UBIComparison(cropped,listaM,listaR,sortedYears);//compara el ubi en todos los meses en la lista de años, imprime únicamente un año si hay 1 o más coincidencias de UBI
    }
    else if(UpperOption=="B"){break;}//salir del programa
    else{cout<<"Incorrect option, try again"<<endl; continue;}
  }
  return 0;
}