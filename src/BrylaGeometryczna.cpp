


#include "BrylaGeometryczna.hh"


#define PLIK_ROBOCZY__DRON1_KORPUS  "dat/PlikRoboczy_Dron1_Korpus.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR1  "dat/PlikRoboczy_Dron1_Rotor1.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR2  "dat/PlikRoboczy_Dron1_Rotor2.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR3  "dat/PlikRoboczy_Dron1_Rotor3.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR4  "dat/PlikRoboczy_Dron1_Rotor4.dat"

#define PLIK_ROBOCZY__DRON2_KORPUS  "dat/PlikRoboczy_Dron2_Korpus.dat"
#define PLIK_ROBOCZY__DRON2_ROTOR1  "dat/PlikRoboczy_Dron2_Rotor1.dat"
#define PLIK_ROBOCZY__DRON2_ROTOR2  "dat/PlikRoboczy_Dron2_Rotor2.dat"
#define PLIK_ROBOCZY__DRON2_ROTOR3  "dat/PlikRoboczy_Dron2_Rotor3.dat"
#define PLIK_ROBOCZY__DRON2_ROTOR4  "dat/PlikRoboczy_Dron2_Rotor4.dat"


#define PLIK_WLASCIWY__DRON1_KORPUS  "dat/PlikWlasciwy_Dron1_Korpus.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR1  "dat/PlikWlasciwy_Dron1_Rotor1.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR2  "dat/PlikWlasciwy_Dron1_Rotor2.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR3  "dat/PlikWlasciwy_Dron1_Rotor3.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR4  "dat/PlikWlasciwy_Dron1_Rotor4.dat"

#define PLIK_WLASCIWY__DRON2_KORPUS  "dat/PlikWlasciwy_Dron2_Korpus.dat"
#define PLIK_WLASCIWY__DRON2_ROTOR1  "dat/PlikWlasciwy_Dron2_Rotor1.dat"
#define PLIK_WLASCIWY__DRON2_ROTOR2  "dat/PlikWlasciwy_Dron2_Rotor2.dat"
#define PLIK_WLASCIWY__DRON2_ROTOR3  "dat/PlikWlasciwy_Dron2_Rotor3.dat"
#define PLIK_WLASCIWY__DRON2_ROTOR4  "dat/PlikWlasciwy_Dron2_Rotor4.dat"



Wektor3D BrylaGeometryczna::Skaluj(const Wektor3D& Wierz)const
{
    Wektor3D Nowy_Wierz;
    Nowy_Wierz=Wierz*Skala;
    return Nowy_Wierz;
}

Wektor3D& BrylaGeometryczna::StworzSkale(Wektor3D skala)
{
    Skala=skala;
    return Skala;
}

const std::string& BrylaGeometryczna::WezNazwePliku_BrylaWzorcowa()const
{
    return NazwaPliku_BrylaWzorcowa;
}
const std::string&  BrylaGeometryczna::WezNazwePliku_BrylaFinalna()const
{
    return NazwaPliku_BrylaFinalna;
}
void BrylaGeometryczna::NazwaplikuW(int nazwa,int ktory)
{
    if(nazwa==0)
    {
        if(ktory==0)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON1_KORPUS;
        }   
        if(ktory==1)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON1_ROTOR1;
        }
        if(ktory==2)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON1_ROTOR2;
        }
        if(ktory==3)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON1_ROTOR3;
        }
        if(ktory==4)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON1_ROTOR4;
        }
    }
    else
    {
        if(ktory==0)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON2_KORPUS;
        }
        if(ktory==1)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON2_ROTOR1;
        }
        if(ktory==2)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON2_ROTOR2;
        }
        if(ktory==3)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON2_ROTOR3;
        }
        if(ktory==4)
        {
            this->NazwaPliku_BrylaWzorcowa=PLIK_ROBOCZY__DRON2_ROTOR4;
        }
    }
}
void BrylaGeometryczna::NazwaplikuF(int nazwa,int ktory)
{
    if(nazwa==0)
    {
        if(ktory==0)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON1_KORPUS;
        }
        if(ktory==1)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON1_ROTOR1;
        }
        if(ktory==2)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON1_ROTOR2;
        }
        if(ktory==3)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON1_ROTOR3;
        }
        if(ktory==4)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON1_ROTOR4;
        }
    }
    else
    {
        if(ktory==0)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON2_KORPUS;
        }
        if(ktory==1)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON2_ROTOR1;
        }
        if(ktory==2)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON2_ROTOR2;
        }
        if(ktory==3)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON2_ROTOR3;
        }
        if(ktory==4)
        {
            this->NazwaPliku_BrylaFinalna=PLIK_WLASCIWY__DRON2_ROTOR4;
        }
    }
}