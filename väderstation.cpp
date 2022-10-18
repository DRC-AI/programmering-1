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
            return "Namn: " + namn + "\nTemperatur: " + to_string(temp) + "\n";
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
    stad städer[255];
    stad *pStäder = städer;
    string namn;
    int temp;
    int antal_städer;
    
    cout << "ANGE ANTAL STÄDER DU VILL LÄGGA TILL: ";
    cin >> antal_städer;

    for (int i = 0; i < antal_städer; i++){
        cout << "VÄRDEN STAD NUMMER " << i + 1 << endl;
        cout << "NAMN: ";
        cin >> namn;
        cout << "TEMPERATUR: ";
        cin >> temp;
        städer[i] = stad(namn, temp); 
    }

    //städer[0] = stad("norrköping", 14);
    //städer[1] = stad("söderköping", 11); 
    //städer[2] = stad("stockholm", 13);
    //städer[3] = stad("funäsdalen", 7);
    //städer[4] = stad("borås", 10);

    bubblesort(städer, antal_städer);

    cout << "\n\nAlla Angivna länder sorterade efter temperatur." << endl;
    for (int i = antal_städer -1; i >= 0; i--){
        cout << städer[i].ToString() ;
    }
    cout << "\n\nSöker igenom städer för temperaturen 10..." << endl;
    int index = linsok(städer, antal_städer, 10);
        if (index == -1){
            cout << "Finns ingen stad med temperaturen 10." << endl;
        } else {
            cout << "Stad med temperatur 10 hittades!" << endl;
            cout << "Staden har index: " << index << endl;
            cout << städer[index].ToString() << endl;
    }

}

