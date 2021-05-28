


#include "BrylaGeometryczna.hh"


Wektor3D BrylaGeometryczna::Skaluj(const Wektor3D& Wierz)const
{
    Wektor3D Nowy_Wierz;
    Nowy_Wierz=Wierz*Skala;
    return Nowy_Wierz;
}

const std::string& BrylaGeometryczna::WezNazwePliku_BrylaWzorcowa()const
{
    return NazwaPliku_BrylaWzorcowa;
}
const std::string&  BrylaGeometryczna::WezNazwePliku_BrylaFinalna()const
{
    return NazwaPliku_BrylaWzorcowa;
}