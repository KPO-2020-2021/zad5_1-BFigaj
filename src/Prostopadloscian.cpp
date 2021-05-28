#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include "Prostopadloscian.hh"
#define PRECISION 0.0000000001
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
Prostopadloscian::Prostopadloscian()
{
    /*Wieżchołki boku leżących na tym samym z*/
    p[0][0]=0;
    p[0][1]=0;
    p[0][2]=0;

    p[1][0]=0+X_bok;
    p[1][1]=0;
    p[1][2]=0;

    p[2][0]=0+X_bok;
    p[2][1]=0+Y_bok;
    p[2][2]=0;

    p[3][0]=0;
    p[3][1]=0+Y_bok;
    p[3][2]=0;
    /*Wieżchołki boku leżących na tym samym z*/
    p[4][0]=0;
    p[4][1]=0;
    p[4][2]=0+Z_bok;

    p[5][0]=0+X_bok;
    p[5][1]=0;
    p[5][2]=0+Z_bok;

    p[6][0]=0+X_bok;
    p[6][1]=0+Y_bok;
    p[6][2]=0+Z_bok;

    p[7][0]=0;
    p[7][1]=0+Y_bok;
    p[7][2]=0+Z_bok;
}

/*!
 *  \brief Konstruktor parametryczny prostopadłoscianu
 * 
 *  Tworzy Prostopadłoscian w zależności od długości boków
 *  i parametrów punktu początkowego
 *  Przyjmuje:
 *  \param[in] x liczba double
 *  \param[in] y liczba double
 *  \param[in] z liczba double
 */
Prostopadloscian::Prostopadloscian(double x, double y, double z)
{
    /*Wierzchołki boku leżące na tym samym z*/
    p[0][0]=x;
    p[0][1]=y;          //a
    p[0][2]=z;

    p[1][0]=x+X_bok;
    p[1][1]=y;          //b
    p[1][2]=z;

    p[2][0]=x+X_bok;
    p[2][1]=y+Y_bok;    //c
    p[2][2]=z;

    p[3][0]=x;
    p[3][1]=y+Y_bok;    //d
    p[3][2]=z;
    /*Wierzchołki boku leżące na tym samym z*/
    p[4][0]=x;
    p[4][1]=y;          //e
    p[4][2]=z+Z_bok;

    p[5][0]=x+X_bok;
    p[5][1]=y;          //f
    p[5][2]=z+Z_bok;

    p[6][0]=x+X_bok;
    p[6][1]=y+Y_bok;    //g
    p[6][2]=z+Z_bok;

    p[7][0]=x;
    p[7][1]=y+Y_bok;    //h
    p[7][2]=z+Z_bok;
}
/*!
 *  \brief Przeciążenie funkcji operatora[] dla Prostopadlościanu
 * 
 *  Funkcja zwraca wybrany wektor, który traktujemy jako punkt.
 *  Przyjmuje:
 *  \param[in] i index potrzebny do wyboru punktu
 *  Zwraca:
 *  \retval Wybrany punkt jako zmiena Wektor3D
 */
Wektor3D Prostopadloscian::operator[](unsigned int i)const
{
    Wektor3D cos;
    if(i==0)
        return p[i];
    if(i==1)
        return p[i];
    if(i==2)
        return p[i];
    if(i==3)
        return p[i];
    if(i==4)
        return p[i];
    if(i==5)
        return p[i];
    if(i==6)
        return p[i];
    if(i==7)
        return p[i];
    return cos;
}

/*!
 *  \brief Funkcja rotacji macierzy o zadany kont wzgledem jakies osi
 * 
 *  Wypełnia macierz3x3 czyli składowa prostokata 
 *  potrzebnymi danymi by powstała macierz obrotu
 *  Przyjmuje:
 *  \param[in] angle liczba double czytli kąt w stopniach
 *  \param[in] opt liczba int czytli odpowiedzialna za wybranie osi
 */
