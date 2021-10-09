#pragma once
#include <string>
#include <vector>
using namespace std;

class Registro{
  public:
    //Constructores
    Registro();
    Registro(int,string,int,string,string,string);    ~Registro();

    //Accesores
    int getDay();
    string getMonth();
    int getYear();
    string getTime();
    string getEntry();
    string getUBI();
    string getDayString();
    string getYearString();
    int getMonthIndex();
    string getCroppedUBI();

    //Modificadores
    void setDay(int);
    void setMonth(string);
    void setYear(int);
    void setTime(string);
    void setEntry(string);
    void setUBI(string);
    void setMonthIndex(int);

    //sobrecarga de operadores
    friend std :: ostream& operator<<(std :: ostream&, Registro&);
    bool operator<(Registro);
    bool operator<=(Registro);
    bool operator>(Registro);

  private:
    //variables privadas
    int day,year,MonthIndex;
    string month,time,entry,ubi;
    string dates[12];
    int z=0;
};

Registro::Registro(){//Constructor por definición
  day=0; month=""; year=0;
  time=""; entry=""; ubi="";
}

Registro::Registro(int day, string month, int year, string time, string entry, string ubi){//Constructor por parámetros
  this->day=day;
  this->month=month;
  this->year=year;
  this->time=time;
  this->entry=entry;
  this->ubi=ubi;

  //meses y sus índices
  dates[0]="jan"; dates[1]="feb"; dates[2]="mar"; dates[3]="apr";
  dates[4]="may"; dates[5]="jun"; dates[6]="jul"; dates[7]="aug";
  dates[8]="sep"; dates[9]="oct"; dates[10]="nov"; dates[11]="dec";

  //definición de índice del mes
  for (int z=0; z<12; z++){
    if(month==dates[z]){
      setMonthIndex(z);
      break;
    }
  }
}

Registro:: ~Registro(){}//destructor

//Accesores
int Registro::getDay(){return day;}
string Registro::getMonth(){return month;}
int Registro::getYear(){return year;}
string Registro::getTime(){return time;}
string Registro::getEntry(){return entry;}
string Registro::getUBI(){return ubi;}
string Registro::getDayString(){return to_string(day);}
string Registro::getYearString(){return to_string(year);}
int Registro::getMonthIndex(){
  return MonthIndex;
} 

string Registro::getCroppedUBI(){
  string crp;
  for(int g=0;g<3;g++){
    crp+=ubi[g];
  }
  return crp;
}
//Modificadores
void Registro::setDay(int day){this->day=day;}
void Registro::setMonth(string month){this->month=month;}
void Registro::setYear(int year){this->year=year;}
void Registro::setTime(string time){this->time=time;}
void Registro::setEntry(string entry){this->entry=entry;}
void Registro::setUBI(string ubi){this->ubi=ubi;}

void Registro::setMonthIndex(int MonthIndex){this->MonthIndex=MonthIndex;}

bool Registro :: operator<(Registro reg){//sobrecarga de operador <
  if (ubi<reg.getUBI())
    return true;
  else if(ubi==reg.getUBI()){
    if (year<reg.getYear())
      return true;
    else if(year==reg.getYear()){
      if (MonthIndex<reg.getMonthIndex())
        return true;
      else if(MonthIndex==reg.getMonthIndex()){
        if(day<reg.getDay())
          return true;
        else  
          return false;
      }
      else
        return false;
    }
    else  
      return false;
  }
  else
    return false;
  return 0;
}

bool Registro :: operator<=(Registro reg){//sobrecarga de operador <=
  if (ubi<=reg.getUBI())
    return true;
  else if(ubi==reg.getUBI()){
    if (year<=reg.getYear())
      return true;
    else if(year==reg.getYear()){
      if (MonthIndex<=reg.getMonthIndex())
        return true;
      else if(MonthIndex==reg.getMonthIndex()){
        if(day<=reg.getDay())
          return true;
        else  
          return false;
      }
      else
        return false;
    }
    else  
      return false;
  }
  else
    return false;
  return 0;
}

bool Registro :: operator>(Registro reg){//sobrecarga de operador >

  if (ubi>reg.getUBI()){
    return true;
  }
  else if(ubi==reg.getUBI()){
    if (year>reg.getYear()){
      return true;
    }
    else if(year==reg.getYear()){
      if (MonthIndex>reg.getMonthIndex()){
        return true;
      }
      else if(MonthIndex==reg.getMonthIndex()){
        if(day>reg.getDay()){
          return true;
        }
        else{
          return false;
        }  
      }
      else{
        return false;
      }
    }
    else{
      return false;
    }  
  }
  else{
    return false;
  }
}

//sobrecarga de operador << para imprimir un objeto de tipo Registro
std :: ostream& operator<<(std :: ostream& salida, Registro& reg){
  salida << reg.getDayString()+"-" + reg.getMonth()+"-"+ reg.getYearString()+"  "+ reg.getTime()+"  "+ reg.getEntry()+ "  "+ reg.getUBI()<<endl;
  return salida;
}