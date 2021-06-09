#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <unistd.h>
#include "Scena.hh"




#define PLIK_WLASCIWY__DRON1_KORPUS  "dat/PlikWlasciwy_Dron1_Korpus.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR1  "dat/PlikWlasciwy_Dron1_Rotor1.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR2  "dat/PlikWlasciwy_Dron1_Rotor2.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR3  "dat/PlikWlasciwy_Dron1_Rotor3.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR4  "dat/PlikWlasciwy_Dron1_Rotor4.dat"
using namespace std;

int main()
{
  Scena Scena;
  PzG::LaczeDoGNUPlota  Lacze;
  char wybor[2]=" ";
  int i;
  Lacze.DodajNazwePliku("bryly_wzorcowe/plaszczyzna.dat");
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON1_KORPUS);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON1_ROTOR1);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON1_ROTOR2);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON1_ROTOR3);
  Lacze.DodajNazwePliku(PLIK_WLASCIWY__DRON1_ROTOR4);

  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(0, 200);
  Lacze.UstawZakresY(0, 200);
  Lacze.UstawZakresZ(0, 120);


  Lacze.UstawRotacjeXZ(64,65); // Tutaj ustawiany jest widok

  /*if (!PrzemiescDrona(0,20,20,0)) return 0;


  Lacze.Rysuj();        // Teraz powinno pojawic sie okienko gnuplota
                        // z rysunkiem, o ile istnieje plik "prostopadloscian1.pow"
  cout << "Nacisnij ENTER, aby pokazac sciezke przelotu drona " << flush;
  cin.ignore(10000,'\n');


  if (!DodajTrasePrzelotu(Lacze)) return 1;
  Lacze.Rysuj();


  cout << "Nacisnij ENTER, aby wykonac animacje lotu drona " << flush;
  cin.ignore(10000,'\n');
  if (!AnimacjaLotuDrona(Lacze)) return 1;

  cout << endl << "Nacisnij ENTER, aby usunac sciezke ... " << flush;
  cin.ignore(10000,'\n');

  Lacze.UsunNazwePliku(PLIK_TRASY_PRZELOTU);
  Lacze.Rysuj();
  
  cout << "Nacisnij ENTER, aby zakonczyc ... " << flush;
  cin.ignore(10000,'\n');*/
       
       while(wybor[0]!='E')/*Warunek zakonczenia programu*/
       {
              
              Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
              cout << "Jakiego Drona chcesz wybrac do przelotu" << endl;
              cout << "A - Dron Alfa" << endl;
              cout << "B - Dron Beta" << endl;
              cout << "E - Exit" << endl;
              cin >> wybor;
              switch(wybor[0])
              {
                     case 'A':i=0;
                     Scena.UstawLacze(Lacze);
                     Scena.WezAktywnegoDrona(i);
                     Scena.UzyjAktynegoDrona(i);
                     break;
                     case 'B':i=1;
                     Scena.UstawLacze(Lacze);
                     Scena.WezAktywnegoDrona(i);
                     Scena.UzyjAktynegoDrona(i);
                     break;
                     case 'E':
                     break;
                     default:cerr << "Nie poprawny wybor opcji";break;
       }
    }



}