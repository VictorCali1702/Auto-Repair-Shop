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

// Metoda zwracająca menu
void pokazMenu() {
    cout << "\n===== MAGAZYN =====\n";
    cout << "1. Dodaj produkt\n";
    cout << "2. Wyświetl produkty\n";
    cout << "3. Usuń produkt\n";
    cout << "4. Zmień ilość\n";
    cout << "5. Szukaj produktu\n";
    cout << "6. Sprawdź wartość towaru lub magazynu\n";
    cout << "0. Wyjście\n";
}

// Metoda do dodawania produktu do magazynu
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

    cout << "\nProdukt został pomyślnie dodany!\n";
}

// Metoda do wyświetlania produktów magazynu
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

// Metoda to usuwania towaru z magazynu
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

// Metoda do zmiany ilości towaru na stanie
void zmienIlosc(vector<Produkt>& lista){
    int ilosc;
    string nazwa;

    if (lista.empty()) {
        cout << "\nBrak towaru na stanie\n";
        cout << "Brak możliwości zmianu ilości\n";

        return;
    }

    cin.ignore();
    cout << "Jakiemu towarowi chcesz zmienić ilość? ";
    getline(cin, nazwa);

    for(size_t i = 0; i < lista.size(); i++) {
        if (lista[i].nazwa == nazwa) {

            cout << "Podaj nową ilość: ";
            cin >> ilosc;

            if (ilosc < 0){
                cout << "Zła wartość\n";
                return;
            }
            
            lista[i].ilosc = ilosc;
            
            cout << "\nNowy stan " << nazwa 
                 << " wynosi " << ilosc 
                 << " sztuk\n";

            return;
        }
    } 
    cout << "\nNie znaleziono produktu.\n";
}

// Metoda do szukania naszych produktów
void szukajProduktu(vector<Produkt>& lista){
    string nazwa;

    if (lista.empty()) {
        cout << "\nMagazyn pusty\n";
        return;
    }

    cin.ignore();
    cout << "Wyszukaj produktu: ";
    getline(cin, nazwa);

    for(size_t i = 0; i < lista.size(); i++){
        
        if(lista[i].nazwa == nazwa){

            cout << "\n===== Znaleziono produkt! =====\n";
            cout << "\nInformacje produktu: " << nazwa << endl;
            
            cout << "Nazwa: " << lista[i].nazwa << "\n";
            cout << "Cena: " << lista[i].cena << "PLN" << "\n";
            cout << "Ilość: " << lista[i].ilosc << " sztuk\n";
            cout << "Producent: " << lista[i].producent << "\n";
            
            return;
        }
    }
    cout << "\nBrak danego towaru!\n";
}

// Metoda licząca wartość naszego magazynu
void wartoscMagazynu(vector<Produkt>& lista){
    
    string nazwa;
    int wybor;

    if(lista.empty()){
        cout << "\nBrak towaru\nWartość magazynu wynosi 0.00 PLN\n";
        return;
    }
    cout << "\n===== Wartość towarów na magazynie =====\n";
    cout << "1. Sprawdź wartość danego produktu\n";
    cout << "2. Pokaż wartość całego magazynu\n";
    cout << "\nWybór: ";
    cin >> wybor;

    switch(wybor){
        case 1:
            cin.ignore();
            cout << "\nProdukt: ";
            getline(cin, nazwa);

            for(size_t i = 0; i < lista.size(); i++){
                if(lista[i].nazwa == nazwa){
                    double wartosc = lista[i].cena * lista[i].ilosc;

                    cout << "\nWartość towaru na magazynie wynosi: " << fixed << setprecision(2) << 
                        wartosc << " PLN\n";
                
                    return;
                }
            }
            
            cout << "\nNie znaleziono danego produktu!\n";
            break;

        case 2:
            {
                double magazynWartosc = 0;

                for(size_t i = 0; i < lista.size(); i++){
                    double wartosc = lista[i].cena * lista[i].ilosc;
                    magazynWartosc += wartosc;
                }

                cout << "\nWartość magazynu wynosi: " << fixed << setprecision(2) << magazynWartosc << " PLN\n";
                
                break;
            }  
             
        default:
            cout << "\nZły wybór\n";
            break;
    }   

}

// Główna część naszego programu
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
                zmienIlosc(lista);
                break;
            case 5:
                szukajProduktu(lista);
                break;
            case 6:
                wartoscMagazynu(lista);
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