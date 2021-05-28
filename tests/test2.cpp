#include "doctest.h"
#include "Wektor3D.hh"
#include "Macierz3x3.hh"

TEST_CASE("Konstruktor bezparametryczny") {
    Wektor3D vec;
    CHECK(vec[0] == 0);
    CHECK(vec[1] == 0);
    CHECK(vec[2] == 0);
}



TEST_CASE("Konstruktor parametryczny") {
    Wektor3D vec(5);
    CHECK(vec[0] == 5);
    CHECK(vec[1] == 5);
    CHECK(vec[2] == 5);
}

TEST_CASE("Dodawanie i porownywanie") {
    Wektor3D vec,vek(4);
    Wektor3D v(4);
   CHECK(v == vec + vek);
}

TEST_CASE("Odejmowanie i porownywanie") {
    Wektor3D vec,vek(4);
    Wektor3D v(4);
   CHECK(v ==  vek - vec);
}
TEST_CASE("Operator[] z const i bez") {
    Wektor3D vec;
    vec[0]=1;
   CHECK(vec[0] == 1);
}
TEST_CASE("Operator* macierzy przez wektor z lewej") {
    Wektor3D vec(4),newvec;
    Macierz3x3 mtx(1);
    newvec=vec*mtx;
   CHECK(newvec[0] == 12);
   CHECK(newvec[1] == 12);
   CHECK(newvec[2] == 12);
}
