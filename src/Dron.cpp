
#include <iostream>
#include <fstream>

#include "Dron.hh"

#define PLIK_TRASY_PRZELOTU "dat/trasa_przelotu.dat"
#define PLIK_ROBOCZY__DRON1_KORPUS  "dat/PlikRoboczy_Dron1_Korpus.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR1  "dat/PlikRoboczy_Dron1_Rotor1.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR2  "dat/PlikRoboczy_Dron1_Rotor2.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR3  "dat/PlikRoboczy_Dron1_Rotor3.dat"
#define PLIK_ROBOCZY__DRON1_ROTOR4  "dat/PlikRoboczy_Dron1_Rotor4.dat"


#define PLIK_WLASCIWY__DRON1_KORPUS  "dat/PlikWlasciwy_Dron1_Korpus.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR1  "dat/PlikWlasciwy_Dron1_Rotor1.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR2  "dat/PlikWlasciwy_Dron1_Rotor2.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR3  "dat/PlikWlasciwy_Dron1_Rotor3.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR4  "dat/PlikWlasciwy_Dron1_Rotor4.dat"
using namespace std;

void Dron::KtoryDron(int i)
{
  this->i=i;
  if(i==0)
  {
    Polozenie[0]=20;
    Polozenie[1]=20;
    Polozenie[2]=0;
  }
  if(i==1)
  {
    Polozenie[0]=80;
    Polozenie[1]=40;
    Polozenie[2]=0;
  }
}

void Dron::PlanujPoczatkowaSciezke(double KatSkretu_stopnie,
                              double DlugoscLotu,
                              Wektor3D Przemieszczenie,
                              PzG::LaczeDoGNUPlota& Lacze)
{
  Wektor3D prawdziwepolozenie;
  ofstream StrmWy(PLIK_TRASY_PRZELOTU);

  if (!StrmWy.is_open()) {
    cerr << endl
	 << " Nie mozna otworzyc do zapisu pliku: " << PLIK_TRASY_PRZELOTU << endl
	 << endl;
  }
  prawdziwepolozenie=Polozenie;
  if(Przemieszczenie[2]==0)
  {
    StrmWy << prawdziwepolozenie[0] << " " << prawdziwepolozenie[1]<< " " << prawdziwepolozenie[2] << " " << endl
    << prawdziwepolozenie[0] << " " << prawdziwepolozenie[1]<< " " << prawdziwepolozenie[2]+DlugoscLotu << " " << endl;
    prawdziwepolozenie=prawdziwepolozenie+Przemieszczenie;
    StrmWy << prawdziwepolozenie[0] << " " << prawdziwepolozenie[1]<< " " << prawdziwepolozenie[2]+DlugoscLotu << " " << endl
    << prawdziwepolozenie[0] << " " << prawdziwepolozenie[1]<< " " << prawdziwepolozenie[2] << " " << endl;
    Lacze.DodajNazwePliku(PLIK_TRASY_PRZELOTU);
  }
  KatOrientacji_stopnie=KatSkretu_stopnie;
  
}

bool /*const*/ Dron::Oblicz_i_Zapisz_WspGlbDrona()
{
  KorpusDrona.polozenie(Polozenie);
  if(!Oblicz_i_Zapisz_WspGlbKorpusu())
  {
    cerr << ":(  Operacja obliczania i zapisywania wspolrzednych globalnych korpusu nie powiodla sie." << endl;
    return false;
  }
  for(unsigned int j=0;j<4;++j)
  {
    RotorDrona[j].polozenie(j,Polozenie);
    if(!Oblicz_i_Zapisz_WspGlbRotora(RotorDrona[j],j))
    {
      cerr << ":(  Operacja obliczania i zapisywania wspolrzednych globalnych rotora nie powiodla sie." << endl;
      return false;
    }
  }
  return true;
}

bool /*const*/ Dron::Oblicz_i_Zapisz_WspGlbKorpusu()
{
  Wektor3D vec;
  ofstream  Strumien_plikowy_wy;
  ifstream Strumien_plikowy_wej;
  int LicznikWierzcholkow;
  KorpusDrona.StworzSkale(0)=10;
  KorpusDrona.StworzSkale(1)=8;
  KorpusDrona.StworzSkale(2)=4;
  KorpusDrona.NazwaplikuW(i,0);
  KorpusDrona.NazwaplikuF(i,0);
  Strumien_plikowy_wej.open(KorpusDrona.WezNazwePliku_BrylaWzorcowa());
  if (!Strumien_plikowy_wej.is_open())  {
    cerr << ":(  Operacja otwarcia do wczytania korupusu \"" << KorpusDrona.WezNazwePliku_BrylaWzorcowa() 
    << "\"" << endl << ":(  nie powiodla sie." << endl;
    return false;
  }
  Strumien_plikowy_wy.open(KorpusDrona.WezNazwePliku_BrylaFinalna());
  if (!Strumien_plikowy_wy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << KorpusDrona.WezNazwePliku_BrylaFinalna() 
    << "\"" << endl << ":(  nie powiodla sie." << endl;
    return false;
  }
  while (!Strumien_plikowy_wej.fail()) 
  {
    LicznikWierzcholkow=0;
    for(;LicznikWierzcholkow<4;++LicznikWierzcholkow)
    {
      Strumien_plikowy_wej >> vec;
      KorpusDrona.Skaluj(vec);
      cout <<"po skalowaniu korp"<< vec << endl;
      KorpusDrona.TransfDoUklWspRodzica(vec);
      cout <<"po rot.trans korp"<< vec << endl;
      vec=TransfDoUklWspRodzica(vec);
      cout <<"po trans korp"<< vec << endl;
      Strumien_plikowy_wy << vec << endl;
    }
    Strumien_plikowy_wy << endl;
  }
  Strumien_plikowy_wej.close();
  Strumien_plikowy_wy.close();
  return true;
}

