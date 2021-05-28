
#include "doctest.h"
#include "Macierz3x3.hh"
#include <math.h>

TEST_CASE("Konstruktor bezparametryczny ") {
    Macierz3x3 mtx;
    CHECK(mtx(0,0) == 0);
    CHECK(mtx(0,1) == 0);
    CHECK(mtx(0,2) == 0);
    CHECK(mtx(1,0) == 0);
    CHECK(mtx(1,1) == 0);
    CHECK(mtx(1,2) == 0);
    CHECK(mtx(2,0) == 0);
    CHECK(mtx(2,1) == 0);
    CHECK(mtx(2,2) == 0);
}



TEST_CASE("Konstruktor parametryczny czyli macierz obrotu") {
    Macierz3x3 mtx(4);
    double a=4;
    CHECK(mtx(0,0) == a);
    CHECK(mtx(0,1) == a);
    CHECK(mtx(0,2) == a);
    CHECK(mtx(1,0) == a);
    CHECK(mtx(1,1) == a);
    CHECK(mtx(1,2) == a);
    CHECK(mtx(2,0) == a);
    CHECK(mtx(2,1) == a);
    CHECK(mtx(2,2) == a);
}

TEST_CASE("Tworzenie macierzy rotacji ox") {
    Macierz3x3 mtx,xmtx;
    double katrad,angle=20;
    katrad=(angle*M_PI)/180;
    mtx(0,0)=1;
    mtx(0,1)=0;
    mtx(0,2)=0;
    mtx(1,0)=0;
    mtx(1,1)=cos(katrad);
    mtx(1,2)=(-sin(katrad));
    mtx(2,0)=0;
    mtx(2,1)=sin(katrad);
    mtx(2,2)=cos(katrad);
    xmtx=rotmtxx(angle,xmtx);
    CHECK(mtx(0,0) == xmtx(0,0));
    CHECK(mtx(0,1) == xmtx(0,1));
    CHECK(mtx(0,2) == xmtx(0,2));
    CHECK(mtx(1,0) == xmtx(1,0));
    CHECK(mtx(1,1) == xmtx(1,1));
    CHECK(mtx(1,2) == xmtx(1,2));
    CHECK(mtx(2,0) == xmtx(2,0));
    CHECK(mtx(2,1) == xmtx(2,1));
    CHECK(mtx(2,2) == xmtx(2,2));
}
TEST_CASE("Tworzenie macierzy rotacji oy") {
    Macierz3x3 mtx,ymtx;
    double katrad,angle=20;
    katrad=(angle*M_PI)/180;
    mtx(0,0)=cos(katrad);
    mtx(0,1)=0;
    mtx(0,2)=sin(katrad);
    mtx(1,0)=0;
    mtx(1,1)=1;
    mtx(1,2)=0;
    mtx(2,0)=(-sin(katrad));
    mtx(2,1)=0;
    mtx(2,2)=cos(katrad);
    ymtx=rotmtxy(angle,ymtx);
    CHECK(mtx(0,0) == ymtx(0,0));
    CHECK(mtx(0,1) == ymtx(0,1));
    CHECK(mtx(0,2) == ymtx(0,2));
    CHECK(mtx(1,0) == ymtx(1,0));
    CHECK(mtx(1,1) == ymtx(1,1));
    CHECK(mtx(1,2) == ymtx(1,2));
    CHECK(mtx(2,0) == ymtx(2,0));
    CHECK(mtx(2,1) == ymtx(2,1));
    CHECK(mtx(2,2) == ymtx(2,2));
}
TEST_CASE("Tworzenie macierzy rotacji oz") {
    Macierz3x3 mtx,zmtx;
    double katrad,angle=20;
    katrad=(angle*M_PI)/180;
    mtx(0,0)=cos(katrad);
    mtx(0,1)=(-sin(katrad));
    mtx(0,2)=0;
    mtx(1,0)=sin(katrad);
    mtx(1,1)=cos(katrad);
    mtx(1,2)=0;
    mtx(2,0)=0;
    mtx(2,1)=0;
    mtx(2,2)=1;
    zmtx=rotmtxz(angle,zmtx);
    CHECK(mtx(0,0) == zmtx(0,0));
    CHECK(mtx(0,1) == zmtx(0,1));
    CHECK(mtx(0,2) == zmtx(0,2));
    CHECK(mtx(1,0) == zmtx(1,0));
    CHECK(mtx(1,1) == zmtx(1,1));
    CHECK(mtx(1,2) == zmtx(1,2));
    CHECK(mtx(2,0) == zmtx(2,0));
    CHECK(mtx(2,1) == zmtx(2,1));
    CHECK(mtx(2,2) == zmtx(2,2));
}

TEST_CASE("Operator() z i bez const") {
    Macierz3x3 mtx;
    mtx(0,0)=4;
    mtx(0,1)=3;
    mtx(1,0)=2;
    mtx(1,1)=1;
    CHECK(mtx(0,0) == 4 );
    CHECK(mtx(0,1) == 3 );
    CHECK(mtx(1,0) == 2 );
    CHECK(mtx(1,1) == 1 );
}
