#include <iostream>
#include<string>
#include "Liczba.h"
#include "Zespolone.h"
using namespace std;


int main()
{
    int option;
    string l1;
    string l2;
    Zespolone liczba1 = Zespolone(Liczba(), Liczba());
    Zespolone liczba2 = Zespolone(Liczba(), Liczba());
    do
    {
        cout << "\nTwoja liczba wynosi: ";
        cout<<liczba1.get();
        cout << "\n\n";
        cout << "0: Wyjscie";
        cout << "\n1: Wprowadz liczbe";
        cout << "\n2: Dodaj";
        cout << "\n3: Odejmij";
        cout << "\n4: Pomnoz\n";
        cin >> option;
        if(option == 1)
        {
            cout << "\nWprowadz liczbe: ";
            cout << "\nCzesc rzeczywista: "; cin >> l1; cout << "Czesc urojona:     "; cin >> l2;
            liczba1=Zespolone(Liczba(l1), Liczba(l2));
        }
        else if(option == 2)
        {
            cout << "\nDodaj: ";
            cout << "\nCzesc rzeczywista: "; cin >> l1; cout << "Czesc urojona:     "; cin >> l2;
            liczba2 = Zespolone(Liczba(l1), Liczba(l2));
            liczba1.dodaj(liczba2);
        }
        else if(option == 3)
        {
            cout << "\nOdejmij: ";
            cout << "\nCzesc rzeczywista: "; cin >> l1; cout << "Czesc urojona:     "; cin >> l2;
            liczba2 = Zespolone(Liczba(l1), Liczba(l2));
            liczba1.odejmij(liczba2);
        }
        else if(option == 4)
        {
            cout << "\nPomnoz przez: ";
            cout << "\nCzesc rzeczywista: "; cin >> l1; cout << "Czesc urojona:     "; cin >> l2;
            liczba2 = Zespolone(Liczba(l1), Liczba(l2));
            liczba1.iloczyn(liczba2);
        }
        cout << endl;
    }
    while (option != 0);
}