bool Dron::Oblicz_i_Zapisz_WspGlbRotora(const Graniastoslup6& Rotor,int k)
{
  Wektor3D vec;
  ofstream  Strumien_plikowy_wy;
  ifstream Strumien_plikowy_wej;
  int LicznikWierzcholkow;
  RotorDrona[k].StworzSkale(0)=8;
  RotorDrona[k].StworzSkale(1)=8;
  RotorDrona[k].StworzSkale(2)=2;
  RotorDrona[k].NazwaplikuW(i,k+1);
  RotorDrona[k].NazwaplikuF(i,k+1);
  Strumien_plikowy_wej.open(Rotor.WezNazwePliku_BrylaWzorcowa());
  if (!Strumien_plikowy_wej.is_open())  {
    cerr << ":(  Operacja otwarcia do wczytania rotora" << Rotor.WezNazwePliku_BrylaWzorcowa() 
    << "" << endl << ":(  nie powiodla sie." << endl;
    return false;
  }
  
  Strumien_plikowy_wy.open(Rotor.WezNazwePliku_BrylaFinalna());
  if (!Strumien_plikowy_wy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << Rotor.WezNazwePliku_BrylaFinalna() 
    << "\"" << endl << ":(  nie powiodla sie." << endl;
    return false;
  }
  while (!Strumien_plikowy_wej.fail()) 
  {
    LicznikWierzcholkow=0;
    for(;LicznikWierzcholkow<4;++LicznikWierzcholkow)
    {
      Strumien_plikowy_wej >> vec;
      /*Rotor.Skaluj(vec);
      cout <<"po skalowaniu rotora"<< vec << endl;
      Rotor.TransfDoUklWspRodzica(vec);
      cout <<"po rot.trans rotora"<< vec << endl;*/
      vec=TransfDoUklWspRodzica(vec);
      cout <<"po trans rotora"<< vec << endl;
      Strumien_plikowy_wy << vec << endl;
    }
    Strumien_plikowy_wy << endl;
  }
  Strumien_plikowy_wej.close();
  Strumien_plikowy_wy.close();
  return true;
}

bool Dron::WykonajPionowyLot(double DlugoscLotu,PzG::LaczeDoGNUPlota& Lacze)
{
  if(Polozenie[2]==0)
  {
    cout << endl << "Wznoszenie ... " << endl;
    cout << Polozenie;
    for (; Polozenie[2] < DlugoscLotu; Polozenie[2] += 2)
    {
      cout << Polozenie<< endl;
      if (!TworzDrona()) return false;
      usleep(100000); // 0.1 ms
      Lacze.Rysuj();

    }
    return true;
  }
  else if(Polozenie[2]==DlugoscLotu)
  {
    cout << endl << "Ladowanie ... " << endl;
    for (; Polozenie[2] >= 0; Polozenie[2] -= 2)
    {
      if (!TworzDrona()) return false;
      usleep(100000); // 0.1 ms
      Lacze.Rysuj();

    }
    return true;
  }
  return false;
}

bool Dron::WykonajPoziomyLot(double DlugoscLotu,Wektor3D Przemieszczenie,PzG::LaczeDoGNUPlota& Lacze)
{
  cout << Polozenie[2] <<"==?" << DlugoscLotu << endl;
  if(Polozenie[2]==DlugoscLotu)
  {
    cout << endl << "Lot do miejsca docelowego ... " << endl;
    for (double i=0;i<=Przemieszczenie[0];i=i+(Przemieszczenie[0]/10))
    {
      for (double i=0;i<=Przemieszczenie[1];i=i+(Przemieszczenie[1]/10))
      {
        Polozenie[0]=Polozenie[0]+(Przemieszczenie[0]/10);
        Polozenie[1]=Polozenie[1]+(Przemieszczenie[1]/10);
        if (!TworzDrona()) return false;
        usleep(100000); // 0.1 ms
        Lacze.Rysuj();
      }
    }
    return true;
  }
  cerr << "Nie poprawna wysokosc lotu" << endl;
  return false;
}

Wektor3D Dron::TransfDoUklWspRodzica(const Wektor3D& Wierz)const
{
    Wektor3D Nowe_polozenie;
    Macierz3x3 mtx;
    mtx=rotmtxz(KatOrientacji_stopnie,mtx);
    Nowe_polozenie=(Wierz*mtx)+Polozenie;
    return Nowe_polozenie;
}

