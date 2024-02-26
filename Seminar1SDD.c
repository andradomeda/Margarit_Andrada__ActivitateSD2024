#include<stdio.h>
#include<malloc.h>
//std este un namespace ce se gaseste in iostream deci nu poti sa il folosesti la stdio.h biblioteca
// de obicei nu folosim categoria auto animal sau persoana 
//diferent intre struct la c si c++ este ca in C nu avem metode in interiorul structurilor 
//malloc= manual allocation 

struct Masina {
	char* marca;
	float capacitateCilindrica;//capacitate cilindrica 
	int an;
};
void afisareMasina(const struct Masina * m)// de reluat
{
	if (m->marca != NULL)
	{
		printf_s("Marca: %s\n", m->marca);
	}
	printf_s("capacitate Cilindrica: %5.2f\n", m->capacitateCilindrica);
	printf_s("An productie\n\n ", m->an);
}
struct Masina initializare(const char* marca, int an, float capacitateCilindrica)// ca la constrcutorul cu parmetri 
{
	struct Masina m;
	m.an = an;
	m.capacitateCilindrica = capacitateCilindrica;
	if (marca != NULL)
	{
		m.marca = malloc(strlen(marca) + 1);
		strcpy(m.marca, marca);
	}
	else 
	{
		m.marca = malloc(strlen("N/A") + 1);
		strcpy(m.marca, "N/A");
	}
	return m;
}
void dezalocare(struct Masina masina)
{
	free(masina.marca);// daca il aloci cu malloc dezaloci cu free
	masina.marca = NULL;
}
int main()
{
	struct Masina masina1; 
	//Dacia 
	masina1.marca = (char*)malloc(sizeof(char/*=1*/)* strlen ("Dacia")+1);// primeste ca param nr de octeti pe care trb sa i aloce; tipul returnat este un pointer la void adica pointer generic adica poate fi pointer la int la float la orice( sa varieze) si asta da o adresa
	strcpy(masina1.marca, "Dacia");
	masina1.capacitateCilindrica = 1.9;
	masina1.an = 2023;
	afisareMasina(&masina1);
	free(masina1.marca);// daca il loci cu malloc dezaloci cu free
	masina1.marca = NULL;

	struct Masina masina2 = initializare("Ford", 2022, 2.49);
	afisareMasina(&masina2);
	//free(masina2.marca);// daca il loci cu malloc dezaloci cu free
	//masina2.marca = NULL;
	dezalocare(masina2);
	// ca sa nu ne repetam facem o functei pt dezalocare memorie 
	//tipuri de eroare dangling pointer solutie trebuie sa trimitem parametri fix prin pointeri; in c nu avem transmirete prin referinta
	return 0;// nu prea are sens sa pui tot timpul return 0 si de ia ar fi mai bine void main
}