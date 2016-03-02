#include "header.h"

void reset (void) {
  int i = 0;
  printf("\n");
  for (i = 0; i < N; i++){
    tab_sequence[i] = -2;
    tab_sortie[i] = -2;
    tab_Posi[i] = -2;
    tab_Nega[i] = -2;
  }
  printf("\n");
}

int recup_message(void){
  reset();
  int tmp = 0;
  int  i = 0;
  printf("Envoyez la sequence de la trame et -1 pour stopper la saisie : \n");

  for (i = 0; tmp != -1; i++){
    scanf("%i", &tmp);
    tab_sequence[i] = tmp;
  }
  return i-1;
}

void choix_hdbn(void){
  printf("Quel est l'ordre de votre HDB? ");
  scanf("%i",&hdbn);
}

void recherche_zero(int max) {
  int nb_zero = 0, i = 0;
  for (i = 0; i < max; i++){
    if (nb_zero == hdbn + 1){
      transforme(i-1);
      nb_zero = 0;
      i--;
    } else if (tab_sequence[i] == 0){
      nb_zero++;
      tab_Nega[i] = tab_sequence[i];
      tab_Posi[i] = tab_sequence[i];
    }
    else if (tab_sequence[i] == 1){
      nb_zero = 0;
      if (last_un == positif){
        last_un = negatif;
        tab_Nega[i] = tab_sequence[i];
        tab_Posi[i] = 0;
      }
      else {
        last_un = positif;
        tab_Nega[i] = 0;
        tab_Posi[i] = tab_sequence[i];
      }
    }
  }
}

void transforme(int place){
  if (last_viol == positif){
    if (last_un == positif){
      //on change de place et on change la chaine avec [-1....1]

      tab_Nega[place - hdbn] = 1;
      tab_Posi[place - hdbn] = 0;
      tab_Nega[place] = 1;
      tab_Posi[place] = 0;

      last_viol = negatif;
      last_un = negatif;
    } else {
      //[0......-1]

      tab_Nega[place - hdbn] = 0;
      tab_Posi[place - hdbn] = 0;
      tab_Nega[place] = 1;
      tab_Posi[place] = 0;

      last_viol = negatif;
      last_un = negatif;
    }
  } else {
    if (last_un == positif){
      //[0....1]

      tab_Nega[place - hdbn] = 0;
      tab_Posi[place - hdbn] = 0;
      tab_Nega[place] = 0;
      tab_Posi[place] = 1;

      last_viol = positif;
      last_un = positif;
    } else {
      //[1.....1]

      tab_Nega[place - hdbn] = 0;
      tab_Posi[place - hdbn] = 1;
      tab_Nega[place] = 0;
      tab_Posi[place] = 1;

      last_viol = positif;
      last_un = positif;
    }
  }
}

void afficher(int max){
  int i;
  for(i=0;i<max;i++){
    if (tab_sortie[i] != -2) {
      printf("%2i ", tab_sequence[i]);
    }
  }
  printf(": La trame D'entée\n\n" );
  for(i=0;i<max;i++){
    if (tab_Nega[i] != -2) {
      printf("%2i ", tab_Nega[i]);
    }
  }
  printf(red ": La trame negative \n" raz);
  for(i=0;i<max;i++){
    if (tab_Posi[i] != -2) {
      printf("%2i ", tab_Posi[i]);
    }
  }
  printf( green ": La trame positive \n\n" raz );
  for(i=0;i<max;i++){
    if (tab_sortie[i] != -2) {
      if (tab_sortie[i] == -1) {
        printf(red "%2i "raz , tab_sortie[i]);
      }else if (tab_sortie[i] == 1) {
        printf(green "%2i " raz , tab_sortie[i]);
      }else {
        printf("%2i " raz , tab_sortie[i]);
      }
    }
  }
  printf(": La trame HDB%i\n",hdbn);
}

void Tab_2Tab(int max){
  int i = 0;
  for (i = 0; i < max; i++){
    tab_sortie[i]=tab_Posi[i] -1*(tab_Nega[i]);
  }
}
void decode(int max){
  int i,j;
  for (i = 0; i < max; i++) {
    tab_sequence[i] = 0;

    if (tab_Posi[i] == 1 && last_viol == negatif) {
      last_viol = positif;
      tab_sequence[i] = 1;

    }else if ( tab_Nega[i] == 1 && last_viol == positif ){
      last_viol = negatif;
      tab_sequence[i] = 1;
    }

    if (tab_Posi[i] == 1 && last_viol == positif ) {
      for (j = i ; j >  i-hdbn ; j--) {
        tab_sequence[i] = 0;
      }
    }
    if (tab_Nega[i] == 1 && last_viol == negatif) {
      for (j = i ; j >  i-hdbn ; j--) {
        tab_sequence[i] = 0;
      }
    }

  }
}
