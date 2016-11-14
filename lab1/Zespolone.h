#ifndef ZESPOLONE_H
#define ZESPOLONE_H
#include "Liczba.h"

#include <string>
#include <iostream>

class Zespolone
{
    public:
        Zespolone(string rz, string ur);
        Zespolone(Liczba rz,Liczba ur);

        Liczba getRzeczywista();
        Liczba getUrojona();

        string get();

        Zespolone dodaj (Zespolone x);
        Zespolone odejmij(Zespolone x);
        Zespolone iloczyn (Zespolone x);

    protected:

    private:
        Liczba rzeczywista;
        Liczba urojona;
	void setRzeczywista(Liczba rz);
	void setUrojona(Liczba u);
};

#endif // ZESPOLONE_H
