#include <iostream>
#include <list>
using namespace std;

int denominations[6] = {1000, 500, 100, 10, 5, 1}; //Ändra om efter valörer i landet.

void printWelcome() {
    cout << "Välkommen, detta program räknar ut antal sedlar och mynt som en kund får tillbaka vid köp. " << endl;
    cout << "Vänligen följ angivna instruktioner" << endl;
}

int main() {
    int price;
    int amount_received;
    int denominations_back;
    
    printWelcome();

    cout << "Kostnad vara: ";
    cin >> price;

    cout << "Antal kronor mottaget: ";
    cin >> amount_received;

    cout << "Kostnad: " << price << endl;
    cout << "Antal kronor mottagna: " << amount_received << endl;

    for (int denomination: denominations) {
        cout << denomination << endl;
    }
    return 0;
}
