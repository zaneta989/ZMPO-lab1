#include "Zespolone.h"


Zespolone::Zespolone(string  rz, string ur)
{
    
    setRzeczywista(Liczba(rz)); 
    setUrojona(Liczba(ur));
}
Zespolone::Zespolone(Liczba rz, Liczba ur)
{
    setRzeczywista(rz);
    setUrojona(ur);

}
Liczba Zespolone::getRzeczywista()
{
    return rzeczywista;
}
Liczba Zespolone::getUrojona()
{
    return urojona;
}
Zespolone Zespolone::dodaj(Zespolone x)
{
    
    Liczba wynikR=rzeczywista.dodaj(x.getRzeczywista());
    Liczba wynikU=urojona.dodaj(x.getUrojona());
    
    setRzeczywista(wynikR);
    setUrojona(wynikU);
    return *this;

}
Zespolone Zespolone::odejmij(Zespolone x)
{

    Liczba wynikR=rzeczywista.odejmij(x.getRzeczywista());
    Liczba wynikU=urojona.odejmij(x.getUrojona());
    
    setRzeczywista(wynikR);
    setUrojona(wynikU);
    return *this;
}
Zespolone Zespolone::iloczyn(Zespolone x)
{
   
    Liczba wynikR=rzeczywista.mnozenie(x.getRzeczywista());
    wynikR=wynikR.odejmij(urojona.mnozenie(x.getUrojona()));
    Liczba wynikU=urojona.mnozenie(x.getRzeczywista());
    wynikU=wynikU.dodaj(rzeczywista.mnozenie(x.getUrojona()));
    
    setRzeczywista(wynikR);
    setUrojona(wynikU);
    return *this;
}
string Zespolone::get()
{
    string rz, ur;
    
    if(!rzeczywista.getZnak()) rz="-"+rzeczywista.getCecha()+","+rzeczywista.getMantysa();
    else rz=rzeczywista.getCecha()+","+rzeczywista.getMantysa();

    

    if(!urojona.getZnak()) ur="-"+urojona.getCecha()+","+urojona.getMantysa()+" i";
    else ur=urojona.getCecha()+","+urojona.getMantysa()+" i";

    return rz+" + "+ur+" ";

}
void Zespolone::setRzeczywista(Liczba rz)
{
    rzeczywista=rz;
}
void Zespolone::setUrojona(Liczba u)
{
    urojona=u;
}
