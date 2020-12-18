#include <cstdlib>
#include <cstring> //strlen, strcpy
#include <iomanip> //std::setprecision
#include <sstream> //stringstream
#include "Cliente.h"

Cliente::Cliente(long int d, char *nom, Fecha f):fechaAlta(f) {
  this->dni=d;                                                  
  this->nombre=new char[strlen(nom)+1];
  strcpy(this->nombre, nom);
}

Cliente::~Cliente() {
  delete [] this->nombre; //si en el constructor uso new [] en el destructor uso delete []
}

Cliente& Cliente::operator=(const Cliente& c) {
  if (this != &c) { //si no es x=x
    this->dni=c.dni;
    this->setNombre(c.nombre);
    this->setFecha(c.fechaAlta);
  }
  return *this;
}

bool Cliente::operator==(const Cliente &c) const {
  if (this->dni!=c.dni)
    return false;
  if (strcmp(this->nombre, c.nombre)!=0)
    return false;
  if (this->fechaAlta.getDia()!=c.fechaAlta.getDia() ||
      this->fechaAlta.getMes()!=c.fechaAlta.getMes() ||
      this->fechaAlta.getAnio()!=c.fechaAlta.getAnio())
      return false;
  return true;
}

void Cliente::setNombre(char *nom){
  delete [] this->nombre;
  this->nombre=new char[strlen(nom)+1];
  strcpy(this->nombre, nom);
}

void Cliente::ver(){
  cout << nombre << " (" << dni << " - " << fechaAlta << ")"; 
}

ostream& operator<<(ostream &s, const Cliente &c){ //cout << c;
  s << c.getNombre() << "  (" << c.getDni() << " " << c.getFecha() << ")" << endl;
  return s;
}


