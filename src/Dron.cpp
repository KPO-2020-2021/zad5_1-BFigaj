
#include <iostream>
#include <fstream>

#include "Dron.hh"
using namespace std;

bool const Dron::Oblicz_i_Zapisz_WspGlbRotora(const Graniastoslup6& Rotor)
{
  ofstream  Strumien_plikowy;

  Strumien_plikowy.open(Rotor.WezNazwePliku_BrylaWzorcowa());
  if (!Strumien_plikowy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << Rotor.WezNazwePliku_BrylaWzorcowa() 
    << "\"" << endl << ":(  nie powiodla sie." << endl;
    return false;
  }
  
}