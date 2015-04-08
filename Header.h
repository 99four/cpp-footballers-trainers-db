#include <iostream>
using namespace std;

class Czlowiek
{
public:
    string imie;
    string nazwisko;
    string klub;

    virtual void tozsamosc()=0;

    static int licznik; //licznik klasy bazowej

    static int Licznik()
    {
        return licznik;
    }

};

class Pilkarz: public Czlowiek
{
public:
    static int licznik;
    string numer;
    Pilkarz( string ximie, string xnazwisko, string xnumer, string xklub );

    static int Licznik()
    {
        return licznik;
    }

    void tozsamosc()
    {
        cout << "jestem pilkarzem!" << endl;
    }

    friend ostream &operator << (ostream &out, Pilkarz &a);
};

class Trener: public Czlowiek
{
public:
    static int licznik;

    static int Licznik()
    {
        return licznik;
    }

    Trener( string ximie, string xnazwisko, string xklub );

    void tozsamosc()
    {
        cout << "jestem trenerem!" << endl;
    }

};
