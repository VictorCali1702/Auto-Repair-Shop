#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Produkt {
    string nazwa;
    double cena;
    int ilosc;
    string producent;
};

void pokazMenu() {
    cout << "\n===== MAGAZYN =====";
    cout << "1. Dodaj produkt";
    cout << "2. Wyświetl produkty";
    cout << "3. Usuń produkt";
    cout << "4. Zmień ilość";
    cout << "5. Szukaj produktu";
    cout << "0. Wyjście";
}

void dodajProdukt(vector<Produkt>& lista) {
    Produkt p;

    cin.ignore();
    cout << "Nazwa: ";
    getline(cin, p.nazwa);

    cout << "Cena: ";
    cin >> p.cena;

    cout << "Ilość: ";
    cin >> p.ilosc;

    cin.ignore();
    cout << "Producent: ";
    getline(cin, p.producent);

    lista.push_back(p);

    cout << "Produkt został pomyślnie dodany!\n";
}

void wyswietlProdukty(vector<Produkt>& lista) {
    cout << "\n===== STAN MAGAZYNU =====";

    if (lista.empty()) {
        cout << "Brak towaru";
        return;
    }

    for(size_t i=0; i < lista.size(); i++){
        cout << i + 1 << ". "
        << lista[i].nazwa << " | "
        << lista[i].cena << " PLN" << " | "
        << lista[i].ilosc << " sztuk" << " | "
        << lista[i].producent << "\n";
    }
}




int main (){
    cout << "f":

    return 0;
}