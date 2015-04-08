#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include "Header.h"

using namespace std;


int main()
{
    fstream plik, plik2, pilknowe, trenerzy_nowy;
    string linia;

    plik.open("pilkarze.txt", ios::in);
    plik2.open("trenerzy.txt", ios::in);

    vector < Pilkarz > footballer;
    vector < Trener > trainer;

    if(!plik.good())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
        cout << "Nie udalo sie pobrac danych z pliku\n";
        exit(0);
    }
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

        footballer.push_back( Pilkarz( odp_imie, odp_nazwisko, odp_numer, odp_klub ) );
    }
    while(!plik2.eof())
    {

        string odpp_imie;
        getline(plik2,odpp_imie);

        string odpp_nazwisko;
        getline(plik2, odpp_nazwisko);

        string odpp_klub;
        getline(plik2, odpp_klub);

        trainer.push_back( Trener( odpp_imie, odpp_nazwisko, odpp_klub ) );
    }
    cout << "Pomyslnie wczytano dane z pliku" << endl << endl;



    cout << "Baza Osob\n" <<
         "1.-Lista pilkarzy\n" <<
         "2.-Lista trenerow\n" <<
         "3.-Wypisz wielkosc bazy pilkarzy\n" <<
         "4.-Wypisz wielkosc bazy trenerow\n" <<
         "5.-Zmien klub pilkarza/trenera\n" <<
         "6.-Wypisz dane zawodnika\n" <<
         "7.-Laczna wielkosc baz(pole statyczne)\n" <<
         "8.-Laczna wielkosc baz(metoda statyczna)\n" <<
         "9.-Sprawdz tozsamosc wskaznika" << endl; //zastosowanie metody wirtualnej

    cout << "\nB.- Zapisz zmiany w pliku pilkarze_nowy.txt";
    cout << "\nC.- Zapisz zmiany w pliku trenerzy_nowy.txt";
    cout << "\nQ.- Wyjscie z programu\n" << endl;



    char wybor;
    do
    {
        wybor = getch();

        switch( wybor )
        {
        case '1':
        {
            cout << "\n\n\nLista pilkarzy:\n";
            for( int i = 0; i < footballer.size(); i++ )
            {
                cout << endl;
                cout << "Imie: " << footballer[ i ].imie << endl;
                cout << "Nazwisko: " << footballer[ i ].nazwisko << endl;
                cout << "Numer na koszulce: " << footballer[ i ].numer << endl;
                cout << "Klub: " << footballer[i].klub << endl;
            }
            break;
        }
        case '2':
        {
            cout << "\n\n\nLista trenerow:\n";
            for( int i = 0; i < trainer.size(); i++ )
            {
                cout << endl;
                cout << "Imie: " << trainer[ i ].imie << endl;
                cout << "Nazwisko: " << trainer[ i ].nazwisko << endl;
                cout << "Klub: " << trainer[ i ].klub << endl;
            }
            break;
        }
        case '3':
        {
            cout << "Wielkosc bazy pilkarzy wynosi: " << Pilkarz::licznik << endl;
            break;
        }
        case '4':
        {
            cout << "Wielkosc bazy trenerow wynosi: " << Trener::licznik << endl;
            break;
        }
        case '5':
        {
            char p_or_t;
            cout << "Zmienic klub pilkarzowi czy trenerowi? P/T" << endl;
            p_or_t = getch();

            if(p_or_t == 'P' || p_or_t == 'p')
            {
                int wybor_pilkarza;
                string wybrany_klub;
                cout << "ktoremu pilkarzowi zmienic klub? 0-" << footballer.size()-1 << endl;
                cin >> wybor_pilkarza;


                if(wybor_pilkarza < (footballer.size()))
                {
                    if(cin.fail())
                    {
                        cout << "niepoprawnie wprowadzone dane" << endl;
                        cin.clear();
                        cin.sync();
                        break;
                    }
                    cout << "Klub: ";
                    cin >> wybrany_klub;
                    footballer[wybor_pilkarza].klub=wybrany_klub;
                    cout << "pomyslnie zmieniono klub" << endl;
                }
                else
                {
                    cout << "Nie ma pilkarza o takim id" << endl;
                    break;
                }
            } //end if
            else if (p_or_t == 'T' || p_or_t == 't')
            {
                int wybor_trenera;
                string wybrany_klub;
                cout << "ktoremu trenerowi zmienic klub? 0-" << trainer.size()-1 << endl;
                cin >> wybor_trenera;


                if(wybor_trenera < (trainer.size()))
                {
                    if(cin.fail())
                    {
                        cout << "niepoprawnie wprowadzone dane" << endl;
                        cin.clear();
                        cin.sync();
                        break;
                    }
                    cout << "Klub: ";
                    cin >> wybrany_klub;
                    trainer[wybor_trenera].klub=wybrany_klub;
                    cout << "pomyslnie zmieniono klub" << endl;
                }
                else
                {
                    cout << "Nie ma trenera o takim id" << endl;
                    break;
                }
            }
            else
            {
                cout << "Wybrano niepoprawna opcje";
            }
            break;



        } //end case 5



        case '6':
        {
            int id_zawodnika;
            cout << "Podaj id zawodnika, ktorego dane chcesz zobaczyc: 0 - " << footballer.size() - 1 << endl;
            cin >> id_zawodnika;
            if(id_zawodnika < footballer.size())
            {
                if(cin.fail())
                {
                    cout << "Wprowadzono niepoprawne dane" << endl;
                    cin.clear();
                    cin.sync();
                    break;
                }
                cout << footballer[id_zawodnika];
                break;
            }
            else
            {
                cout << "Niepoprawne id zawodnika " << endl;
                break;
            }
        }
            case '7':
            {
                cout << "Laczna wielkosc bazy wynosi: " << Czlowiek::licznik << endl;
                break;
            }
            case '8':
            {
                cout << "Liczba wszystkich w bazie wynosi: " << Czlowiek::Licznik() << endl;
                break;
            }
            case '9':
            {
                Pilkarz p1poli("testowy", "pilkarz", "test", "test");
                Trener t1poli("testowy", "trener", "test");
                Czlowiek *wskaznik;
                wskaznik = &t1poli;
                wskaznik -> tozsamosc();

                break;
            }
            case 'B':
            {
                pilknowe.close();
                pilknowe.open("pilkarze_nowe.txt", ios::out);
                for(int i=0 ; i<footballer.size(); i++)
                {
                    pilknowe << footballer[i].imie << endl << footballer[i].nazwisko << endl << footballer[i].numer << endl
                             << footballer[i].klub << endl;
                }
                cout << "pomyslnie zapisano w pliku pilkarze_nowe.txt" << endl;
                break;
            }
            case 'b':
            {
                pilknowe.close();
                pilknowe.open("pilkarze_nowe.txt", ios::out);
                for(int i=0 ; i<footballer.size(); i++)
                {
                    pilknowe << footballer[i].imie << endl << footballer[i].nazwisko << endl << footballer[i].numer << endl
                             << footballer[i].klub << endl;
                }
                cout << "pomyslnie zapisano w pliku pilkarze_nowe.txt" << endl;
                break;
            }
            case 'C':
            {
                trenerzy_nowy.close();
                trenerzy_nowy.open("trenerzy_nowe.txt", ios::out);
                for(int i=0 ; i<trainer.size(); i++)
                {
                    trenerzy_nowy << trainer[i].imie << endl << trainer[i].nazwisko << endl
                                  << trainer[i].klub << endl;
                }
                cout << "pomyslnie zapisano w pliku trenerzy_nowe.txt" << endl;
                break;
            }
            case 'c':
            {
                trenerzy_nowy.close();
                trenerzy_nowy.open("trenerzy_nowe.txt", ios::out);
                for(int i=0 ; i<trainer.size(); i++)
                {
                    trenerzy_nowy << trainer[i].imie << endl << trainer[i].nazwisko << endl
                                  << trainer[i].klub << endl;
                }
                cout << "pomyslnie zapisano w pliku trenerzy_nowe.txt" << endl;
                break;
            }
            case 'Q':
            {
                cout << "Czy na pewno chcesz wyjsc z programu? T/N: ";
                char choose;
                choose = getch();
                switch(choose)
                {
                case 'T':
                {
                    exit(0);
                }
                case 'N':
                {
                    cout << endl;
                    break;
                }
                case 't':
                {
                    exit(0);
                }
                case 'n':
                {
                    cout << endl;
                    break;
                }
                default:
                {
                    cout << "nie ma takiej opcji" << endl;
                }
                }
            }
            case 'q':
            {
                cout << "Czy na pewno chcesz wyjsc z programu? T/N: ";
                char choosee;
                choosee = getch();
                switch(choosee)
                {
                case 'T':
                {
                    exit(0);
                }
                case 'N':
                {
                    cout << endl;
                    break;
                }
                case 't':
                {
                    exit(0);
                }
                case 'n':
                {
                    cout << endl;
                    break;
                }
                default:
                {
                    cout << "nie ma takiej opcji" << endl;
                }
                }
            }
            default:
            {
                cout << "nie ma takiej opcji" << endl;
            }

        }
        }
        while(true);

        return 0;
    }
