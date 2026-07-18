#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void systemKsiegowy() {
    cout << "1. Dodaj przychód\n";
    cout << "2. Dodaj wydatek\n";
    cout << "3. Wyświetl wszystkie opercje\n";
    cout << "4. Saldo konta\n";
    cout << "5. Usuń operację\n";
    cout << "6. Zapisz do pliku\n";
    cout << "7. Wczytaj z pliku\n";
    cout << "0. Koniec Programu\n";
}

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

    
    return 0;
}