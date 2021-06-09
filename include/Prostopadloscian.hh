#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>
#include "BrylaGeometryczna.hh"

#define X_bok 100
#define Y_bok 50
#define Z_bok 50
/*!
 *  \file 
 *  \brief Ten plik zawiera diefinicje klasy Prostopadłościan
 *   
 *  Klasa składa się z 8 punktów które są traktowane jako zmienne
 *  Wektor3D dzieki czemu łatwo można tymi punktami manipulować
 *  dodatkowo przetrzymywana jest Macierz3x3 do operacji takich jak
 *  rotacja
 */
class Prostopadloscian:public BrylaGeometryczna{
  Wektor3D Polozenie;
  double KatOrientacji_stopnie;
  public:
  Wektor3D TransfDoUklWspRodzica(const Wektor3D& Wierz)const;
  Wektor3D& polozenie(const Wektor3D polozenieD);
};

#endif
