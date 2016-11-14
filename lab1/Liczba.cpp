#include "Liczba.h"


using namespace std;

Liczba::Liczba(string l)
{
    liczba=l;
    ustawPoczWartoscZnaku(); 
    ustawPoczWartoscCechy();
    ustawPoczWartoscMantysy();
    
}
Liczba::Liczba(string c,string m, bool z)
{
    setCecha(c);
    setMantysa(m);
    setZnak(z);
    liczba=setLiczba();
}
Liczba::Liczba()
{

}

string Liczba::get()
{
    return liczba;
}

bool Liczba::getZnak()
{
    return znak;
}
string Liczba::getCecha()
{
    return cecha;
}
string Liczba::getMantysa()
{
    return mantysa;
}
Liczba Liczba::getLiczba()
{
    return *this;
}
Liczba Liczba::dodaj(Liczba x)
{
    if(znak!=x.getZnak()) return odejmowanie(x);
    else return dodawanie(x);
}
Liczba Liczba::odejmij(Liczba x)
{
    if(znak!=x.getZnak()) return dodawanie(x);
    else return odejmowanie(x);
}
Liczba Liczba::mnozenie(Liczba x)
{
    string a=cecha+mantysa;
    string b=x.getCecha()+x.getMantysa();
    int m=0, k=0, dl=0, prze=0;
    string wM="", pom="", wC="";
    Liczba w=Liczba("0,0");
    for (int l=(int)b.size()-1; l>=0; l--)
    {
        m=(int)b[l]-48;
        pom="";
        for (int j=(int)a.size()-1; j>=0; j--)
        {
            k=((int)a[j]-48)*m+prze;
            pom=std::to_string(k%10)+pom;
            prze=k/10;
        }
        if(prze!=0) pom=std::to_string(prze)+pom;
        prze=0;
        for (int i=l; i<b.size()-1;i++) pom=pom+"0";

        //dodawanie;
        w=w.dodaj(Liczba(pom,"0",true));
    }
    //ile po przecinku
    dl=(int)mantysa.size()+(int)x.getMantysa().size();
    pom=w.getCecha();
    for (int i=(int)pom.size()-1; i>=(int)pom.size()-dl;i--) wM=pom[i]+wM;
    for (int i=0; i<(int)pom.size()-dl;i++) wC+=pom[i];

    setZnak(znak==x.getZnak());
    setCecha(wC);
    setMantysa(wM);
    usun();
    return *this;
}
////Prywatne

