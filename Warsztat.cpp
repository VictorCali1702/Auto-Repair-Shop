#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Zlecenie {
    string klient;
    string usluga;
    double cena;
};

void pokazMenu() {
    cout << "\n=== Warsztat samochodowy ===\n";
    cout << "1. Dodaj zlecenie\n";    
    cout << "2. Pokaż wszystkie zlecenia\n";
    cout << "3. Wystaw rachunek\n";
    cout << "0. Wyjście\n";
    cout << "Wybierz opcje: ";
} 

void dodajZlecenie(vector<Zlecenie>& lista) {
    Zlecenie z;

    cin.ignore();
    cout << "Klient: ";
    getline(cin, z.klient);
    
    cout << "Usługa: ";
    getline(cin, z.usluga);

    cout << "Cena: ";
    cin >> z.cena;

    lista.push_back(z); // oznacza dodaj element na koniec wektora

    cout << "Dodano zlecenie!\n";

}

void pokazZlecenie(const vector<Zlecenie>& lista) {
    cout << "\n=== LISTA ZLECEŃ ===\n";

    if (lista.empty()) {
        cout << "Brak zleceń.\n";
        return;
    }

    for(size_t i = 0; i < lista.size(); i++){
        cout << i + 1 << ". "
        << lista[i].klient << " | "
        << lista[i].usluga << " | "
        << lista[i].cena << " PLN\n";
    }
}

void rachunek(const vector<Zlecenie>& lista){
    if (lista.empty()){
        cout << "Brak danych.\n";
        return;
    }

    int nr;
    cout << "Podaj numer zlecenia: ";
    cin >> nr;
    
    if (nr < 1 || nr > lista.size()){
        cout << "Nieprawidłowy numer!\n";
        return;
    }

    Zlecenie z = lista[nr - 1];
    double vat = z.cena * 0.23;
    double brutto = z.cena + vat;

    cout << "\n===== RACHUNEK =====\n";
    cout << "Klient: " << z.klient << "\n";
    cout << "Usluga: " << z.usluga << "\n";
    cout << "Netto: " << z.cena << " PLN\n";
    cout << "Vat (23%): " << vat << " PLN\n";
    cout << "Brutto: " << brutto << " PLN\n";
    cout << "==========================\n";
}

int main() {
    vector<Zlecenie> lista;
    int wybor;

    do {
        pokazMenu();
        cin >> wybor;
        
        switch (wybor) {
            case 1:
                dodajZlecenie(lista);
                break;
            case 2:
                pokazZlecenie(lista);
                break;
            case 3:
                rachunek(lista);
                break;
            case 0:
                cout << "Koniec programu!\n";
                break;
            default:
                cout << "Zły wybór\n";
        } 
    } while(wybor != 0);
    cout << "Hello";
    return 0;
} 