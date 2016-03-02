# include<stdlib.h>
# include<string.h>
# include<stdio.h>

#include "header.h"

int hdbn = 0;
t_signe last_viol = positif;
t_signe last_un = negatif;
int tab_sequence[N] = { 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0};

int main (void) {

  int choix = 0;
  int sizeTab = 23;
  printf("Si vous voulez coder une chaine (celle de l'exemple) tapé 1, sinon si vous voulez décoder une chaine taper 2: \n");
  scanf("%i", &choix);
  switch (choix) {
    case 1:
      choix_hdbn();
      sizeTab = recup_message();
      recherche_zero(sizeTab);
      Tab_2Tab(sizeTab);
      afficher(sizeTab);
      break;
    case 2:
      printf("En train de bosser...");
      break;
    default:
      printf("Mauvaise saisie !");
      break;
  }
  return EXIT_SUCCESS;
}
