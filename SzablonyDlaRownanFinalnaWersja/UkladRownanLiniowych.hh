#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "Wektor.hh"

template<class TYP, int ROZMIAR>
class UkladRownanLiniowych
{
private:
    MacierzKw<TYP, ROZMIAR> A;
    Wektor<TYP, ROZMIAR> B;
public:
    UkladRownanLiniowych();
    const MacierzKw<TYP, ROZMIAR> & Wez_Macierz() const;
    const Wektor<TYP, ROZMIAR> & Wez_Wektor() const;
    void Zmien_Macierz(const MacierzKw<TYP, ROZMIAR> & M);
    void Zmien_Wektor(const Wektor<TYP, ROZMIAR> & W);
    Wektor<TYP, ROZMIAR> Oblicz_Odwrotna();
};
template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Str, UkladRownanLiniowych<TYP, ROZMIAR> &UklRown);

template<class TYP, int ROZMIAR>
std::ostream& operator << (std::ostream &Str, const UkladRownanLiniowych<TYP, ROZMIAR> &UklRown);

template<class TYP, int ROZMIAR>
UkladRownanLiniowych<TYP, ROZMIAR>:: UkladRownanLiniowych()
{
    MacierzKw<TYP, ROZMIAR>();
    Wektor<TYP, ROZMIAR>();
}

template<class TYP, int ROZMIAR>
const MacierzKw<TYP, ROZMIAR> & UkladRownanLiniowych<TYP, ROZMIAR>:: Wez_Macierz() const
{
    return A;
}

template<class TYP, int ROZMIAR>
const Wektor<TYP, ROZMIAR> & UkladRownanLiniowych<TYP, ROZMIAR>:: Wez_Wektor() const
{
    return B;
}

template<class TYP, int ROZMIAR>
void UkladRownanLiniowych<TYP, ROZMIAR>:: Zmien_Macierz(const MacierzKw<TYP, ROZMIAR> & M)
{
    A=M;
}

template<class TYP, int ROZMIAR>
void UkladRownanLiniowych<TYP, ROZMIAR>:: Zmien_Wektor(const Wektor<TYP, ROZMIAR> & W)
{
    B=W;
}

template<class TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> UkladRownanLiniowych<TYP, ROZMIAR>:: Oblicz_Odwrotna()
{
    MacierzKw<TYP, ROZMIAR> Wynik_pom;
    Wynik_pom = A.Odwrotnosc();
    Wektor<TYP, ROZMIAR> Wynik;
    Wynik = Wynik_pom * B;
    return Wynik;
}

template<class TYP, int ROZMIAR>
std::istream& operator >> (std::istream &Str, UkladRownanLiniowych<TYP, ROZMIAR> &UklRown)
{
    MacierzKw<TYP, ROZMIAR> temp_M;
    Wektor<TYP, ROZMIAR> temp_W;
    Str >> temp_M >> temp_W;
    temp_M.Transpozycja();
    UklRown.Zmien_Macierz(temp_M);
    UklRown.Zmien_Wektor(temp_W);
    return Str;
}

template<class TYP, int ROZMIAR>
std::ostream& operator << ( std::ostream &str, const UkladRownanLiniowych<TYP, ROZMIAR> &UklRown)
{
    MacierzKw<TYP, ROZMIAR> temp_M;
    Wektor<TYP, ROZMIAR> temp_W;
    temp_M = UklRown.Wez_Macierz();
    temp_W = UklRown.Wez_Wektor();
    str << temp_M << temp_W;
    return str;
}
#endif