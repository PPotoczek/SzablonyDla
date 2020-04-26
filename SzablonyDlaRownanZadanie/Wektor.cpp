#include "Wektor.hh"
#include<iomanip>

/*
template <class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR>:: Wektor()
{
    for(int i=0;i<ROZMIAR;i++)
    {
        daneWek[i]=0;
    }
}
template<class TYP, int ROZMIAR>
Wektor::Wektor(TYP x, TYP y, TYP z)
{
    daneWek[0]=x;
    daneWek[1]=y;
    daneWek[2]=z;
}
double Wektor::Dlugosc() const
{
    double Wynik=0;
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik+=daneWek[i]*daneWek[i];
    }
    Wynik = sqrt(Wynik);
    return Wynik;
}

double Wektor:: operator * (const Wektor &W2) const             //skalarny
{
    double Wynik=0;
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik+= this->daneWek[i]*W2.daneWek[i];
    }
    return Wynik;
}

const Wektor Wektor:: operator + (const Wektor &W2) const
{
    Wektor Wynik(0, 0, 0);
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik.daneWek[i]=this->daneWek[i]+W2.daneWek[i];
    }
    return Wynik;
}

const Wektor Wektor:: operator - (const Wektor &W2) const
{
    Wektor Wynik(0, 0, 0);
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik.daneWek[i]=this->daneWek[i]-W2.daneWek[i];
    }
    return Wynik;
}

const double & Wektor:: operator[] (int indeks) const
{
    if (indeks < 0 || indeks >= ROZMIAR)
    {
        std::cerr << "Blad: Zly indeks wektora";
        exit(1);
    }
    return this->daneWek[indeks];
}

template<class TYP, int ROZMIAR>
TYP & Wektor<TYP, ROZMIAR>:: operator[] (int indeks)
{
    if (indeks < 0 || indeks >= ROZMIAR)
    {
        std::cerr << "Blad: Zly indeks wektora";
        exit(1);
    }
    return this->daneWek[indeks];
}

template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &str, Wektor <TYP, ROZMIAR> &Wek)
{

    for(int i=0;i<ROZMIAR;i++)
    {
        str >> Wek[i];
    }
    return str;
}

template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &str, const Wektor <TYP, ROZMIAR> &Wek)
{
    str << "( ";
    for(int i=0;i<ROZMIAR;i++)
    {
        str << Wek[i];
        if(i<ROZMIAR-1)
        {
            str << ", ";
        }
    }
    str << " )";
}
*/