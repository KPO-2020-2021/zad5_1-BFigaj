
#include "doctest.h"
#include "Prostopadloscian.hh"
#define PRECISION 0.0000000001

TEST_CASE("Konstruktor bezparametryczny"){
    Prostopadloscian Pr;
    double x,y,z;
    x=y=z=0;
    CHECK(Pr[0][0] == x);
    CHECK(Pr[0][1] == y);
    CHECK(Pr[0][2] == z);
    
    CHECK(Pr[1][0] == x+X_bok);
    CHECK(Pr[1][1] == y);
    CHECK(Pr[1][2] == z);
    
    CHECK(Pr[2][0] == x+X_bok);
    CHECK(Pr[2][1] == y+Y_bok);
    CHECK(Pr[2][2] == z);
    
    CHECK(Pr[3][0] == x);
    CHECK(Pr[3][1] == y+Y_bok);
    CHECK(Pr[3][2] == z);
    
    CHECK(Pr[4][0] == x);
    CHECK(Pr[4][1] == y);
    CHECK(Pr[4][2] == z+Z_bok);
    
    CHECK(Pr[5][0] == x+X_bok);
    CHECK(Pr[5][1] == y);
    CHECK(Pr[5][2] == z+Z_bok);
    
    CHECK(Pr[6][0] == x+X_bok);
    CHECK(Pr[6][1] == y+Y_bok);
    CHECK(Pr[6][2] == z+Z_bok);
    
    CHECK(Pr[7][0] == x);
    CHECK(Pr[7][1] == y+Y_bok);
    CHECK(Pr[7][2] == z+Z_bok);
    
    

}

TEST_CASE("Konstruktor parametryczny"){
    double x=5,y=10,z=5;
    Prostopadloscian Pr(x,y,z);
    CHECK(Pr[0][0] == x);
    CHECK(Pr[0][1] == y);
    CHECK(Pr[0][2] == z);
    
    CHECK(Pr[1][0] == x+X_bok);
    CHECK(Pr[1][1] == y);
    CHECK(Pr[1][2] == z);
    
    CHECK(Pr[2][0] == x+X_bok);
    CHECK(Pr[2][1] == y+Y_bok);
    CHECK(Pr[2][2] == z);
    
    CHECK(Pr[3][0] == x);
    CHECK(Pr[3][1] == y+Y_bok);
    CHECK(Pr[3][2] == z);
    
    CHECK(Pr[4][0] == x);
    CHECK(Pr[4][1] == y);
    CHECK(Pr[4][2] == z+Z_bok);
    
    CHECK(Pr[5][0] == x+X_bok);
    CHECK(Pr[5][1] == y);
    CHECK(Pr[5][2] == z+Z_bok);
    
    CHECK(Pr[6][0] == x+X_bok);
    CHECK(Pr[6][1] == y+Y_bok);
    CHECK(Pr[6][2] == z+Z_bok);
    
    CHECK(Pr[7][0] == x);
    CHECK(Pr[7][1] == y+Y_bok);
    CHECK(Pr[7][2] == z+Z_bok);
}


