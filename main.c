#include "header.h"

int hdbn = 0;
t_signe last_viol = positif;
t_signe last_un = negatif;

int main (void) {
	reset();
	choix_hdbn();
	recup_message();
	recherche_zero();
	afficher();

	return EXIT_SUCCESS;
}
