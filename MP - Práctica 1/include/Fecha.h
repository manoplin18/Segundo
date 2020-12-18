#ifndef FECHA_H
#define FECHA_H

#include <iostream> //cin, cout

using namespace std;

class Fecha {
  int dia;
  int mes, anio;
public:
  Fecha(const int &dia = 0, const int &m = 0, const int &anio = 0);
//virtual ~Fecha();
//Fecha(const Fecha &f); 
  int getDia() const { return this->dia; }
  int getMes() const { return this->mes; }
  int getAnio() const { return this->anio; }
  void setFecha(const int &dia, const int &mes, const int &a);
  void ver() const;
  bool bisiesto() const;
  Fecha operator++();   //++f
  Fecha operator++(const int i); //f++
  Fecha operator+(const int &i); //f+5

  friend Fecha operator+(const int &i, const Fecha &f); //const por seguridad y & por velocidad
};

Fecha operator+(const int &i, const Fecha &f); //const por seguridad y & por velocidad
ostream& operator<<(ostream &s, const Fecha &f);

#endif // FECHA_H