void Prostopadloscian::rotacja(double angle,unsigned int opt)
{
    unsigned int i;
    if(opt==1)
    {
        mtx=rotmtxx(angle,mtx);
        for(i=0;i<8;++i)
        {
            p[i]=p[i]*mtx;

        }
        
    }
    if(opt==2)
    {
        mtx=rotmtxy(angle,mtx);
        for(i=0;i<8;++i)
        {
            p[i]=p[i]*mtx;
            
        }
        
    }
    if(opt==3)
    {
        mtx=rotmtxz(angle,mtx);
        for(i=0;i<8;++i)
        {
            p[i]=p[i]*mtx;
            
        }
        
    }
}
/*!
 *  \brief Funkcja przesuniecia o wektor
 * 
 *  Funkcja zmienia współrzędne punktów prostopadłościanu
 *  dodajac do nich współrzędne wektora
 *  Przyjmuje:
 *  \param[in] vec wektor o który chcemy przesunąć figurę
 */
void Prostopadloscian::przesunieciewektor(Wektor3D vec)
{
    int i;
    for(i=0;i<8;++i)
    {
        p[i]=p[i]+(vec);
    }
}
/*!
 *  \brief Funkcja sprawdzajaca przeciwległe boki prostopadłościanu
 * 
 *  Funkcja oblicza boki z współrzędnych punktów prostopadłościanu
 *  a następnie sprawdza czy są równe nie sprawdza natomiast czy są 
 *  zgodne ze stanem początkowym
 */
