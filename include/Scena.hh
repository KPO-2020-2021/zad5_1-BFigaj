#ifndef SCENA_HH
#define SCENA_HH


#include <iostream>
#include "Dron.hh"


/*!
 * \brief Instancja macierzy jako Macierz3x3
 *
 *  Modeluje pojecie macierzy 3x3 jej główną cechą jest określony wymiar
 *  czyli 3. Z racji tego że chcemy pracować w 3 wymiarach w programie.
 */
class Scena {
    Dron TabDronow[2];
    PzG::LaczeDoGNUPlota Lacze;
    public:
    Dron& WezAktywnegoDrona(int i);
    bool UzyjAktynegoDrona(int i);
    void UstawLacze(PzG::LaczeDoGNUPlota& Lacze);
    void Poczatek();

};

#endif

