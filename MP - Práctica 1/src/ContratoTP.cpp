#include "ContratoTP.h"

int ContratoTP::minutosTP=300;
float ContratoTP::precioTP=10;
const float ContratoTP::precioExcesoMinutos=0.15;

ContratoTP::ContratoTP(long int dni, Fecha f, int m):Contrato(dni,f){
    this->minutosHablados=m;
}

void ContratoTP::setTarifaPlana(int m, float p) {
  ContratoTP::minutosTP=m;
  ContratoTP::precioTP=p;
}

void ContratoTP::ver() const {
  cout << this->getDniContrato() << " (" << this->getIdContrato() << " - " << this->getFechaContrato()  << ") " << this->minutosHablados<< "m, " << minutosTP <<" (" << this->precioTP << ") - " << this->factura() << "e.";
}

ostream& operator<<(ostream &s, const ContratoTP &c){

  s << (Contrato &)c; //IMPORTANTE: convierto el objeto c (ContratoMovil &) a objeto Contrato &
                      // de esta forma se cree que es un objeto Contrato y muestra lo que indica el operator<< de Contrato
                      //... y a continuacion solo "me preocupo" de mostrar lo que es exclusivo del hijo
  s << " " << c.getMinutosHablados() << "m, " << c.getLimiteMinutos() << " (" << c.factura(true) << ") - ";
  s << c.factura() << " e.";
  return s;
}
