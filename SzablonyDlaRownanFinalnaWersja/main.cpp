#include <iostream>
#include "UkladRownanLiniowych.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "LZespolona.hh"

using namespace std;

int main()
{
    char wybor;
    cin >> wybor;
    UkladRownanLiniowych<double, 5>R_Uklad;
    Wektor<double, 5>R_Rozwiazanie;
    MacierzKw<double, 5>R_Macierz_pom;
    Wektor<double, 5>R_Wektor_pom;
    UkladRownanLiniowych<LZespolona, 5> Z_Uklad;
    Wektor<LZespolona, 5>Z_Rozwiazanie;
    MacierzKw<LZespolona, 5>Z_Macierz_pom;
    Wektor<LZespolona, 5>Z_Wektor_pom;
    cout << endl << " Start programu " << endl << endl;
    switch (wybor)
    {
        case 'r':
            {
                cin >> R_Uklad;
                if(!cin.good())
                {
                    cerr << "Blad, zle wpisane dane";
                    exit (1);
                }
                cout << endl << "Uklad rownan o wspolczynnikach rzeczywistych" << endl;
                cout << "Macierz A: " << endl << endl;
                R_Macierz_pom = R_Uklad.Wez_Macierz();
                cout << R_Macierz_pom << endl;
                cout << "Wektor wyrazów wolnych B: " << endl << endl;
                R_Wektor_pom = R_Uklad.Wez_Wektor();
                cout << R_Wektor_pom << endl << endl;
                cout << "Rozwiazanie X =(x1, x2, x3, x4, x5): " << endl << endl;
                R_Rozwiazanie = R_Uklad.Oblicz_Odwrotna();
                cout << R_Rozwiazanie << endl << endl;
                break;
            }
        case 'z':
            {
                cin >> Z_Uklad;
                if(!cin.good())
                {
                    cerr << "Blad, zle wpisane dane";
                    exit (1);
                }
                cout << endl << "Uklad rownan o wspolczynnikach zespolonych" << endl;
                cout << "Macierz A: " << endl << endl;
                Z_Macierz_pom = Z_Uklad.Wez_Macierz();
                cout << Z_Macierz_pom << endl;
                cout << "Wektor wyrazów wolnych B: " << endl << endl;
                Z_Wektor_pom = Z_Uklad.Wez_Wektor();
                cout << Z_Wektor_pom << endl << endl;
                cout << "Rozwiazanie X =(x1, x2, x3, x4, x5): " << endl << endl;
                Z_Rozwiazanie = Z_Uklad.Oblicz_Odwrotna();
                cout << Z_Rozwiazanie << endl << endl;
                break;
            }
        default:
        {
            cout << "Blad, zla opcja" << endl;
            exit (1);
        }
    }
}
