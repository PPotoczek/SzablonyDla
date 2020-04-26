#include <iostream>
#include "Wektor.hh"
#include "LZespolona.hh"
//#include "Macierz.hh"
//#include "UkladRownanLiniowych.hh"



using namespace std;

int main()
{
    Wektor<LZespolona , 2> W1;
    Wektor<LZespolona , 2> W2;
    Wektor<double , 2> W3;
    Wektor<double , 2> W4;
    cin >> W1 >> W2;
    cin >> W3 >> W4;
    LZespolona skalar1;
    double skalar2;
    skalar1 = W1 * W2;
    skalar2= W3 * W4;
    cout << W1 << endl << W2 << endl << skalar1 << endl;
    cout << W3 << endl << W4 << endl << skalar2;
}
