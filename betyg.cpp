#include<iostream>
#include<string>
using namespace std;

void valkomstMeddelande(){
    cout << "Välkommen till lärarhjälpen 2.0, detta program \n";
    cout << "hjälper dig som lärare att hålla koll på dina elevers betyg.\n";
    cout << "För att använda programmet, vänligen följ angivna instruktioner.\n";
}

void LäsPoäng(string *amnen, int *poang){
    for (int i = 0; i <= 4; i++){
        cout << "Ange poäng för ämnet " << amnen[i] << ": ";
        cin >> *(poang + i);
    }
}

void omvandla(int *poang, char *betyg){
    for (int i = 0; i <= 4; i++){
           if (*(poang + i) == 100){
               *(betyg + i) = 'A';
           } else if (*(poang + i) < 100 && *(poang + i) >= 50){
               *(betyg + i) = 'C';
           } else if (*(poang + i) < 50){
               *(betyg + i) = 'F';
           }
    }
}
void skrivUtBetyg(string *amnen, char *betyg){
    for (int i = 0; i <= 4; i++){
        cout << *(amnen + i) << ": " << *(betyg + i) << endl;
    }
}
void statistik(int *poang, char *betyg){
    //räkna ihop poäng
    int poang_totalt = {0};
    for (int i = 0; i <= 4; i++){
        poang_totalt += *(poang + i);
    }
    cout << "Totalt antal poäng: " << poang_totalt << endl;

    //räkna ihop betyg
    int antal_a = {0};
    int antal_c = {0};
    int antal_f = {0};
    for (int i = 0; i <= 4; i++){
        if (*(betyg + i) == 'A'){
            antal_a += 1;
        }
        if (*(betyg + i) == 'C'){
            antal_c += 1;
        }
        if (*(betyg + i) == 'F'){
            antal_f += 1;
        }
    }
    cout << "Totalt antal A: " << antal_a << endl;
    cout << "Totalt antal C: " << antal_c << endl;
    cout << "Totalt antal F: " << antal_f << endl;
}

int main() {

    string amnen[5] = {"Matematik", "Svenska", "Engelska",
                       "Histora", "Fysik"};
    int poang[5];
    char betyg[6];
    
    //pointers
    string *pAmnen = amnen;
    int *pPoang = poang;
    char *pBetyg = betyg;
    valkomstMeddelande();    
    LäsPoäng(pAmnen, pPoang);
    omvandla(pPoang, pBetyg);
    skrivUtBetyg(pAmnen, pBetyg);
    statistik(pPoang, pBetyg);


}
