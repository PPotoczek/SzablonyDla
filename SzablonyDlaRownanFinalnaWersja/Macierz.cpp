/*
#include "Macierz.hh"
#include<iomanip>


MacierzKw::MacierzKw()
{
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            daneMac[i][j]=0;
        }
    }
}

MacierzKw::MacierzKw(Wektor W1, Wektor W2, Wektor W3)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        daneMac[0][i]=W1[i];
        daneMac[1][i]=W2[i];
        daneMac[2][i]=W3[i];
    }
}

MacierzKw::MacierzKw(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3)
{
    daneMac[0][0]=x1;
    daneMac[0][1]=y1;
    daneMac[0][2]=z1;
    daneMac[1][0]=x2;
    daneMac[1][1]=y2;
    daneMac[1][2]=z2;
    daneMac[2][0]=x3;
    daneMac[2][1]=y3;
    daneMac[2][2]=z3;
}

const Wektor &MacierzKw:: operator[](int indeks) const
{
    if (indeks < 0 || indeks >= ROZMIAR)
    {
        std::cerr << "Blad: Zly indeks macierzy";
        exit(1);
    }
    return this->daneMac[indeks];
}

Wektor & MacierzKw:: operator[](int indeks)
{
    if (indeks < 0 || indeks >= ROZMIAR)
    {
        std::cerr << "Blad: Zly indeks macierzy";
        exit(1);
    }
    return this->daneMac[indeks];
}

double & MacierzKw::operator()(int indeks1, int indeks2)
{
    if (indeks1 < 0 || indeks1 >= ROZMIAR || indeks2 < 0 || indeks2 >= ROZMIAR)
    {
        std::cerr << "Blad: Zly indeks macierzy";
        exit(1);
    }
    return this->daneMac[indeks1][indeks2];
}

const double & MacierzKw::operator()(int indeks1, int indeks2) const
{
    if (indeks1 < 0 || indeks1 >= ROZMIAR || indeks2 < 0 || indeks2 >= ROZMIAR)
    {
        std::cerr << "Blad: Zly indeks macierzy";
        exit(1);
    }
    return this->daneMac[indeks1][indeks2];
}

const Wektor MacierzKw::wez_kolumne(int indeks) const
{
    Wektor Wynik(daneMac[0][indeks],daneMac[1][indeks],daneMac[2][indeks]);
    return Wynik;
}

void MacierzKw:: Zamiana_kolumny(int indeks, const Wektor &W)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        daneMac[i][indeks] = W[i];
    }
}

void MacierzKw::Transpozycja()
{
    MacierzKw M_Pomocnicza;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            M_Pomocnicza[i][j]=daneMac[i][j];
        }
    }
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            daneMac[i][j]=M_Pomocnicza[j][i];
        }
    }
}

double MacierzKw::WyznacznikSarrus() const
{
    double Wynik_dod,Wynik_odej,Wynik;
    Wynik_dod = daneMac[0][0]*daneMac[1][1]*daneMac[2][2]+daneMac[0][1]*daneMac[1][2]*daneMac[2][0]+daneMac[0][2]*daneMac[1][0]*daneMac[2][1];
    Wynik_odej = daneMac[0][2]*daneMac[1][1]*daneMac[2][0]+daneMac[0][0]*daneMac[1][2]*daneMac[2][1]+daneMac[0][1]*daneMac[1][0]*daneMac[2][2];
    Wynik=Wynik_dod-Wynik_odej;
    return Wynik;
}

double MacierzKw::WyznacznikLaPlace() const // wzgledem pierwszego wiersza
{
    double Wynik=0;
    for(int i=0;i<ROZMIAR;i++)
    {
        if(i%2)
        {
            Wynik+= (-1)*daneMac[0][i]*Wyznacznik2x2(0,i);
        }
        else
        {
            Wynik+= daneMac[0][i]*Wyznacznik2x2(0,i);
        }
    }
    //Wynik = daneMac[0][0]*Wyznacznik2x2(0,0) +  daneMac[0][1]*(-1)*Wyznacznik2x2(0, 1) + daneMac[0][2]*Wyznacznik2x2(0, 2);
    return Wynik;
}

double MacierzKw::Wyznacznik2x2(int wiersz, int kolumna) const
{
    double tab[4];
    int indeks=0;
    double Wynik=0;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            if(i!= wiersz && j!= kolumna)
            {
                tab[indeks]=daneMac[i][j];
                indeks++;
            }
        }
    }
    Wynik=tab[0]*tab[3]-tab[1]*tab[2];
    return Wynik;
}

const MacierzKw MacierzKw::Odwrotnosc() const
{
    MacierzKw Wynik;
    double wyznacznik=0;
    wyznacznik = (*this).WyznacznikSarrus();
    if((*this).WyznacznikSarrus()==0)
    {
        std::cerr << "Blad : Wyznaczik jest rowny zeru. Macierz odwrotna nie istnieje." << std::endl;
        exit(1);
    }
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            if((j+i)%2)
            {
                Wynik[i][j] = (-1)*Wyznacznik2x2(i,j);
            }
            else
            {
                Wynik[i][j] = Wyznacznik2x2(i,j);
            }
        }
    }
    Wynik = Wynik/wyznacznik;
    Wynik.Transpozycja();
    return Wynik;
}

const MacierzKw MacierzKw::operator+(const MacierzKw &M) const
{
    MacierzKw Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            Wynik[i][j]=this->daneMac[i][j]+M.daneMac[i][j];
        }
    }
    return Wynik;
}

const MacierzKw MacierzKw::operator-(const MacierzKw &M) const
{
    MacierzKw Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            Wynik[i][j]=this->daneMac[i][j]-M.daneMac[i][j];
        }
    }
    return Wynik;
}

const MacierzKw MacierzKw::operator*(const MacierzKw &M) const
{
    MacierzKw Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            Wynik[i][j]= this->daneMac[i]*M.wez_kolumne(j);
        }
    }
    return Wynik;
}

const MacierzKw MacierzKw::operator / (const double & L) const
{
    if(L==0)
    {
        std::cerr << "Blad : Nie mozna dzielic przez 0";
        exit (1);
    }
    MacierzKw Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            Wynik[i][j]=daneMac[i][j]/L;
        }
    }
    return Wynik;
}
const Wektor MacierzKw::operator*(const Wektor &W) const
{
    Wektor Wynik;
    for(int i=0;i<ROZMIAR;i++)
    {
        Wynik[i]=this->daneMac[i]*W;
    }
    return Wynik;
}

std::istream& operator >> (std::istream &str, MacierzKw &Mac)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        for(int j=0;j<ROZMIAR;j++)
        {
            str >>  Mac[i][j];
        }
    }
    return str;
}

std::ostream& operator << (std::ostream &str, const MacierzKw &Mac)
{
    for(int i=0;i<ROZMIAR;i++)
    {
        str << "|" << std::right << std::setw(3);
        for(int j=0;j<ROZMIAR;j++)
        {
            str << std::right << std::setw(5) <<  Mac[i][j] << std::setw(5);
        }
        str << std::right << std::setw(3) << "|";
        str << std::endl;
    }
}

 */