TEST_CASE("Translacja wektora"){
    Prostopadloscian Pr;
    double x,y,z,a=2;
    Wektor3D vec(a);
    Pr.przesunieciewektor(vec);
    x=y=z=0;
    CHECK(Pr[0][0]-(x+a)<PRECISION);
    CHECK(Pr[0][1]-(y+a)<PRECISION);
    CHECK(Pr[0][2]-(z+a)<PRECISION);
    
    CHECK(Pr[1][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[1][1]-(y+a)<PRECISION);
    CHECK(Pr[1][2]-(z+a)<PRECISION);
    
    CHECK(Pr[2][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[2][1]-(y+Y_bok+a)<PRECISION);
    CHECK(Pr[2][2]-(z+a)<PRECISION);
    
    CHECK(Pr[3][0]-(x+a)<PRECISION);
    CHECK(Pr[3][1]-(y+Y_bok+a)<PRECISION);
    CHECK(Pr[3][2]-(z+a)<PRECISION);
    
    CHECK(Pr[4][0]-(x+a)<PRECISION);
    CHECK(Pr[4][1]-(y+a)<PRECISION);
    CHECK(Pr[4][2]-(z+Z_bok+a)<PRECISION);
    
    CHECK(Pr[5][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[5][1]-(y+a)<PRECISION);
    CHECK(Pr[5][2]-(z+Z_bok+a)<PRECISION);
    
    CHECK(Pr[6][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[6][1]-(y+Y_bok+a)<PRECISION);
    CHECK(Pr[6][2]-(z+Z_bok+a)<PRECISION);
    
    CHECK(Pr[7][0]-(x+a)<PRECISION);
    CHECK(Pr[7][1] -(y+Y_bok+a)<PRECISION);
    CHECK(Pr[7][2] -(z+Z_bok+a)<PRECISION);
}

TEST_CASE("Rotacja ox"){
    Prostopadloscian Pr;
    Pr.rotacja(360,1);
    double x,y,z,a=0;
    x=y=z=0;
    CHECK(Pr[0][0]-(x+a)<PRECISION);
    CHECK(Pr[0][1]-(y+a)<PRECISION);
    CHECK(Pr[0][2]-(z+a)<PRECISION);
    
    CHECK(Pr[1][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[1][1]-(y+a)<PRECISION);
    CHECK(Pr[1][2]-(z+a)<PRECISION);
    
    CHECK(Pr[2][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[2][1]-(y+Y_bok+a)<PRECISION);
    CHECK(Pr[2][2]-(z+a)<PRECISION);
    
    CHECK(Pr[3][0]-(x+a)<PRECISION);
    CHECK(Pr[3][1]-(y+Y_bok+a)<PRECISION);
    CHECK(Pr[3][2]-(z+a)<PRECISION);
    
    CHECK(Pr[4][0]-(x+a)<PRECISION);
    CHECK(Pr[4][1]-(y+a)<PRECISION);
    CHECK(Pr[4][2]-(z+Z_bok+a)<PRECISION);
    
    CHECK(Pr[5][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[5][1]-(y+a)<PRECISION);
    CHECK(Pr[5][2]-(z+Z_bok+a)<PRECISION);
    
    CHECK(Pr[6][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[6][1]-(y+Y_bok+a)<PRECISION);
    CHECK(Pr[6][2]-(z+Z_bok+a)<PRECISION);
    
    CHECK(Pr[7][0]-(x+a)<PRECISION);
    CHECK(Pr[7][1] -(y+Y_bok+a)<PRECISION);
    CHECK(Pr[7][2] -(z+Z_bok+a)<PRECISION);

}

TEST_CASE("Rotacja oy"){
    Prostopadloscian Pr;
    Pr.rotacja(360,2);
    double x,y,z,a=0;
    x=y=z=0;
    CHECK(Pr[0][0]-(x+a)<PRECISION);
    CHECK(Pr[0][1]-(y+a)<PRECISION);
    CHECK(Pr[0][2]-(z+a)<PRECISION);
    
    CHECK(Pr[1][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[1][1]-(y+a)<PRECISION);
    CHECK(Pr[1][2]-(z+a)<PRECISION);
    
    CHECK(Pr[2][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[2][1]-(y+Y_bok+a)<PRECISION);
    CHECK(Pr[2][2]-(z+a)<PRECISION);
    
    CHECK(Pr[3][0]-(x+a)<PRECISION);
    CHECK(Pr[3][1]-(y+Y_bok+a)<PRECISION);
    CHECK(Pr[3][2]-(z+a)<PRECISION);
    
    CHECK(Pr[4][0]-(x+a)<PRECISION);
    CHECK(Pr[4][1]-(y+a)<PRECISION);
    CHECK(Pr[4][2]-(z+Z_bok+a)<PRECISION);
    
    CHECK(Pr[5][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[5][1]-(y+a)<PRECISION);
    CHECK(Pr[5][2]-(z+Z_bok+a)<PRECISION);
    
    CHECK(Pr[6][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[6][1]-(y+Y_bok+a)<PRECISION);
    CHECK(Pr[6][2]-(z+Z_bok+a)<PRECISION);
    
    CHECK(Pr[7][0]-(x+a)<PRECISION);
    CHECK(Pr[7][1] -(y+Y_bok+a)<PRECISION);
    CHECK(Pr[7][2] -(z+Z_bok+a)<PRECISION);

}
TEST_CASE("Rotacja oz"){
    Prostopadloscian Pr;
    Pr.rotacja(360,3);
    double x,y,z,a=0;
    x=y=z=0;
    CHECK(Pr[0][0]-(x+a)<PRECISION);
    CHECK(Pr[0][1]-(y+a)<PRECISION);
    CHECK(Pr[0][2]-(z+a)<PRECISION);
    
    CHECK(Pr[1][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[1][1]-(y+a)<PRECISION);
    CHECK(Pr[1][2]-(z+a)<PRECISION);
    
    CHECK(Pr[2][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[2][1]-(y+Y_bok+a)<PRECISION);
    CHECK(Pr[2][2]-(z+a)<PRECISION);
    
    CHECK(Pr[3][0]-(x+a)<PRECISION);
    CHECK(Pr[3][1]-(y+Y_bok+a)<PRECISION);
    CHECK(Pr[3][2]-(z+a)<PRECISION);
    
    CHECK(Pr[4][0]-(x+a)<PRECISION);
    CHECK(Pr[4][1]-(y+a)<PRECISION);
    CHECK(Pr[4][2]-(z+Z_bok+a)<PRECISION);
    
    CHECK(Pr[5][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[5][1]-(y+a)<PRECISION);
    CHECK(Pr[5][2]-(z+Z_bok+a)<PRECISION);
    
    CHECK(Pr[6][0]-(x+X_bok+a)<PRECISION);
    CHECK(Pr[6][1]-(y+Y_bok+a)<PRECISION);
    CHECK(Pr[6][2]-(z+Z_bok+a)<PRECISION);
    
    CHECK(Pr[7][0]-(x+a)<PRECISION);
    CHECK(Pr[7][1] -(y+Y_bok+a)<PRECISION);
    CHECK(Pr[7][2] -(z+Z_bok+a)<PRECISION);

}

