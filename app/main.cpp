#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "lacze_do_gnuplota.hh"



using namespace std;

int main()
{
  int ile,i,opt=0;
  double kat;
  char wybor[2]=" ";
  char os[2]=" ";
  Wektor3D W1,W2;
  Macierz3x3 M1;
  Prostopadloscian             Pr;   // To tylko przykladowe definicje zmiennej
  PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("prostopadloscian.dat",PzG::RR_Ciagly,2);
   //
   //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy x,y,z.
   //
  Lacze.ZmienTrybRys(PzG::TR_3D);

   // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresY(-155,155);
  Lacze.UstawZakresX(-155,155);
  Lacze.UstawZakresZ(-155,155);


       while(wybor[0]!='e')/*Warunek zakonczenia programu*/
       {
              if (!filesave("prostopadloscian.dat",Pr)) return 1;
              Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
              cout << "Twoj wybor (m-menu) -";
              cin >> wybor;
              switch(wybor[0])
              {
                     case 'm':cout << "m - wyswietlenie menu" << endl 
                            << "o - obrot bryly o zadana sekwencje katow" << endl
                            << "p - przesuniecie  o zadany wektor" << endl
                            << "w - wyswietlenie wspolrzednych wierzcholkow" << endl
                            << "t - powtorzenie poprzedniego obrotu" << endl
                            << "r - wyswietlenie macierzy rotacji" << endl
                            << "s - sprawdzenie dlugosci przeciwleglych bokow" << endl
                            << "e - exit" << endl;
                     break;
                     case 'p':cout << "Wpisz wspolrzedne wectora " << endl;
                            cin >> W1;
                            Pr.przesunieciewektor(W1);
                     break;
                     case 'o':cout << "Ile razy ma sie dokonac operacja " << endl;
                            cin >> ile;
                            cout << "Podaj os (x,y,z)" << endl;
                            cin >> os;
                            if(*os=='x')
                                   opt=1;
                            if(*os=='y')
                                   opt=2;
                            if(*os=='z')
                                   opt=3;
                            cout << "Podaj kat" << endl;
                            cin >> kat;
                            for(i=1;i<=ile;++i)
                                   Pr.rotacja(kat,opt);
                     break;
                     case 'w':cout << Pr;
                     break;
                     case 't':if(opt!=0)
                                   {
                                       for(i=1;i<=ile;++i)
                                          Pr.rotacja(kat,opt); 
                                   }
                     break;
                     case 'r':if(opt==1)
                                   {
                                       M1=rotmtxx(kat,M1);
                                       cout << M1 << endl;
                                   }
                            if(opt==2)
                                   {
                                       M1=rotmtxy(kat,M1);
                                       cout << M1 << endl;
                                   }
                            if(opt==3)
                                   {
                                       M1=rotmtxz(kat,M1);
                                       cout << M1 << endl;
                                   }
                     break;
                     case 's':Pr.sprawdzeniebok();
                     break;
                     case 'e':
                     break;
                     default:cerr << "Nie poprawny wybor opcji";break;
       }
    }

}
