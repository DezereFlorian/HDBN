#include "header.h"

int hdbn = 0;
t_signe last_viol = negatif; 
t_signe last_un = negatif;

int main (void) {
	
	printf("Coucou je marche !");
	reset();
	choix_hdbn();
	recup_message();
	recherche_zero();
	afficher();
	
	return EXIT_SUCCESS;
}
