#include "header.h"

int hdbn = 0;
t_signe last_viol = positif;
t_signe last_un = negatif;

int tab_sequence[N] = { 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0};

int main (void) {
  choix_hdbn();
//  recup_message();
  recherche_zero();
	Tab_2Tab();
  afficher();
  return EXIT_SUCCESS;
}
