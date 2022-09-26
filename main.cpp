#include <iostream>
using namespace std;

void printWelcome() {
    //print welcome message.
<<<<<<< HEAD
    cout << "Välkommen, detta program räknar ut antal\nsedlar och mynt som en kund får tillbaka vid köp. " << endl;
=======
    cout << "Välkommen, detta program räknar ut antal sedlar och mynt som en kund får tillbaka vid köp. " << endl;
>>>>>>> main
    cout << "Vänligen följ angivna instruktioner" << endl;
}

long getInteger() {
    //Get only integers, prints error message if not int.
    long input = 0;
    while(true) {
        if (cin >> input) {
            return input;
        }
        else {
            cout << "Programmet tar bara emot heltal, försök igen.\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            input = 0;
        }
    }
}

<<<<<<< HEAD
bool checkPrice( long price){
        cout << "OBS! Kontrollera pris." << endl;
        cout << "Angivet pris: " << price << endl;
        cout << "Vill du fortsätta) (y/n)" << endl;
        string ans;
        while (true) {
            if (cin >> ans) {
                if (ans == "y") {
                    return true;
                }
                if (ans == "n") {
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

=======
>>>>>>> main
long getTotal(long balance){
    // Get number of vares and updates balance.
    long numProducts;
    cout << "Ange antal varor: ";
    numProducts = getInteger();
    for (int i = 1; i < numProducts + 1; i++) {
        long price = 0;
        cout << "Kostnad vara " << i << ": ";
        price = getInteger();
        if (price > 0) {
            balance -= price;
        }
        if (price < 0) {
            if (checkPrice(price)){
            balance -= price;
            } else {
            i--;
            } 
        }
        cout << "Att betala: " << balance * -1 << endl;
    }
    return balance;
}

long getMore(long balance) {
    // Ask for more money.
    while (balance< 0) {
            cout << "Att betala: " << balance * -1 << "sek"<< endl;
            cout << "Ange mottaget belopp:";
            balance += getInteger();
    }
    return balance;
}

void printChange( long balance) {
        int denominations[] = {1000, 500, 100, 50, 20, 10, 5, 1};
        int denom_back;
        cout << "Åter: " << balance << "kr\n";
        cout << "Valörer: \n";
        for (int denomination: denominations) {
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
    cout << "Vill du göra ett nytt köp? (y/n)" << endl;
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
    bool on = true;

    printWelcome();

    while (on) {
        long balance = 0;
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
