#ifndef DRON_HH
#define DRON_HH


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <unistd.h>
#include "lacze_do_gnuplota.hh"
#include "Graniastoslup6.hh"
#include "Prostopadloscian.hh"

/*!
 * \brief Instancja macierzy jako Macierz3x3
 *
 *  Modeluje pojecie macierzy 3x3 jej główną cechą jest określony wymiar
 *  czyli 3. Z racji tego że chcemy pracować w 3 wymiarach w programie.
 */
class Dron {
    Wektor3D Polozenie;
    double KatOrientacji_stopnie;
    Prostopadloscian KorpusDrona;
    Graniastoslup6 RotorDrona[4];
    public:
    void PlanujPoczatkowaSciezke(double KatSkretu_stopnie,
                                double DlugoscLotu,
                                std::vector<Wektor3D>& PunktySciezki);
    bool WykonajPionowyLot(double DlugoscLotu,PzG::LaczeDoGNUPlota& Lacze);
    bool WykonajPoziomyLot(double DlugoscLotu,PzG::LaczeDoGNUPlota& Lacze);
    bool const Oblicz_i_Zapisz_WspGlbDrona();
    protected:
    Wektor3D TransfDoUklWspRodzica(const Wektor3D& Wierz)const;
    private:
    bool const Oblicz_i_Zapisz_WspGlbKorpusu();
    bool const Oblicz_i_Zapisz_WspGlbRotora(const Graniastoslup6& Rotor);


};

#endif

