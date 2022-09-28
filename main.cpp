#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;

void printWelcome() {
    //print welcome message.
    cout << "Välkommen, detta program räknar ut antal\nsedlar och mynt som en kund får tillbaka vid köp. " << endl;
    cout << "Vänligen följ angivna instruktioner" << endl;
}

float getFloat() {
    //Get only integers, prints error message if not int.
    string input;
    float converted_input;
    while(true) {
        cin >> input;
        try {
            converted_input = stof(input);
            return converted_input;
        } catch (exception error_message) {
            cout << "Fel, försök igen." << endl;
        }
             
    }
}

bool isInt(string num) {
    bool is_int = true;
    for (char n: num) {
        if (!(isdigit(n))) {
            is_int = false;
        }
    }
    return is_int;
}

int getInteger() {
    //Get only integers, prints error message if not int.
    string input;
    int converted_input;
    while(true) {
        cin >> input;
        if (!(isInt(input))) {
            cout << "Fel, försök igen." << endl;
            continue;
        } else {
            converted_input = stoi(input);
            return converted_input;
        } 
    }
}

bool getYesNo(){
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

bool checkPrice( float price){
        cout << "\nOBS! Kontrollera pris." << endl;
        cout << "Angivet pris: " << price << endl;
        cout << "Vill du fortsätta) (y/n)" << endl;
        bool ans = getYesNo();
        return ans;
        
}
float getTotal(float balance){
    // Get number of vares and updates balance.
    int numProducts;
    cout << "Ange antal varor: ";
    numProducts = getInteger();
    for (int i = 1; i < numProducts + 1; i++) {
        float price = 0;
        cout << "Kostnad vara " << i << ": ";
        price = getFloat();
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
        if (i < numProducts){
            cout << "Att betala: " << balance * -1 << "sek" << endl;
        }
    }
    return balance;
}

float getMore(float balance) {
    // Ask for more money.
    while (balance< 0) {
            cout << "Att betala: " << balance * -1 << "sek"<< endl;
            cout << "Ange mottaget belopp:";
            balance += getFloat();
    }
    return balance;
}

void printChange(float balance) {
        float denominations[] = {1000, 500, 100, 50, 20, 10, 5, 1, 0.5};
        float denom_back;
        bool rounded = false;

        //Rounding
        if ((balance - (int)balance > 0)){
            float rest = balance - (int)balance;
            if (rest >= 0.75){
                balance = int(balance) + 1;
            }
            if (rest < 0.75 && rest >= 0.25){
                balance = int(balance) + 0.5;
            }
            if (rest < 0.25){
                balance = int(balance);
            }
        }
        cout << "\nÅter: " << balance << "kr\n";
        cout << "Valörer: \n";
        for (float denomination: denominations) {
            if (denomination >= 1) {
                denom_back = (int)balance / (int)denomination;
            } else if (denomination == 0.5) {
                denom_back = balance / denomination;
            }
            if (denom_back > 0) {
                if (denomination >= 1){
                    cout << denom_back << "x" << denomination << "kr" << endl;
                } else if (denomination == 0.5){
                    cout << denom_back << "x" << denomination * 100 << "öre" << endl;
                }
            }
            balance = fmod((double)balance, double(denomination));

        }
}

bool askRestart() {
    //Asks if user wants to make another purchase.
    string input;
    cout << "Vill du göra ett nytt köp? (y/n)" << endl;
    bool ans = getYesNo();
    return ans;
}

int main() {
    bool on = true;

    printWelcome();

    while (on) {
        float balance;
        balance = getTotal(balance);

        if (balance > 0) {
            cout << "Ange mottaget belopp:";
            balance += getFloat();
        }
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
