#include<iostream>
using namespace std;

class stad {
    public:
        string namn;
        int temp;

        stad() {}
        stad(string n, int t){
            namn = n;
            temp = t;
        }
    public:
        string ToString(){
            return "Stad: " + namn + "\nTemperatur: " + to_string(temp);
        }
};

int linsok(stad *städer,int n, int söktemp){
    for (int i = 0; i < n; i++){
        if (städer[i].temp == söktemp){
            return i;
        }
    }
    return -1;
}

void bubblesort(stad städer[], int antal_städer){
    bool was_swaped;
    int counter = {0};
    bool finished = false;

    while (finished != true){
        was_swaped = false;
        if (städer[counter+1].temp > städer[counter].temp){
            swap(städer[counter+1], städer[counter]);
            was_swaped = true;
        }
        counter += 1;

        if (counter + 1 == antal_städer && was_swaped == false){
            finished = true;
        } else if (counter + 1 == antal_städer){
            counter = 0;
        }
    }
}



int main() {
    stad städer[10];

    städer[0] = stad("norrköping", 14);
    städer[1] = stad("söderköping", 11); 
    städer[2] = stad("stockholm", 13);
    städer[3] = stad("funäsdalen", 7);
    städer[4] = stad("borås", 10);

    int antal_städer = 5;

    //cout << "Antal städer: ";
    //cin >> antal_städer;
    //for (int i = 0; i < antal_städer; i++){
    //    cout << "Ange Namn: ";
    //    städer[i].hämtaNamn();
    //    cout << "Ange Temperatur: ";
    //    städer[i].hämtaTemp();
    //}
    stad *pStäder = städer;

    bubblesort(pStäder, antal_städer);

    for (int i = 0; i < antal_städer; i++){
        cout << städer[i].namn << " " << städer[i].temp << "\n";
    }

}

