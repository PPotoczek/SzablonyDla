#include <iostream>
#include<math.h>
#include "LZespolona.hh"
using std::cout;
using std::cin;
using std::endl;

const double & LZespolona::Wez_Re()
{
    return re;
}

const double & LZespolona::Wez_Im()
{
    return im;
}

void LZespolona::Zmien_Re(double &re1)
{
    re = re1;
}

void LZespolona::Zmien_Im(double &im1)
{
    im = im1;
}

void LZespolona:: Sprzezenie()
{
    im = -im;
}

double LZespolona::Modul()
{
    double Wynik;
    Wynik = sqrt(re*re + im*im);
    return(Wynik);
}

LZespolona LZespolona::operator * (double rzeczywista) const
{
    LZespolona Wynik;
    Wynik.re = this->re*rzeczywista;
    Wynik.im = this->im*rzeczywista;
    return Wynik;
}

LZespolona LZespolona::operator / (double rzeczywista) const
{
    LZespolona Wynik;
    if(rzeczywista == 0)
    {
        cout << "Blad, nie mozna dzielic przez zero" << endl;
        exit (1);
    }
    Wynik.re = this->re/rzeczywista;
    Wynik.im = this->im/rzeczywista;
    return Wynik;
}
LZespolona LZespolona::operator + (LZespolona L) const
{
    LZespolona  Wynik;
    Wynik.re = this->re + L.re;
    Wynik.im = this->im + L.im;
    return Wynik;
}

LZespolona LZespolona::operator - (LZespolona L) const
{
    LZespolona Wynik;
    Wynik.re = this->re - L.re;
    Wynik.im = this->im - L.im;
    return Wynik;
}

LZespolona LZespolona::operator * (LZespolona L) const
{
    LZespolona Wynik;
    Wynik.re = this->re * L.re - this->im * L.im;
    Wynik.im = this->re * L.im + this->im * L.re;
    return Wynik;
}

LZespolona LZespolona::operator / (LZespolona L) const
{
    LZespolona Wynik;
    double wynik_pom;
    L.Sprzezenie();
    Wynik.re = this->re * L.re - this->im * L.im;
    Wynik.im = this->re * L.im + this->im * L.re;
    wynik_pom = L.Modul()*L.Modul();
    Wynik = Wynik/wynik_pom;
    return(Wynik);
}

LZespolona LZespolona::operator = (double liczba)
{
    re = liczba;
    im = 0;
    return *this;
}

bool LZespolona::operator == (const LZespolona &L)
{
    bool Wynik;
    if(this->re == L.re && this->im == L.im)
    {
        Wynik = true;
    }
    else
    {
        Wynik = false;
    }
    return(Wynik);
}

bool LZespolona::operator == (const double L)
{
    bool Wynik;
    if(this->re == L && this->im == 0)
    {
        Wynik = true;
    }
    else
    {
        Wynik = false;
    }
    return(Wynik);
}

bool LZespolona::operator != (const LZespolona &L)
{
    bool Wynik;
    if(*this==L)
    {
        Wynik = false;
    }
    else
    {
        Wynik = true;
    }
    return(Wynik);
}

bool LZespolona::operator != (const double L)
{
    bool Wynik;
    if(*this==L)
    {
        Wynik = false;
    }
    else
    {
        Wynik = true;
    }
    return(Wynik);
}

std::ostream & operator << (std::ostream & str, LZespolona &Wynik)
{
    double temp_re = Wynik.Wez_Re();
    double temp_im = Wynik.Wez_Im();
    str << "(" << temp_re << std::showpos << temp_im << std::noshowpos << "i)";
    return str;
}

std::istream & operator >> (std::istream & str, LZespolona &L)
{
    double temp_re;
    double temp_im;
    char znak;
    str >> znak;
    if(znak =='(')
    {
        str >> temp_re;
        L.Zmien_Re(temp_re);
        str >> temp_im;
        L.Zmien_Im(temp_im);
        str >> znak;
        if(znak != 'i')
        {
            str.setstate(std::ios::failbit);
        }
        else
        {
            str >> znak;
            if(znak!=')')
            {
                str.setstate(std::ios::failbit);
            }
            else
            {
                return str;
            }
        }
    }
    else
    {
        str.setstate(std::ios::failbit);
    }
    return str;
}