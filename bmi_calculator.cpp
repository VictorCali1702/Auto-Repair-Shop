#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main () {
    string imie;
    double waga;
    string plec;
    int wiek;
    double wzrost;

    cout << "=== Witaj ===\n";
    cout << "=== Kalkulator BMI ===\n";

    cout << "Podaj swoje imię: ";
    cin >> imie;
    cout << "Podaj płeć: ";
    cin >> plec;
    cout << "Podaj wiek: ";
    cin >> wiek;
    cout << "Podaj wagę (kg): ";
    cin >> waga;
    cout << "Podaj wzrost (cm): ";
    cin >> wzrost;

    double wzrost_m = wzrost / 100;

    double BMI = waga / pow(wzrost_m, 2);

    cout << "\nBMI wynosi: " << fixed << setprecision(2) << BMI;
    cout << "\nTwoje BMI: ";
    
    if (BMI <= 18.5){
        cout << "Niedowaga";
    } else if (BMI <= 24.9){
        cout << "Prawidłowa masa ciała";
    } else if (BMI <= 29.9) {
        cout << "Nadwaga";
    } else {
        cout << "Otyłość";
    }

    return 0;
}