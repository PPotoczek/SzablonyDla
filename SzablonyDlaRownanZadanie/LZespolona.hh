#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

class LZespolona
{
private:
    double   re;
    double   im;
public:
    LZespolona() : re(0), im(0) {};
    LZespolona(double re1, double im1) : re(re1), im(im1) {};
    const double & Wez_Re();
    const double & Wez_Im();
    void Zmien_Re(double &re1);
    void Zmien_Im(double &im1);
    void Sprzezenie();
    double Modul();
    LZespolona operator / (double rzeczywista) const;
    LZespolona operator + (LZespolona L) const;
    LZespolona operator - (LZespolona L) const;
    LZespolona operator * (LZespolona L) const;
    LZespolona operator / (LZespolona L) const;
    LZespolona operator = (double liczba);
    bool operator == (const LZespolona &L);
    bool operator != (const LZespolona &L);
};

std::ostream & operator << (std::ostream & str, LZespolona &Wynik);

std::istream & operator >> (std::istream & str, LZespolona &L);

#endif
