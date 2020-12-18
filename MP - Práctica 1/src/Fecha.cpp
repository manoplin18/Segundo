#include "Fecha.h"
#include <string.h>
#define AnioDosMil 2000;
Fecha::Fecha(const int &dia, const int &m, const int &anio) {
    this->setFecha(dia, m, anio); //asi no repito codigo
}

void Fecha::setFecha(const int &dia, const int &mes, const int &a) {

    int dmax, diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    this->anio=a; //Para averiguar con la funcion bisiesto() si es o no
    if (this->bisiesto())
        diaMes[2]=29;

    if (mes<1)  //si el mes es incorrecto
      this->mes = 1;
    else if (mes>12)
      this->mes = 12;
    this->mes = mes;
    dmax=diaMes[mes]; //fija el dia del mes

    this->dia = dia;
    if (dia > dmax) //si dia es superior al numero de dias de dicho mes o inferior a 1 se pone por defecto el más cercano
      this->dia = dmax;
    else if (dia < 1)
     this->dia = 1;

}

bool Fecha::bisiesto() const { 
    int anio = this->anio;
    if ( anio % 4 == 0){
      if( anio % 100 == 0){
        if( anio % 400 == 0)
          return true;
        else
          return false;
      }else
        return true;
    }else
        return false;

}

void Fecha::ver() const {
  if (this->dia < 10)
    cout << "0";
  cout << this->dia << "/";
  if (this->mes < 10)
    cout << "0";
  cout << this->mes << "/" << this->anio;
}

Fecha Fecha::operator++() {   //++f
    int dmax, diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (this->bisiesto()) //si el anio es bisiesto febrero tiene 29 dias
      diaMes[2]=29;
    dmax=diaMes[this->mes];
    this->dia++;
    if (this->dia>dmax) { //si al incrementar dia superamos el numero de dias de dicho mes
        this->dia=1;      //pasamos a 1
        this->mes++;      //del mes siguiente
        if (this->mes>12) { //si al incrementar mes pasamos de 12 meses
            this->mes=1;    //pasamos al mes 1
            this->anio++;   //del a�o siguiente
        }
    }
    return *this; //devolvemos el objeto fecha ya incrementado
}

Fecha Fecha::operator++(const int i) {   //f++
    Fecha fecha_aux = *this;
    int dmax, diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (this->bisiesto()) //si el anio es bisiesto febrero tiene 29 dias
      diaMes[2]=29;
    dmax=diaMes[this->mes];
    this->dia++;
    if (this->dia > dmax) { //si al incrementar dia superamos el numero de dias de dicho mes
        this->dia = 1;      //pasamos a 1
        this->mes++;      //del mes siguiente
        if (this->mes > 12) { //si al incrementar mes pasamos de 12 meses
            this->mes = 1;    //pasamos al mes 1
            this->anio++;   //del anio siguiente
        }
    }
    return fecha_aux; //devolvemos el auxiliar sin incrementer pero sí incrementamos el objeto
}

Fecha Fecha::operator+(const int &i){
    int  diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (this->bisiesto()) //si el anio es bisiesto febrero tiene 29 dias
      diaMes[2]=29;
    int dmax = diaMes[this->mes]; // Lo coloco aqui para evitar fallos con el bucle while (evitar que dmax contenga basura)
    this->dia+=i;
    while(this->dia >= dmax){ // Por si el usuario suma varios meses o años en formato dia Ej: 350 dias
      dmax=diaMes[this->mes];
      if (this->dia>dmax) { //si al incrementar dia superamos el numero de dias de dicho mes
          this->dia -= dmax; //Como nos pasamos de día hacemos que dia valga lo mismo que esa diferencia
          this->mes++;      //del mes siguiente
          if (this->mes>12) { //si al incrementar mes pasamos de 12 mese
              this->mes=1;    //pasamos al mes que corresponda
              this->anio++;   //del anio siguiente
          }
      }
    }
    return *this; //devolvemos el objeto fecha ya incrementado
}

Fecha operator+(const int &i, const Fecha &f){
  int  diaMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
  Fecha f_aux = f;
    if (f_aux.bisiesto()) //si el anio es bisiesto febrero tiene 29 dias
      diaMes[2]=29;
    int dmax = diaMes[f.mes]; // Lo coloco aqui para evitar fallos con el bucle while (evitar que dmax contenga basura)
    f_aux.dia+=i;
    while(f_aux.dia >= dmax){ // Por si el usuario suma varios meses o años en formato dia Ej: 350 dias
      dmax=diaMes[f_aux.mes];
      if (f_aux.dia>dmax) { //si al incrementar dia superamos el numero de dias de dicho mes
          f_aux.dia -= dmax; //Como nos pasamos de día hacemos que dia valga lo mismo que esa diferencia
          f_aux.mes++;      //del mes siguiente
          if (f_aux.mes>12) { //si al incrementar mes pasamos de 12 mese
              f_aux.mes=1;    //pasamos al mes que corresponda
              f_aux.anio++;   //del anio siguiente
          }
      }
    }
  return f_aux;
}

ostream& operator<<(ostream &s, const Fecha &f){
  char primera_letra[] = {' ','E','F','M','A','M','J','J','A','S','O','N','D'} ;
  char segunda_letra[] = {' ','n','e','a','b','a','u','u','g','e','c','o','i'};
  char tercera_letra[] = {' ','e','b','r','r','y','n','l','o','p','t','v','c'};

   s << f.getDia() << " " << primera_letra[f.getMes()] << segunda_letra[f.getMes()] << tercera_letra[f.getMes()] << " " << f.getAnio();
   return s;
}

