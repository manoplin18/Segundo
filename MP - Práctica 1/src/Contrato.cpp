#include "Contrato.h"

int Contrato::contador=1;

Contrato::Contrato(long int dni, Fecha f): idContrato(contador), fechaContrato(f) {
  this->contador++;
  this->dniContrato=dni;
}

Contrato::Contrato(const Contrato& c): idContrato(contador), fechaContrato(c.fechaContrato) {
  this->contador++;
  this->dniContrato=c.dniContrato;
}

Contrato::~Contrato(){
    this->dniContrato = 00000000;
    this->contador--;
    this->fechaContrato.setFecha(0, 0, 0);
}


void Contrato::ver() const {
  cout << this->dniContrato << " (" << this->idContrato << " - ";
  this->fechaContrato.ver(); //llamo al ver del objeto fecha
  cout << ")";
}

ostream& operator<<(ostream &s, const Contrato &c) {
  s << c.getDniContrato() << " (" << c.getIdContrato() << " - " << c.getFechaContrato() << " )";
  return s;
}

