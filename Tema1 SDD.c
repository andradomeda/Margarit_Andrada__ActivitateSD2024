//Margarit Andrada grupa 1058 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Masina
{
	int kilometraj;
	char* denumire;
	int pret;

};
//Realizati o functie cu ajutorul careia sa cititi de la tastatura un articol de tipul construit de voi. Funcția returnează obiectul citit.
struct Masina citire()
{
	struct Masina masina1;
    printf_s("kilometraj masina: ");
    scanf_s("%d", &masina1.kilometraj);

    masina1.denumire = (char*)malloc(100 * sizeof(char));
    if (masina1.denumire == NULL) {
        printf_s("Eroare");
        exit(1);
    }
    printf_s("denumire masina: ");
    scanf_s("%s", masina1.denumire);

    printf_s("Introduceți prețul mașinii: ");
    scanf_s("%d", &masina1.pret);

    return masina1;
}
//Realizati o functie care calculeaza ceva pentru un obiect de tipul implementat de voi. (o medie sau o suma, un maxim, un minim...sau orice altceva)
void tipmasina(struct Masina masina)
{
        if (masina.kilometraj <= 1000) {
            printf_s("masina este noua \n");
        }
        else {
            printf_s("masina nu este noua \n");
        }
}
//Realizati o functie care modifica pentru un obiect primit ca parametru, un anumit camp. noua valoare este primita ca parametru
void modificare( struct Masina *masina, int pretnou)
{
    masina->pret = pretnou;
}
//Realizați o funcție care afișează un obiect de tipul creat. Afișarea se face la console, și sunt afișate toate informațiile.
void afisare(struct Masina masina) {
    printf_s("Kilometraj: %d\n", masina.kilometraj);
    printf_s("Denumire: %s\n", masina.denumire);
    printf_s("Pret: %d\n", masina.pret);
}
int main()
{
	//struct Masina masina= citire();
    struct Masina masina1 = { 10000, "Dacia", 15000 };
    tipmasina(masina1);
    modificare(&masina1, 1000);
    afisare(masina1);
}