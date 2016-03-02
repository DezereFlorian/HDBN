# include<stdlib.h>
# include<string.h>
# include<stdio.h>

#include "header.h"

int hdbn = 0;
t_signe last_viol = positif;
t_signe last_un = negatif;
int tab_sequence[N] = { 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0};

int main (void) {

  int sizeTab = 23;


      choix_hdbn();
      // sizeTab = recup_message();
      recherche_zero(sizeTab);
      Tab_2Tab(sizeTab);
      afficher(sizeTab);

      decode(sizeTab);

      int i;
      printf("\n");
      for(i=0;i<sizeTab;i++){
        if (tab_Posi[i] != -2) {
          printf("%2i ", tab_Posi[i]);
        }
      }
      printf( green ": La trame positive \n\n" raz );

  return EXIT_SUCCESS;
}
