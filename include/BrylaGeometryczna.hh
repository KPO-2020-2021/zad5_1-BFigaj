#ifndef BRYLAGEOMETRYCZNA_HH
#define BRYLAGEOMETRYCZNA_HH


#include <iostream>
#include "Wektor3D.hh"


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
  Wektor3D Skaluj(const Wektor3D& Wierz)const;
  const std::string& WezNazwePliku_BrylaWzorcowa()const;
  const std::string& WezNazwePliku_BrylaFinalna()const;
  
};

#endif