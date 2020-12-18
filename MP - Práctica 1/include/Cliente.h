#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream> //cin, cout
#include "Fecha.h"

using namespace std;

class Cliente {
  long int dni;
  char *nombre;
  Fecha fechaAlta;
public:
  Cliente(long int d, char *nom, Fecha f); 
  virtual ~Cliente(); 
  Cliente& operator=(const Cliente& c); 

  long int getDni() const { return this->dni; } 
  const char* getNombre() const { return this->nombre; } 
  Fecha getFecha() const { return this->fechaAlta; }

  void setNombre(char *nom);
  void setFecha(Fecha f) { this->fechaAlta = f; }

  bool operator==(const Cliente &c) const; // if (c1 ===c2)
  void ver(); 

};

ostream& operator<<(ostream &s, const Cliente &c); //funcion no amiga de la clase

#endif // CLIENTE_H