bool Prostopadloscian::sprawdzeniebok() const
{
    int i;
    double ile=4;
    double bok,pbok,u=0;
    for (i=0;i<ile-1;++i)
    {
        bok=pow(pow((p[i][0]-p[i+1][0]),2)+pow((p[i][1]-p[i+1][1]),2)+pow((p[i][2]-p[i+1][2]),2),0.5);
        pbok=pow(pow((p[i+4][0]-p[i+5][0]),2)+pow((p[i+4][1]-p[i+5][1]),2)+pow((p[i+4][2]-p[i+5][2]),2),0.5);
        if(bok-pbok<0)
        {
            if(((bok-pbok)*(-1))>PRECISION)
            {
                cout << setw(16) << fixed << setprecision(10) << bok << "!=" 
                << setw(16) << fixed << setprecision(10) << pbok << endl;
                u=1;
            }
            else
            {
                cout << setw(16) << fixed << setprecision(10) << bok << "=" 
                << setw(16) << fixed << setprecision(10) << pbok << endl;
            }
        }
        else
        {
            if((bok-pbok)>PRECISION)
            {
                cout << setw(16) << fixed << setprecision(10) << bok << "!=" 
                << setw(16) << fixed << setprecision(10) << pbok << endl;
                u=1;
            }
            else
            {
                cout << setw(16) << fixed << setprecision(10) << bok << "=" 
                << setw(16) << fixed << setprecision(10) << pbok << endl;
            }
        }
    }

    
    bok=pow(pow((p[3][0]-p[0][0]),2)+pow((p[3][1]-p[0][1]),2)+pow((p[3][2]-p[0][2]),2),0.5);
    pbok=pow(pow((p[5][0]-p[6][0]),2)+pow((p[5][1]-p[6][1]),2)+pow((p[5][2]-p[6][2]),2),0.5);
    if(bok-pbok<0)
        {
            if(((bok-pbok)*(-1))>PRECISION)
            {
                cout << setw(16) << fixed << setprecision(10) << bok << "!=" 
                << setw(16) << fixed << setprecision(10) << pbok << endl;
                u=1;
            }
            else
            {
                cout << setw(16) << fixed << setprecision(10) << bok << "=" 
                << setw(16) << fixed << setprecision(10) << pbok << endl;
            }
        }
        else
        {
            if((bok-pbok)>PRECISION)
            {
                cout << setw(16) << fixed << setprecision(10) << bok << "!=" 
                << setw(16) << fixed << setprecision(10) << pbok << endl;
                u=1;
            }
            else
            {
                cout << setw(16) << fixed << setprecision(10) << bok << "=" 
                << setw(16) << fixed << setprecision(10) << pbok << endl;
            }
        }



    for (i=0;i<2;++i)
    {
        bok=pow(pow((p[i][0]-p[i+4][0]),2)+pow((p[i][1]-p[i+4][1]),2)+pow((p[i][2]-p[i+4][2]),2),0.5);
        pbok=pow(pow((p[i+2][0]-p[i+6][0]),2)+pow((p[i+2][1]-p[i+6][1]),2)+pow((p[i+2][2]-p[i+6][2]),2),0.5);
        if(bok-pbok<0)
        {
            if(((bok-pbok)*(-1))>PRECISION)
            {
                cout << setw(16) << fixed << setprecision(10) << bok << "!=" 
                << setw(16) << fixed << setprecision(10) << pbok << endl;
                u=1;
            }
            else
            {
                cout << setw(16) << fixed << setprecision(10) << bok << "=" 
                << setw(16) << fixed << setprecision(10) << pbok << endl;
            }
        }
        else
        {
            if((bok-pbok)>PRECISION)
            {
                cout << setw(16) << fixed << setprecision(10) << bok << "!=" 
                << setw(16) << fixed << setprecision(10) << pbok << endl;
                u=1;
            }
            else
            {
                cout << setw(16) << fixed << setprecision(10) << bok << "=" 
                << setw(16) << fixed << setprecision(10) << pbok << endl;
            }
        }
    }
    if(u==1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
/*!
 *  \brief Funkcja potrzebna do zapisu współrzędnych do pliku
 * 
 *  Funkcja wypisuje współrzędne punktów by były dobrze
 *  wyświetlane w gnuplocie
 *  Przyjmuje:
 *  \param[in] Strm  referencja do strumienia ostream
 *  \param[in] Pr Prostopadloscian, którego punkty wypisujemy
 *  Zwraca:
 *  \retval Strm 
 */
std::ostream& printtofile ( std::ostream       &Strm, 
                            const Prostopadloscian    &Pr)
{
    
    Strm << setw(16) << fixed << setprecision(10) << Pr[0][0] 
         << setw(16) << fixed << setprecision(10) << Pr[0][1] 
         << setw(16) << fixed << setprecision(10) << Pr[0][2] << endl;
    Strm << setw(16) << fixed << setprecision(10) << Pr[1][0] 
         << setw(16) << fixed << setprecision(10) << Pr[1][1] 
         << setw(16) << fixed << setprecision(10) << Pr[1][2] << endl;
    
    Strm << endl;

    Strm << setw(16) << fixed << setprecision(10) << Pr[3][0] 
         << setw(16) << fixed << setprecision(10) << Pr[3][1] 
         << setw(16) << fixed << setprecision(10) << Pr[3][2] << endl;
    Strm << setw(16) << fixed << setprecision(10) << Pr[2][0] 
         << setw(16) << fixed << setprecision(10) << Pr[2][1]
         << setw(16) << fixed << setprecision(10) << Pr[2][2] << endl;

    Strm << endl;

    Strm << setw(16) << fixed << setprecision(10) << Pr[7][0]
         << setw(16) << fixed << setprecision(10) << Pr[7][1]
         << setw(16) << fixed << setprecision(10) << Pr[7][2] << endl;
    Strm << setw(16) << fixed << setprecision(10) << Pr[6][0] 
         << setw(16) << fixed << setprecision(10) << Pr[6][1] 
         << setw(16) << fixed << setprecision(10) << Pr[6][2] << endl;

    Strm << endl;

    Strm << setw(16) << fixed << setprecision(10) << Pr[4][0]
         << setw(16) << fixed << setprecision(10) << Pr[4][1]
         << setw(16) << fixed << setprecision(10) << Pr[4][2] << endl;
    Strm << setw(16) << fixed << setprecision(10) << Pr[5][0]
         << setw(16) << fixed << setprecision(10) << Pr[5][1] 
         << setw(16) << fixed << setprecision(10) << Pr[5][2] << endl;

    Strm << endl;

    Strm << setw(16) << fixed << setprecision(10) << Pr[0][0] 
         << setw(16) << fixed << setprecision(10) << Pr[0][1] 
         << setw(16) << fixed << setprecision(10) << Pr[0][2] << endl;
    Strm << setw(16) << fixed << setprecision(10) << Pr[1][0] 
         << setw(16) << fixed << setprecision(10) << Pr[1][1] 
         << setw(16) << fixed << setprecision(10) << Pr[1][2] << endl;
    return Strm;
}


/*!
 *  \brief Przeciążenie operatora << by wypisywał Prostopadłościan
 * 
 *  Funkcja wypisuje współrzędne punktów by były dobrze
 *  wyświetlane 
 *  Przyjmuje:
 *  \param[in] Strm  referencja do strumienia ostream
 *  \param[in] Pr Prostopadloscian, którego punkty wypisujemy
 *  Zwraca:
 *  \retval Strm 
 */
std::ostream& operator << ( std::ostream       &Strm, 
                            const Prostopadloscian    &Pr)
{
    Strm << "Wspolrzedne punktow (x,y,z)" << endl;
    Strm << "A=(";
    Strm << setw(16) << fixed << setprecision(10) << Pr[0][0] << ","
         << setw(16) << fixed << setprecision(10) << Pr[0][1] << ","
         << setw(16) << fixed << setprecision(10) << Pr[0][2] << ")" << endl;
    Strm << "B=(";
    Strm << setw(16) << fixed << setprecision(10) << Pr[1][0] << ","
         << setw(16) << fixed << setprecision(10) << Pr[1][1] << ","
         << setw(16) << fixed << setprecision(10) << Pr[1][2] << ")" << endl;
    Strm << "C=(";
    Strm << setw(16) << fixed << setprecision(10) << Pr[2][0] << ","
         << setw(16) << fixed << setprecision(10) << Pr[2][1] << ","
         << setw(16) << fixed << setprecision(10) << Pr[2][2] << ")" << endl;
    Strm << "D=(";
    Strm << setw(16) << fixed << setprecision(10) << Pr[3][0] << ","
         << setw(16) << fixed << setprecision(10) << Pr[3][1] << ","
         << setw(16) << fixed << setprecision(10) << Pr[3][2] << ")" << endl;
    Strm << "E=(";
    Strm << setw(16) << fixed << setprecision(10) << Pr[4][0] << ","
         << setw(16) << fixed << setprecision(10) << Pr[4][1] << ","
         << setw(16) << fixed << setprecision(10) << Pr[4][2] << ")" << endl;
    Strm << "F=(";
    Strm << setw(16) << fixed << setprecision(10) << Pr[5][0] << ","
         << setw(16) << fixed << setprecision(10) << Pr[5][1] << ","
         << setw(16) << fixed << setprecision(10) << Pr[5][2] << ")" << endl;
    Strm << "G=(";
    Strm << setw(16) << fixed << setprecision(10) << Pr[6][0] << ","
         << setw(16) << fixed << setprecision(10) << Pr[6][1] << ","
         << setw(16) << fixed << setprecision(10) << Pr[6][2] << ")" << endl;
    Strm << "H=(";
    Strm << setw(16) << fixed << setprecision(10) << Pr[7][0] << ","
         << setw(16) << fixed << setprecision(10) << Pr[7][1] << ","
         << setw(16) << fixed << setprecision(10) << Pr[7][2] << ")" << endl;
    return Strm;
}

/*!
 *  \brief Funkcja zapisująca współrzędne Prostopadłoscianu do pliku
 * 
 *  Funkcja zapisuje do pliku współrzędne potrzebne do gnuplota
 *  Przyjmuje:
 *  \param[in] filename  referencja do strumienia ostream
 *  \param[in] Pr Prostopadloscian, którego punkty chcemy zapisać
 *  Zwraca:
 *  \retval true - jeśli się powiodło
 *  \retval false - jeśli się nie powiodło
 */
bool filesave(const char *filename,const Prostopadloscian &Pr )
{
  ofstream  filestrm;

  filestrm.open(filename);
  if (!filestrm.is_open())  {
    cerr << ":(  Operacja otwarcia do zapisu \"" << filename << "\"" << endl
	 << ":(  nie powiodla sie." << endl;
    return false;
  }

  printtofile(filestrm,Pr);

  filestrm.close();
  return !filestrm.fail();
}