#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;

void   printWelcome();
void   printGoodbye();
bool   isNum(string num);
double getFloat();
bool   getYesNo();
bool   checkPrice(float);
float  getTotal(double);
float  getPayment(double);
double roundChange(double);
void   printChange(double);
bool   askRestart();

int main() {
    bool on = true;

    printWelcome();

	while (on) {
		double balance = 0;

		balance = getTotal(balance);
		//Low balance
		if (balance < 0) {
			balance = getPayment(balance);
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
    printGoodbye();
    return 0;
}

void printWelcome() {
	cout << "Välkommen, detta program räknar ut antal" << endl;
	cout << "sedlar och mynt som en kund får tillbaka vid köp." << endl;
	cout << "Vänligen följ angivna instruktioner" << endl;
}

void printGoodbye(){
	cout << "Välkommen åter!";
}

bool isNum(string num) { //checks if input contains non wanted characters.
	for (char n: num) {
		if (!(isdigit(n)) && n != '.' && n != '-' ) {
			return false;
		}
	}
	return true;
	}

double getFloat() { //returns input as float.
	string input;
	double rounded;
	double converted_input;

	while(true) {
		cin >> input;
		try {
			if (!(isNum(input))){
				cout << "Felaktigt format.\nFörsök igen: ";
				continue;
			} else if (input.length() > 8){
				cout << "För stor siffra.\nFörsök igen: ";
			continue;
			}
			converted_input = stof(input);
			//round to two decimals for safety.
			rounded = converted_input * 100;
			rounded = (int)rounded / 100.0;
			return rounded;
		} catch (exception error_message) {
			cout << "Felaktigt format.\nFörsök igen: ";
		}
	     
	}
}

bool getYesNo(){ //used for y/n questions.
	string ans;
	while (true) {
		if (cin >> ans) {
			if (ans == "j") {
			    return true;
			}
		if (ans == "n") {
			return false;
		} else {
			cout << "j = Ja n = Nej.\n";
		}
		} else {
			cout << "j = Ja n = Nej\n";
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

bool checkPrice( float price){ //used for confirmation if unexpected value.
	cout << "\nOBS! Kontrollera pris." << endl;
	cout << "ANGIVET PRIS: " << price << endl;
	cout << "Vill du fortsätta) (j/n)" << endl;
	bool ans = getYesNo();
	return ans;
        
}
float getTotal(double balance){ //returns purchase cost.
	int i = {1};
	float price;
	cout << "För att gå till betalning, ange 0." << endl;
	do {
		cout << "Kostnad vara " << i << ": ";
		price = getFloat();
		if (price < 0) {
			if (checkPrice(price)){
				balance = balance + price;
			} else {
			continue;
			}
		} else {
			balance = balance + price;
		}
		i++;
	} while (price != 0);
	return -balance;
}

float getPayment(double balance) { // returns received payment.
	while (balance< 0) {
		cout << "Att betala: " << balance * -1 << "sek"<< endl;
	    	cout << "Ange mottaget belopp: ";
	    	balance += getFloat();
	}
	return balance;
}

double roundChange(double balance) { // rounds change to nearest 50öre.	
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
        return balance;

}

void printChange(double balance) { // prints change in denominations.
	float denominations[] = {1000, 500, 100, 50, 20, 10, 5, 1, 0.5};
	float denom_back;
	bool rounded = false;
	balance = roundChange(balance);
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
	    	    		cout << denom_back << " x " << denomination << "kr" << endl;
	    	    	} else if (denomination <= 0.5){
	    	    		cout << denom_back << " x " << denomination * 100 << "öre" << endl;
	    	    	}
	    	}
	balance = fmod((double)balance, double(denomination));

	}
}

bool askRestart() { //Asks if user wants to make another purchase.
	string input;
	cout << "\nVill du göra ett nytt köp? (j/n)" << endl;
	bool ans = getYesNo();
	return ans;
}
