#ifndef LICZBA_H
#include <string>
#include<string>
#include <iostream>
#include<cmath>
#define LICZBA_H

using namespace std;

class Liczba
{
    public:
        Liczba(string l);
        Liczba (string c, string m, bool z);
        Liczba();

        string get();
        bool getZnak();
        string getCecha();
        string getMantysa();
        Liczba getLiczba();
        Liczba dodaj(Liczba x);
        Liczba odejmij(Liczba x);
        Liczba mnozenie(Liczba x);

    protected:
    private:
            string liczba;
            string cecha;
            string mantysa;
            bool znak;
    
            void ustawPoczWartoscCechy();
            void ustawPoczWartoscMantysy();
            void ustawPoczWartoscZnaku();
    
            string setLiczba();
            void setZnak(bool z);
            void setCecha(string c);
            void setMantysa(string m);

            string maxD(string x, string y);
            string minD(string x, string y);

            Liczba dodawanie(Liczba x);
            Liczba odejmowanie(Liczba x);
            void pozyczka(string x);
            void usun();

};

#endif // LICZBA_H
