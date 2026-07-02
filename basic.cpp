#include <iostream>

using namespace std;

int main() {
    string name;
    int age;
    cout << "Hello, what is your name? ";
    cin >> name;
    cout << "How old are you? ";
    cin >> age;
    
    cout << "Hello " << name << ". Nice to meet you!\n";
    cout << "You are " << age << " years old!\n";

    if (age >= 18) {
        cout << "You are adult.";
    } else {
        cout << "You are a child.";
    }

    return 0;
}