#include <iostream>
using namespace std;


void printWelcome() {
    cout << "Välkommen, detta program räknar ut antal sedlar och mynt som en kund får tillbaka vid köp. " << endl;
    cout << "Vänligen följ angivna instruktioner" << endl;
}

int getInteger() {
    int input = 0;
    while(true) {
        if (cin >> input) {
            return input;
        }
        else {
            cout << "Fel typ av data, försök igen.\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            input = 0;
        }
    }
    }

int getTotal(int balance){
    int numProducts;
    cout << "Ange antal varor: ";
    numProducts = getInteger();
    for (int i = 1; i < numProducts + 1; i++) {
        cout << "Kostnad vara " << i << ": ";
        balance -= getInteger();
    }
    cout << "Total kostnad:" << balance * -1 << "kr" << endl;
    return balance;
}


int getMore(int balance) {
    while (balance< 0) {
            cout << "Kvar att betala: " << balance * -1 << "sek"<< endl;
            cout << "Ange mottaget belopp:";
            balance += getInteger();
    }
    return balance;
}

void printChange( int balance) {
        int denominations[] = {1000, 500, 100, 50, 20, 10, 5, 1};
        int denom_back;
        cout << "Totalt tillbaka: " << balance << "kr\n";
        cout << "Valörer: \n";
        for (int denomination: denominations) {
            // Deconstructed modulus.
            denom_back = balance / denomination;
            balance = balance % denomination;
            // Only print what costumer needs back.
            if (denom_back > 0) {
                cout << denom_back << "x" << denomination << "kr" << endl;
            }
        }
}

bool askRestart() {
    //Asks if user wants to make another purchase.
    string input;
    cout << "Vill du göra ett till köp? (y/n)" << endl;
    while (true) {
        if (cin >> input) {
            if (input == "y") {
                return true;
            }
            if (input == "n") {
                return false;
            } else {
                cout << "Var god svara med y för ja eller n för nej.\n";
            }
        } else {
            cout << "Var god svara med y för ja eller n för nej\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int main() {
    int balance = 0;
    bool on = true;

    printWelcome();

    while (on) {
        balance = getTotal(balance);
        cout << "Ange mottaget belopp:";
        balance += getInteger();
        
        //Low balance
        if (balance < 0) {
            balance = getMore(balance);
        }
        //Even balance
        if (balance == 0) {
            cout << "Jämt belopp.\n";
        }
        //High Balance
        if (balance > 0) {
            printChange(balance);
        }
        on = askRestart();
    }

    return 0;
}
