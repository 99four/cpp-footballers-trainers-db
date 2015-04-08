#include <iostream>
#include "Header.h"
using namespace std;

Pilkarz::Pilkarz( string ximie, string xnazwisko, string xnumer, string xklub )
{
    imie = ximie;
    nazwisko = xnazwisko;
    numer = xnumer;
    klub = xklub;
    Czlowiek::licznik++; //licznik klasy bazowej
    licznik++;
}

Trener::Trener( string ximie, string xnazwisko, string xklub )
{
    imie = ximie;
    nazwisko = xnazwisko;
    klub = xklub;
    Czlowiek::licznik++; //licznik klasy bazowej
    licznik++;
}

ostream &operator << (ostream &out, Pilkarz &p)
{
    return out << p.imie << " " << p.nazwisko << " " << p.numer << " " << p.klub << endl;
}

int Pilkarz::licznik = 0;
int Czlowiek::licznik = 0;
int Trener::licznik = 0;
