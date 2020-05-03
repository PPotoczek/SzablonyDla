/*
#include "UkladRownanLiniowych.hh"
#include<iomanip>
UkladRownanLiniowych:: UkladRownanLiniowych()
{
    MacierzKw();
    Wektor();
}

UkladRownanLiniowych:: UkladRownanLiniowych(MacierzKw M, Wektor W)
{
    A = M;
    B = W;
}

const MacierzKw & UkladRownanLiniowych:: Wez_Macierz() const
{
    return A;
}

const Wektor & UkladRownanLiniowych:: Wez_Wektor() const
{
    return B;
}

void UkladRownanLiniowych:: Zmien_Macierz(const MacierzKw & M)
{
    A=M;
}

void UkladRownanLiniowych:: Zmien_Wektor(const Wektor & W)
{
    B=W;
}

Wektor UkladRownanLiniowych:: Oblicz_Odwrotna() const
{
    MacierzKw Wynik_pom = A.Odwrotnosc();
    Wektor Wynik = Wynik_pom * B;
    return Wynik;
}

Wektor UkladRownanLiniowych:: Oblicz_Crammer() const
{
    MacierzKw Pomocnicza = A;
    Wektor Wynik(0,0,0);
    double wyznacznik_gl = A.WyznacznikLaPlace();
    double zmienna=0;
    if(wyznacznik_gl==0)
    {
        std::cerr << "Blad, wyznaczik rowny zeru" << std::endl;
        exit(1);
    }
    for (int i = 0; i <ROZMIAR; i++)
    {
        Pomocnicza.Zamiana_kolumny(i,B);
        zmienna = Pomocnicza.WyznacznikLaPlace();
        Wynik[i] = zmienna/wyznacznik_gl;
        Pomocnicza = A;
        zmienna = 0;
    }
    return Wynik;
}
Wektor UkladRownanLiniowych:: Blad(const Wektor & W) const
{
    Wektor Wynik;
    Wynik = A*W - B;
    return Wynik;
}

std::istream& operator >> (std::istream &Str, UkladRownanLiniowych &UklRown)
{
    MacierzKw temp_M;
    Wektor temp_W;
    Str >> temp_M >> temp_W;
    temp_M.Transpozycja();
    UklRown.Zmien_Macierz(temp_M);
    UklRown.Zmien_Wektor(temp_W);
}

std::ostream& operator << ( std::ostream &str, const UkladRownanLiniowych &UklRown)
{

    MacierzKw temp_M;
    Wektor temp_W;
    temp_M = UklRown.Wez_Macierz();
    temp_W = UklRown.Wez_Wektor();
    //str << temp_M << temp_W;                                     // Standardowe wypisanie
    for(int i=0;i<ROZMIAR;i++)
    {
        str << "|" << std::right << std::setw(3);
        for(int j=0;j<ROZMIAR;j++)
        {
            str << std::right << std::setw(5) <<  temp_M[i][j] << std::setw(5);
        }
        str << std::right << std::setw(3) << "|";
        str << "|" << std::right << std::setw(3);
        str << "x_" << i+1;
        str << std::right << std::setw(2) << "|";
        if(i==1)
        {
            str << " = ";
        }
        else
        {
            str << "   ";
        }
        str << "|" << std::right << std::setw(5)
            << temp_W[i] << std::setw(5) << "|";
        str << std::endl;
    }
}
*/