bool Dron::TworzKorpus(Wektor3D trans)
{
#define  SKALA_KORPUSU  10,8,4
  Wektor3D vec,skala;
  Wektor3D Nowe_polozenie;
  Macierz3x3 mtx;
  ofstream  Strumien_plikowy_wy,Strumien_plikowy_wy2;
  ifstream Strumien_plikowy_wej;
  skala[0]=10;
  skala[1]=8;
  skala[2]=4;
  KorpusDrona.NazwaplikuW(i,0);
  KorpusDrona.NazwaplikuF(i,0);
  Strumien_plikowy_wej.open("bryly_wzorcowe/szescian.dat");
  if (!Strumien_plikowy_wej.is_open())  {
    cerr << ":(  Operacja otwarcia do wczytania szescianu" 
    << "" << endl << ":(  nie powiodla sie." << endl;
    return false;
  }
  
  Strumien_plikowy_wy.open(KorpusDrona.WezNazwePliku_BrylaWzorcowa());
  if (!Strumien_plikowy_wy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu korpusu \"" 
    << "\"" << endl << ":(  nie powiodla sie." << endl;
    return false;
  }
  Strumien_plikowy_wy2.open(KorpusDrona.WezNazwePliku_BrylaFinalna());
  if (!Strumien_plikowy_wy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu korpusu \"" 
    << "\"" << endl << ":(  nie powiodla sie." << endl;
    return false;
  }
  Strumien_plikowy_wej >> vec;
  mtx=rotmtxz(KatOrientacji_stopnie,mtx);
  while(!Strumien_plikowy_wej.fail()) 
  {
    for(unsigned int k=0;k<4;++k)
    {
      
      Nowe_polozenie=((vec*mtx)*skala)+Polozenie+trans;
      Strumien_plikowy_wy << Nowe_polozenie << endl;
      Strumien_plikowy_wy2 << Nowe_polozenie << endl;
      Strumien_plikowy_wej >> vec;
    }
    Strumien_plikowy_wy << endl;
    Strumien_plikowy_wy2<< endl;
  }
  Strumien_plikowy_wej.close();
  Strumien_plikowy_wy.close();
  return true;
}

bool Dron::TworzRotor(int j,Wektor3D trans)
{
#define  SKALA_ROTORA  8,8,2  
 Wektor3D vec,skala;
  Wektor3D Nowe_polozenie;
  Macierz3x3 mtx;
  ofstream  Strumien_plikowy_wy,Strumien_plikowy_wy2;
  ifstream Strumien_plikowy_wej;
  skala[0]=8;
  skala[1]=8;
  skala[2]=2;
  RotorDrona[j].NazwaplikuW(i,j+1);
  RotorDrona[j].NazwaplikuF(i,j+1);
  Strumien_plikowy_wej.open("bryly_wzorcowe/graniastoslup6.dat");
  if (!Strumien_plikowy_wej.is_open())  {
    cerr << ":(  Operacja otwarcia do wczytania graniastoslup6" 
    << "" << endl << ":(  nie powiodla sie." << endl;
    return false;
  }
  
  Strumien_plikowy_wy.open(RotorDrona[j].WezNazwePliku_BrylaWzorcowa());
  if (!Strumien_plikowy_wy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu rotora \"" 
    << "\"" << endl << ":(  nie powiodla sie." << endl;
    return false;
  }
  Strumien_plikowy_wy2.open(RotorDrona[j].WezNazwePliku_BrylaFinalna());
  if (!Strumien_plikowy_wy.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu korpusu \"" 
    << "\"" << endl << ":(  nie powiodla sie." << endl;
    return false;
  }
  Strumien_plikowy_wej >> vec;
  mtx=rotmtxz(KatOrientacji_stopnie,mtx);
  while(!Strumien_plikowy_wej.fail()) 
  {
    for(unsigned int k=0;k<4;++k)
    {
      
      Nowe_polozenie=((vec*mtx)*skala)+Polozenie+trans;
      Strumien_plikowy_wy << Nowe_polozenie << endl;
      Strumien_plikowy_wy2 << Nowe_polozenie << endl;
      Strumien_plikowy_wej >> vec;
    }
    Strumien_plikowy_wy << endl;
    Strumien_plikowy_wy2<< endl;
  }
  Strumien_plikowy_wej.close();
  Strumien_plikowy_wy.close();
  return true;
}
bool Dron::TworzDrona()
{
  Wektor3D transKor,transR1,transR2,transR3,transR4;
  transKor[2]=2;
  transR1[0]=5;
  transR1[1]=4;
  transR1[2]=5;
  transR2[0]=5;
  transR2[1]=-4;
  transR2[2]=5;
  transR3[0]=-5;
  transR3[1]=4;
  transR3[2]=5;
  transR4[0]=-5;
  transR4[1]=-4;
  transR4[2]=5;

  if (!TworzKorpus(transKor)) return false;

  if (!TworzRotor(0,transR1)) return false;
  if (!TworzRotor(1,transR2)) return false;
  if (!TworzRotor(2,transR3)) return false;
  if (!TworzRotor(3,transR4)) return false;
  return true;
}