#include "myFunctions.cc"

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