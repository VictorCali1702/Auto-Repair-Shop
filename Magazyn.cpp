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
    cout << "\n===== MAGAZYN =====\n";
    cout << "1. Dodaj produkt\n";
    cout << "2. Wyświetl produkty\n";
    cout << "3. Usuń produkt\n";
    cout << "4. Zmień ilość\n";
    cout << "5. Szukaj produktu\n";
    cout << "0. Wyjście\n";
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
    cout << "\n===== STAN MAGAZYNU =====\n";

    if (lista.empty()) {
        cout << "\nBrak towaru\n";
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

void usunProdukt(vector<Produkt>& lista) {
    string nazwa;
    if (lista.empty()){
        cout << "\nBrak towaru na stanie.\n";    
        return;
    }
    
    cin.ignore();
    cout << "Podaj nazwę produktu do usunięcia: ";
    getline(cin, nazwa);

    for (size_t i = 0; i < lista.size(); i++){
        if (lista[i].nazwa == nazwa){
            lista.erase(lista.begin() + i);

            cout << "\nProdukt został pomyślnie usunięty!\n";

            return;
        }
    }

    cout << "\nNie znaleziono produktu.\n";

}


int main (){
    vector<Produkt> lista;
    int wybor;

    do {
        pokazMenu();
        cout << "\nWybierz opcję: ";
        cin >> wybor;

        switch (wybor) {
            case 1:
                dodajProdukt(lista);
                break;
            case 2:
                wyswietlProdukty(lista);
                break;
            case 3:
                usunProdukt(lista);
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                cout << "Program zakończony!\n";
                break;
            default:
                cout << "Zły wybór\n";
        }
    } while (wybor != 0);

    return 0;
}