#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>


/*!
 * \file
 * \brief Ten plik zawiera definicję szablonu Wektor<>
 */


/*!
 * \brief Ogólny szablon Wektor<>
 * 
 *  Modeluje pojęcie wektora o dowolnej wielkości
 *  i jakie ma glowne cechy.
 */
template <int Wymiar>
class Wektor {
   double _Wsp[Wymiar]; 
  public:
   Wektor()
   {
    int i;
    for(i=0;i<Wymiar;++i)
      _Wsp[i]=0;
   }
   Wektor(double x)
   {
    int i;
    for(i=0;i<Wymiar;++i)
      _Wsp[i]=x;
   }
   double operator [](unsigned int index) const
   {
    if(index>=Wymiar)
    {
      std::cerr << "Zly wybor parametrow" << std::endl;
      //assert(index>=Wymiar);
      return _Wsp[index];
    }
    else
      return _Wsp[index];
   }
   double& operator [](unsigned int index)
   {
    if(index>=Wymiar)
    {
      //std::cerr << "Zly wybor parametrow" << std::endl;
      //assert(index>=Wymiar);
      return _Wsp[index];
    }
    else
      return _Wsp[index];
   }
   Wektor operator+ (Wektor vec) const;
   Wektor operator- (Wektor vec) const;
   Wektor operator* (Wektor vec) const;
   bool operator== (Wektor vec) const;   
};

template <int Wymiar>
Wektor<Wymiar> Wektor<Wymiar>::operator+ (Wektor<Wymiar> vec) const
{
  int i;
  Wektor<Wymiar> newvec;
  for(i=0;i<Wymiar;++i)
  {
    newvec._Wsp[i]=vec._Wsp[i]+this->_Wsp[i];
  }
  return newvec;
}

template <int Wymiar>
Wektor<Wymiar> Wektor<Wymiar>::operator- (Wektor<Wymiar> vec) const
{
  int i;
  Wektor<Wymiar> newvec;
  for(i=0;i<Wymiar;++i)
  {
    newvec._Wsp[i]=this->_Wsp[i]-vec._Wsp[i];
  }
  return newvec;
}

template <int Wymiar>
Wektor<Wymiar> Wektor<Wymiar>::operator* (Wektor<Wymiar> vec) const
{
  int i;
  Wektor<Wymiar> newvec;
  for(i=0;i<Wymiar;++i)
  {
    newvec._Wsp[i]=vec._Wsp[i]*this->_Wsp[i];
  }
  return newvec;
}

template <int Wymiar>
bool Wektor<Wymiar>::operator== (Wektor<Wymiar> vec) const
{
  int i;
  for(i=0;i<Wymiar;++i)
  {
    if(this->_Wsp[i]!=vec[i])
      return false;
  }
  return true;
}

/*!
 * \brief Przeciążenie jako szablon operatora >>
 *
 * Wypisuje elementy skladowe wektora
 * Przyjmuje:
 *  \param[in] Strm& referencje do strumienia gdzie chcemy wypisywac
 *  \param[in] Wek& referencje do szablonu wektora o zadanym wymiarze
 *  Zwraca:
 *  \retval Strumien wyjsciowy
 */
template <int Wymiar>
inline
std::istream& operator >> (std::istream &Strm, Wektor<Wymiar> &Wek)
{
  int i;
  i=0;
  while(i!=Wymiar)
  {
    Strm >> Wek[i];
    i=i+1;
  }
  return Strm;
}

/*!
 * \brief Przeciążenie jako szablon operatora >>
 *
 * Wczytuje elementy składowe wektora ze strumienia
 * Przyjmuje:
 *  \param[in] Strm& referencje do strumienia gdzie chcemy wczytywac
 *  \param[in] Wek& referencje do szablonu wektora o zadanym wymiarze
 *  Zwraca:
 *  \retval Strumien wejsciowy
 */
template <int Wymiar>
inline
std::ostream& operator << (std::ostream &Strm, const Wektor<Wymiar> &Wek)
{
  int i;
  i=0;
  while(i!=Wymiar)
  {
    Strm << Wek[i];
    Strm << " ";
    i=i+1;
  }
  return Strm;  
}

#endif
