#ifndef BRYLAGEOMETRYCZNA_HH
#define BRYLAGEOMETRYCZNA_HH


#include <iostream>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"

/*!
 * \brief Klasa figury geometrycznej
 *
 *  Modeluje pojecie figury geometrycznej.
 */
class BrylaGeometryczna {
  std::string NazwaPliku_BrylaWzorcowa;
  std::string NazwaPliku_BrylaFinalna;
  Wektor3D Skala;
  public:
  double& StworzSkale(unsigned int i);
  Wektor3D Skaluj(const Wektor3D& Wierz)const;
  const std::string& WezNazwePliku_BrylaWzorcowa()const;
  const std::string& WezNazwePliku_BrylaFinalna()const;
  void NazwaplikuW(int nazwa,int ktory);
  void NazwaplikuF(int nazwa,int ktory);

};

#endif