/* ### 02.02.2019 ### */

/* Kaffeemaschine mit Button
 * 1 - americano 70/30/0
 * 2 - cappuccino 30/20/50
 * 3 - latte 20/20/60
 * 4 - espresso 50/50/0

inhalt: wasser, kaffee, milch in ml
ausgabe inhalt nach der wahl
*/

#include<stdio.h>
#include<stdbool.h>
void kaffeemashine(char button, double geld);
void make(char name[], int water, int caffe, int milk);
void ausgabe(double zahl, double preis);

int main() {
    char nummer = '0';
    double betrag = 0;
    double summe = 0;
    bool getraenk = false;
    const double americano = 1;
    const double cappuccino = 1.5;
    const double latte = 2;
    const double espresso = 0.6;

    while(!getraenk){
    printf("#### Bitte zahlen Sie das Geld ein ####\nIhr Zahlbetrag: ");
    scanf("%lf", &betrag);
    summe = summe + betrag;

        if(summe > 0) {
            while(nummer > '4' || nummer <= '0') {
                printf("#### Bitte wählen Sie die Nummer ####\n1: Americano für 1.00€\n2: Cappucino für 1.50€\n3: Latte für 2.00€\n4: Espresso für 0.60€\nIhre Wahl: ");
                nummer = getchar();
            }
    
            switch (nummer)
            {
                case '1':
                    if(summe < americano) {
                        ausgabe(summe, americano);
                    }
                    else {
                        getraenk = true;
                    }
                    break;
                case '2':
                    if(summe < 1.50) {
                        ausgabe(summe, cappuccino);
                    }
                    else {
                        getraenk = true;
                    }
                    break;   
                case '3':
                    if(summe < 2) {
                        ausgabe(summe, latte);
                    }
                    else {
                        getraenk = true;
                    }
                    break; 
                case '4':
                    if(summe < 0.6) {
                        ausgabe(summe, espresso);
                    }
                    else {
                        getraenk = true;
                    }
                    break;
                default:
                    break;
            }
        }       
    }
    printf("#### Danke. Sie haben gewählt: %c und gezahlter Betrag: %.2f ####\n", nummer, summe);
    kaffeemashine(nummer, summe);   
    return 0;
}

void kaffeemashine(char button, double geld) {
    printf("#### Kaffemaschine startet ####\n");
    switch (button)
    {
        case '1':
            make("Americano",70, 30, 0);
            printf("Rückgabe: %.2f€\n", (geld - 1) );
            break;
        case '2':
            make("Cappucino", 30,20,50);
            printf("Rückgabe: %.2f€\n", (geld - 1.5) );
            break;
        case '3':
            make("Latte", 20,20,60);
            printf("Rückgabe: %.2f€\n", (geld - 2) );
            break;
        case '4':
            make("Espresso", 50,50, 0);
            printf("Rückgabe: %.2f€\n", (geld - 0.6) );
            break;
    
        default:
            break;
    }
}

void make(char name[], int water, int caffe, int milk) {
    printf("Sie bekommen:\nGetränk:\t%s\nWasser\t%d ml\nKaffee\t%d ml\nMilch\t%d ml\n", name, water, caffe, milk);

}

void ausgabe(double zahl, double preis) {
    printf("Aktueller Betrag %.2f€. Es reicht nicht. Bitte mind. %.2f€ geben.\n", zahl, preis);
}