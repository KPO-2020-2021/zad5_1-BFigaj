

#include "Scena.hh"


#define PLIK_WLASCIWY__DRON1_KORPUS  "dat/PlikWlasciwy_Dron1_Korpus.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR1  "dat/PlikWlasciwy_Dron1_Rotor1.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR2  "dat/PlikWlasciwy_Dron1_Rotor2.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR3  "dat/PlikWlasciwy_Dron1_Rotor3.dat"
#define PLIK_WLASCIWY__DRON1_ROTOR4  "dat/PlikWlasciwy_Dron1_Rotor4.dat"

using namespace std;


Dron& Scena::WezAktywnegoDrona(int i)
{
    return TabDronow[i];
}


bool Scena::UzyjAktynegoDrona(int i)
{
    Wektor3D przemieszczenie;
    Dron AktywnyDron;
    double kat=0,dlugosclotu=40;
    AktywnyDron=WezAktywnegoDrona(i);
    AktywnyDron.KtoryDron(i);
    AktywnyDron.TworzDrona();
    Lacze.Rysuj();
    char wybor[2]=" ";
    while(wybor[0]!='N')
    {
        cout << "Podaj wektor o jaki ma sie przesunac dron (na koniec wpisz 0)";
        cin >> przemieszczenie;
        cout << "Nacisnij ENTER, aby pokazac sciezke przelotu drona " << flush;
        cin.ignore(10000,'\n');
        AktywnyDron.PlanujPoczatkowaSciezke(kat,dlugosclotu,przemieszczenie,Lacze);
        Lacze.Rysuj();
        cout << "Nacisnij ENTER, aby wykonac ruch drona " << flush;
        cin.ignore(10000,'\n');
        
        
        AktywnyDron.WykonajPionowyLot(dlugosclotu,Lacze);
        AktywnyDron.WykonajPoziomyLot(dlugosclotu,przemieszczenie,Lacze);
        AktywnyDron.WykonajPionowyLot(dlugosclotu,Lacze);
        
        cout << "Jezeli nie chcesz kontynuowac wpisz N";
        cin >> wybor;
    }
    TabDronow[i]=AktywnyDron;
    return true;
}

void Scena::UstawLacze(PzG::LaczeDoGNUPlota& Lacze)
{
    this->Lacze=Lacze;
}