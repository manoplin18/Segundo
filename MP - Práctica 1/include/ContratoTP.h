#ifndef CONTRATOTP_H
#define CONTRATOTP_H

#include <iostream> //cin, cout
#include "Fecha.h"
#include "Contrato.h"

using namespace std;

class ContratoTP: public Contrato {
  static int minutosTP;
  static float precioTP;
  int minutosHablados;
  static const float precioExcesoMinutos;

public:
  ContratoTP(long int dni, Fecha f, int m);
  virtual ~ContratoTP() { minutosHablados = 0; }
  //ContratoTP(const ContratoTP& c);
  //ContratoTP& operator=(const ContratoTP& c);
  static int getLimiteMinutos() { return ContratoTP::minutosTP; }
  static float getPrecio() { return ContratoTP::precioTP; }
  static void setTarifaPlana(int m, float p);
  void ver() const;

  //-------Todo inline por ser poco codigo, para que sea mas eficiente-------------------
  float FacturaExcesoMinutos() const { if(this->ExcesoMinutos() > 0)
                                          return precioExcesoMinutos*this->ExcesoMinutos();
                                        else
                                          return 0;
                                      }
  float ExcesoMinutos() const { float exceso =  minutosHablados - minutosTP;
                                  return exceso;
                              }

  float factura() const { float factura = this->precioTP + this->FacturaExcesoMinutos();
                          return factura;}

  float factura(bool precio_fijo) const { return this->precioTP; } //bool solo para sobrecargar la funcion

  float getMinutosHablados() const { return minutosHablados;}

  void setMinutosHablados(int minutosHablados) { this->minutosHablados = minutosHablados;}
  friend ostream& operator<<(ostream &s, const ContratoTP &c);
  virtual void abstracto() const {;}

};

ostream& operator<<(ostream &s, const ContratoTP &c);

#endif // CONTRATOTP_H
