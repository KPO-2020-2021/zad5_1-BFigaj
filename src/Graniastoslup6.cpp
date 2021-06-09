#include "Graniastoslup6.hh"



Wektor3D Graniastoslup6::TransfDoUklWspRodzica(const Wektor3D& Wierz)const
{
    Wektor3D Nowe_polozenie;
    Macierz3x3 mtx;
    rotmtxz(KatOrientacji_stopnie,mtx);
    Nowe_polozenie=(Wierz*mtx)+Polozenie;
    return Nowe_polozenie;
}

Wektor3D& Graniastoslup6::polozenie(int index,const Wektor3D polozenieD)
{
    Wektor3D transR1,transR2,transR3,transR4;
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
    if(index==0)
        Polozenie=polozenieD+transR1;
    if(index==1)
        Polozenie=polozenieD+transR2;
    if(index==2)
        Polozenie=polozenieD+transR3;
    if(index==3)
        Polozenie=polozenieD+transR4;
    return Polozenie;
}