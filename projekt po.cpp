#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;


class czlowiek
{


public:
    static int licznik;
    string imie;
    string nazwisko;
    string numer;
    string klub;
    czlowiek( string ximie, string xnazwisko, string xnumer, string xklub );

    static int Licznik()
    {
        return licznik;
    }

    friend ostream &operator << (ostream &out, czlowiek &a);
};

int main()
{
    fstream plik;
    string linia;

    plik.open("plik.txt", ios::in);

    vector < czlowiek > osoba;
    cout << "Baza Osob\n1.-Lista osob\n2.-Dodaj osoby do bazy\n3.-Wyjscie\n4.-Wielkosc bazy\n5.-Zmien klub\n6.-Wypisz dane zawodnika\n7.-Wielkosc bazy(pole statyczne)\n8.- Wielkosc bazy(metoda statyczna)" << endl;
    char wybor;
    do
    {
        wybor = getch();
        //odp = getch();
        switch( wybor )
        {
        case '1':
            cout << "\n\n\nLista osob:\n";
            for( int i = 0; i < osoba.size(); i++ )
            {
                cout << endl;
                cout << "Nazwa: " << osoba[ i ].imie << endl;
                cout << "Autor: " << osoba[ i ].nazwisko << endl;
                cout << "Numer tel.: " << osoba[ i ].numer << endl;
                cout << "Klub: " << osoba[i].klub << endl;
            }
            break;
        case '2':
            while(!plik.eof())
            {

                string odp_imie;
                getline(plik,odp_imie);

                string odp_nazwisko;
                getline(plik, odp_nazwisko);

                string odp_numer;
                getline(plik, odp_numer);

                string odp_klub;
                getline(plik, odp_klub);

                osoba.push_back( czlowiek( odp_imie, odp_nazwisko, odp_numer, odp_klub ) );
            }
            cout << "\n<***ZAKONCZONO_Z_SUKCESEM***>" << endl;break;
        case '4':
        {
            cout << "Osob w bazie: " << osoba.size() << endl;
        }
        case '5':
        {
            int wybor;
            string wybrany_klub;
            cout << "ktoremu pilkarzowi zmienic klub? 0-" << osoba.size()-1 << endl;
            cin >> wybor;
            cout << "Klub: ";
            cin >> wybrany_klub;
            osoba[wybor].klub=wybrany_klub;
            cout << "pomyslnie zmieniono klub" << endl;
            break;
        }
        case '6':
        {
            int id_zawodnika;
            cout << "Podaj id zawodnika, ktorego dane chcesz zobaczy: ";
            cin >> id_zawodnika;
            cout << osoba[id_zawodnika];
            break;
        }
        case '7':
        {
            cout << "Licznik bazy wynosi: " << czlowiek::licznik << endl;
            break;
        }
        case '8':
        {
            cout << "Licznik bazy wynosi: " << czlowiek::Licznik() << endl;
            break;
        }

        }
    }
    while( wybor != '3' );

    return 0;
}



czlowiek::czlowiek( string ximie, string xnazwisko, string xnumer, string xklub )
{
    imie = ximie;
    nazwisko = xnazwisko;
    numer = xnumer;
    klub = xklub;
    licznik++;
}

ostream &operator << (ostream &out, czlowiek &a)
{
    cout << a.imie << " " << a.nazwisko << " " << a.numer << " " << a.klub << endl;
}

int czlowiek::licznik = 0;
