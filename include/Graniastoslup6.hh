#ifndef GRANIASTOSLUP6_HH
#define GRANIASTOSLUP6_HH


#include <iostream>
#include "BrylaGeometryczna.hh"

/*!
 *  \file 
 *  \brief Ten plik zawiera diefinicje klasy Prostopadłościan
 *   
 *  Klasa składa się z 8 punktów które są traktowane jako zmienne
 *  Wektor3D dzieki czemu łatwo można tymi punktami manipulować
 *  dodatkowo przetrzymywana jest Macierz3x3 do operacji takich jak
 *  rotacja
 */
class Graniastoslup6:public BrylaGeometryczna{
  Wektor3D Polozenie;
  double KatOrientacji_stopnie;
  
  public:
  Wektor3D TransfDoUklWspRodzica(const Wektor3D& Wierz)const;
  Wektor3D& polozenie(int index,const Wektor3D polozenieD);
};


#endif