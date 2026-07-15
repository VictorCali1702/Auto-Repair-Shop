#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    cout << "Witaj w programie Finanse osobiste!\n";
    double przychod;

    cout << "Podaj przychód brutto: ";
    cin >> przychod;
    cout << "\nPodany przychód brutto: " << przychod << " PLN\n";
    
    double podatek = 32;
    double podatekKwota = przychod * (podatek / 100.0);
    cout << "\nPodatek od przychodu " << przychod << " PLN wynosi: " << podatekKwota << endl;
    
    double kwotaNetto = przychod - podatekKwota;
    cout << "\nPrzychód Netto: " << kwotaNetto << " PLN";
    cout << "opcje";
    cout << "Opcje finansowania";
    
    return 0;
}