string Liczba::setLiczba()
{
    string z="";
    if(!znak) z="-";
    return z+cecha+","+mantysa;
}
void Liczba::setCecha(string c)
{
    cecha=c;
}
void Liczba::setMantysa(string m)
{
    mantysa=m;
}
void Liczba::setZnak(bool z)
{
    znak=z;
}
void Liczba::ustawPoczWartoscZnaku()
{
    znak = (liczba[0]!='-') ;
}
void Liczba::ustawPoczWartoscCechy()
{
     this->cecha="";
    if (liczba[0]!='-') cecha=liczba[0];
    for (int i=1; i<liczba.length() && liczba[i]!=','; i++)
    {


        cecha += liczba[i];
    }
}
void Liczba::ustawPoczWartoscMantysy()
{
    mantysa="";
    bool jestPrzecinek=false;
    int j=0;
    while(j++<liczba.length() && !jestPrzecinek) if(liczba[j]==',') jestPrzecinek=true;
    if(jestPrzecinek)
    for (int i=(int)liczba.length()-1; i>=0 && liczba[i]!=','; i--)
    {

       mantysa= liczba[i]+mantysa;
    }
    else mantysa="0";
}
Liczba Liczba::odejmowanie(Liczba x)
{
    string mxC, mxM, mnC, mnM;
    int i=0;
    bool czyR=false;//czy rozne
    bool znakW; //znak wiekszej liczby

string wM="", wC="";

    //sprawdzanie ktora wieksza

    mnC=x.getCecha();
    mnM=x.getMantysa();
    usun();
    x.usun();
    if(cecha.size()>mnC.size())
        {
            mxC=cecha;
            mxM=mantysa;
            znakW=znak;
        }
    else
        {
            if(cecha.size()<mnC.size())
            {
                mxC=x.getCecha();
                mxM=x.getMantysa();
                znakW=!x.getZnak();
                mnC=cecha;
                mnM=mantysa;
            }
            else
                {   i=0;
                    while (i<cecha.size() && !czyR)
                    {
                        if(cecha[i]!=mnC[i])
                        {
                            if(cecha[i]>mnC[i])
                            {
                                mxC=cecha;
                                mxM=mantysa;
                                znakW=znak;
                            }
                            else
                            {
                                mxC=x.getCecha();
                                mxM=x.getMantysa();
                                mnC=cecha;
                                mnM=mantysa;
                                znakW=!x.getZnak();
                            }
                            czyR=true;
                          }
                        i++;
                    }
                    if(!czyR)
                    {
                        if(mantysa.size()<mnM.size())
                        {   i=0;
                            while (i<mantysa.size() && !czyR)
                            {
                                if(mantysa[i]!=mnM[i])
                                {
                                    if(mantysa[i]>mnM[i])
                                    {
                                        mxC=cecha;
                                        mxM=mantysa;
                                        znakW=znak;
                                    }
                                    else
                                    {
                                        mxC=x.getCecha();
                                        mxM=x.getMantysa();
                                        mnC=cecha;
                                        mnM=mantysa;
                                        znakW=!x.getZnak();
                                    }
                                    czyR=true;
                                  }
                                i++;
                            }
                            if(!czyR)
                            {
                                mxC=x.getCecha();
                                mxM=x.getMantysa();
                                mnC=cecha;
                                mnM=mantysa;
                                znakW=!x.getZnak();
                            }
                        }
                        else
                        {   i=0;
                            while (i<mantysa.size() && !czyR)
                            {
                                if(mantysa[i]!=mnM[i])
                                {
                                    if(mantysa[i]>mnM[i])
                                    {
                                        mxC=cecha;
                                        mxM=mantysa;
                                        znakW=znak;
                                    }
                                    else
                                    {
                                        mxC=x.getCecha();
                                        mxM=x.getMantysa();
                                        mnC=cecha;
                                        mnM=mantysa;
                                        znakW=!x.getZnak();
                                    }
                                    czyR=true;
                                  }
                                i++;
                            }
                            if(!czyR)
                            {
                                mxC=cecha;
                                mxM=mantysa;
                                znakW=znak;
                            }
                        }
                    }
                }
            }
                //wypelnienie zerami
                if((int)mxC.size()>(int)mnC.size()) for(int i=(int)mnC.length();i<(int)mxC.length();i++) mnC="0"+mnC;
                if((int)mxM.size()>(int)mnM.size()) for (int i=(int)mnM.length();i<(int)mxM.length();i++) mnM=mnM+"0";
                else for (int i=(int)mxM.length();i<(int)mnM.length();i++) mxM=mxM+"0";

		bool pozyczka=false;
		for(int j=(int)mxM.size()-1; j>=0; j--)
		{
			if((mxM[j]-mnM[j])<0)
			{
				wM=std::to_string(mxM[j]+10-mnM[j])+wM;
				if(j!=0) mxM[j-1]-=1;
				pozyczka=true;
			}
			else
			{
				pozyczka=false;
				wM=std::to_string(mxM[j]-mnM[j])+wM;
			}
		}
		if(pozyczka) mxC[mxC.size()-1]-=1;
		for(int j=(int)mxC.size()-1; j>=0; j--)
		{
			if(mxC[j]-mnC[j]<0)
			{
				wC=std::to_string(mxC[j]+10-mnC[j])+wC;
				mxC[j-1]-=1;

			}
			else wC=std::to_string(mxC[j]-mnC[j])+wC;

		}

        setZnak(znakW);
        setCecha(wC);
        setMantysa(wM);
    
        usun();
    
        return *this;
}
Liczba Liczba::dodawanie(Liczba x)
{
    int w=0;
    int przeniesienie=0;
    string wynikC="";
    string wynikM="";
    string mnC = minD(cecha, x.getCecha());
    string mxC=maxD(cecha,x.getCecha());
    string mnM = minD(mantysa, x.getMantysa());
    string mxM=maxD(mantysa,x.getMantysa());
    string pom="";
    for (int i=(int)mnM.length();i<(int)mxM.length();i++) mnM=mnM+"0";
    for(int i=(int)mxM.length()-1;i>=0;i--)
    {

             w=(int)mnM[i]+(int)mxM[i]-96+przeniesienie;
             pom=wynikM;
             wynikM=std::to_string(w%10)+pom;
             przeniesienie=w/10;
    }
    for (int i=(int)mnC.length();i<(int)mxC.length();i++) mnC="0"+mnC;
    for(int i=(int)mxC.length()-1;i>=0;i--)
    {


             w=(int)mnC[i]+(int)mxC[i]-96+przeniesienie;
             pom=wynikC;
             wynikC=std::to_string(w%10)+pom;
             przeniesienie=w/10;
    }
    if(przeniesienie!=0) wynikC=std::to_string(przeniesienie)+wynikC;
    
    setCecha(wynikC);
    setMantysa(wynikM);
    
    usun();
    
    return *this;
    


}

string Liczba::maxD(string x,string y)
{
    if(x.length()!=y.length())
    {
        if(x.length()> y.length()) return x;
        else return y;
    }
    else
    {
            return x;
    }
}
string Liczba::minD(string x,string y)
{
     if(x.length()!=y.length())
        {
            if(x.length()< y.length()) return x;
            else return y;
        }
        else
        {
                return y;
        }
}
void Liczba::usun ()
{
    string wC="", wM="";
    int start=(int)cecha.size()-1;
    for(int i=0;i<cecha.size(); i++) if(cecha[i]!='0' ) { start=i; break;}
    
    for(int i=start;i<cecha.size(); i++) wC+=cecha[i];
    
    start=0;
    for(int i=(int)mantysa.size()-1;i>=0;i--) {if(mantysa[i]!='0') start=i; break;}
    
    
    for(int i=start; i>=0;i--) wM=mantysa[i]+wM;
    cecha=wC;
    mantysa=wM;
}
