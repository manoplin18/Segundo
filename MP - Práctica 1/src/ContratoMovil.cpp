#include <iostream>
#include <cstdlib>
#include <cstring> //strlen, strcpy
#include <iomanip> //std::setprecision
#include "Contrato.h"
#include "ContratoMovil.h"

ContratoMovil::ContratoMovil(long int dni, Fecha f, float p, int m, char *nac): Contrato(dni, f) {
  this->precioMinuto=p;
  this->minutosHablados=m;
  this->setNacionalidad(nac);
}

ContratoMovil::~ContratoMovil() {
  this->precioMinuto = 0;
  this->minutosHablados = 0;
  delete [] this->nacionalidad; this->nacionalidad = NULL;
}

ContratoMovil::ContratoMovil(const ContratoMovil& c):Contrato(c.getDniContrato(), c.getFechaContrato()){
  this->precioMinuto = c.precioMinuto;
  this->minutosHablados = c.minutosHablados;
  this->setNacionalidad(c.nacionalidad); 
}

void ContratoMovil::ver() const {
  Contrato::ver(); //IMPORTANTE: llamamos al ver que heredo de mi padre PARA QUE MUESTRE LO DEL PADRE
                   //... y a continuacion solo "me preocupo" de mostrar lo que es exclusivo del hijo
  cout << " " << this->minutosHablados << "m, " << this->nacionalidad << " " << this->precioMinuto << " - " << this->factura() << "e.";
}

float ContratoMovil::factura() const {
  float factura = 0;
  factura = precioMinuto * minutosHablados;
  return factura;
}


void ContratoMovil::setNacionalidad(const char* nac) {
  this->nacionalidad = new char [strlen(nac)+1]; //creo los espacios necesarios para poder copiar la informacion de nac
  strcpy(this->nacionalidad, nac);
}

ostream& operator<<(ostream &s, const ContratoMovil &c) {
  s << (Contrato &)c; //IMPORTANTE: convierto el objeto c (ContratoMovil &) a objeto Contrato &
                      // de esta forma se cree que es un objeto Contrato y muestra lo que indica el operator<< de Contrato
                      //... y a continuacion solo "me preocupo" de mostrar lo que es exclusivo del hijo
  s << " " << c.getMinutosHablados() << "m, " << c.getNacionalidad() << " " << c.getPrecioMinuto() << " - ";
  s << c.factura() << char(128);
  return s;
}
