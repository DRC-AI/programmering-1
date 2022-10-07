#include<cctype>
#include<iostream>
#include<string>
using namespace std;

void printGoodbye() {
    cout << "Tack för att du använt våra tjänst, välkommen åter!" << endl;
}
void printWelcome() {
	cout << "Välkommen till Banken." << endl;
}

void printMenuOptions(){
    cout << fixed;
    cout.precision(2);
	cout << "Ange vilken tjänst du önskar använda." << endl;
	cout << "Välj med motsvarande bokstav, tryck sedan Enter." << endl;
	cout << "[I]nsättningl [U]ttag [S]aldo [R]äntebetalning [A]vsluta" << endl;
}

int getChoice() {
	char choice;	
	while (true){
		if (cin >> choice){
			choice = tolower(choice);
			return (int)choice;
		}
	}
}
void restrictLength(string* number){
	double temp = stof(*number);

	temp = temp * 100;
	temp = (int)temp;
	temp = temp / 100;

	*number = to_string(temp);
	}

bool isNumber(string number) {
    double validated;
    try {
        validated = stod(number);
        return true;
    } catch (exception& except1) {
        cout << "Fel format på inmatning." << endl;
        return false;
    }
}

bool isPositive(string number) {
    if (number[0] == '-'){
        return false;
        } else {
            return true;
        }
}


void makeDeposit(double* balance){
	string deposit;
	string* pDeposit = &deposit;
	while (true){
		cout << "Ange summa för insättning: ";
		cin >> deposit;
		
		if (isNumber(deposit) && isPositive(deposit)){
			restrictLength(pDeposit);
			*balance += stod(*pDeposit);
			cout << "Saldo: " << *balance << endl;
			break;
		} else {
			cout << "Kunde inte göra insättning" << endl;
			if (!(isPositive(deposit))){
				cout << "Minusbelopp ej tillåtna." << endl;
			}
			if (!(isNumber(deposit))){
				cout << "Icke giltigt nummer." << endl;
			}
			break;
		}
	}
}

void makeWithdrawal(double* balance){
	string withdrawal;
	string* pwithdrawal = &withdrawal;
	while (true){
		cout << "Ange summa för uttag: ";
		cin >> withdrawal;
		
		if (isNumber(withdrawal) && isPositive(withdrawal) && *balance >= 0 && *balance >= stod(withdrawal)){
			restrictLength(pwithdrawal);
			*balance -= stod(*pwithdrawal);
			cout << "Saldo: " << *balance << endl;
			break;
		} else {
			cout << "Kunde inte göra uttag." << endl;
			if (*balance <= 0 || stod(withdrawal) > *balance){
				cout << "Saldo för lågt." << endl;
			}
			break;
		}
	}
}

void showBalance(double* balance){
	cout << "Saldo: " << *balance << endl;
}

void exit(bool *powerOn){
	*powerOn = false;
}

bool validateInteger(string number){
	for (char num: number){
		if (!(isdigit(num))){
			return false;
		}
	}
	return true;
}

void calcRentSavings(){
	string input;
	int years;
	int ySaving;
	double interest;
	unsigned int balance = {0};
	while (true){
		cout << "Ange hur många år du vill spara: ";
		cin >> input;
		if (validateInteger(input)){
			years = stoi(input);
		} else {
			cout << "Ogiltig data, endast heltal tillåtna" << endl;
			break;
		}

		cout << "Ange insättning per år: ";
		cin >> input;
		if (validateInteger(input)){
			ySaving = stoi(input);
		} else {
			cout << "Ogiltig data, endast heltal tillåtna" << endl;
			break;
		}

		cout << "Ange räntesats: ";
		if (cin >> interest){
			interest = (interest / 100.0) + 1.0;
		} else {
			cout << "Ogiltig data, endast siffor tillåtna" << endl;
			break;
		}
		for (int i = 1; i < years + 1; i++){
			balance = (balance + ySaving) * interest;	
		}
        cout << "Efter "<< years << " års sparande skulle du ha " << balance << "kr på kontot." << endl;
		break;
	}
}


int main() {
	bool on = true;
	bool* pOn = &on;
	double balance = {0};
	double* pBalance = &balance;
	
	printWelcome();
	while (on){
		printMenuOptions();
		int choice = getChoice();

		switch (choice){
			case (int)'i':
				makeDeposit(pBalance);
				continue;
			case (int)'u':
				makeWithdrawal(pBalance);
				continue;
			case (int)'s':
				showBalance(pBalance);
				continue;
			case (int)'r':
				calcRentSavings();
				continue;
			case (int)'a':
				exit(pOn);
				continue;
			default:
				cout << "Valet matchade inget av alternativen" << endl;
				continue;
		}
	}
    printGoodbye();
	return 1;
}
