#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include "Prostopadloscian.hh"
using namespace std;

/*!
 *  \file
 *  \brief W tym pliku zdefiniowane sa funkcje i metody związane z klasą prostopadłościan
 */


/*!
 *  \brief Konstruktor bezparametryczny prostopadłoscianu
 * 
 *  Tworzy Prostopadłoscian w zależności od długości boków
 *  i gdzie pierwszy punkt leży na środku układu współrzędnych
 */
/*
Prostopadloscian::Prostopadloscian(Wektor3D polozenieD)
{
    Wektor3D skala;
    skala[0]=10;
    skala[1]=8;
    skala[2]=4;
    Polozenie=polozenieD;
    Polozenie[2]+=2;
    StworzSkale(skala);
    KatOrientacji_stopnie=0;

}*/
Wektor3D Prostopadloscian::TransfDoUklWspRodzica(const Wektor3D& Wierz)const
{
    Wektor3D Nowe_polozenie;
    Macierz3x3 mtx;
    rotmtxz(KatOrientacji_stopnie,mtx);
    Nowe_polozenie=(Wierz*mtx)+Polozenie;
    return Nowe_polozenie;
}

Wektor3D& Prostopadloscian::polozenie(const Wektor3D polozenieD)
{
    Wektor3D trans;
    trans[2]=2;
    Polozenie=polozenieD+trans;
    return Polozenie;
}