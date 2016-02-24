#include "header.h"

void reset (void) {
	int i = 0;
	printf("\n");
	for (i = 0; i < N; i++){
		tab_sequence[i] = -1;
		tab_sortie[i] = -1;
	}
	printf("\n");
}

void recup_message(void){
	int tmp = 0;
	int  i = 0;
	printf("Envoyez la sequence de la trame et -1 pour stopper la saisie : \n");
	/*scanf("%c", tmp);
	int longueur = strlen(&tmp);
	for (i = 0; i != longueur; i++){
		tab_sequence[i] = tmp[i];
		i++;
	}*/
	for (i = 0; tmp != -1; i++){
		scanf("%i", &tmp);
		tab_sequence[i] = tmp;
	}
	//printf("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
}

void choix_hdbn(void){
	printf("Quel est l'ordre de votre HDB? ");
	scanf("%i",&hdbn);
}

void recherche_zero(void) {
	int nb_zero = 0, i = 0;
	for (i = 0; i < N; i++){
		if (nb_zero == hdbn + 1){
			transforme(i);
			nb_zero = 0;
		} else if (tab_sequence[i] == 0){
			nb_zero++;
			tab_sortie[i] = tab_sequence[i];
		}
		else if (tab_sequence[i] == 1){
			nb_zero = 0;
			tab_sortie[i] = tab_sequence[i];
		} //else:
	}
}

void transforme(int place){
	if (last_viol == positif){
		if (last_un == positif){
			//on change de place et on change la chaine avec [-1001]
			tab_sortie[place - hdbn] = -1;
			tab_sortie[place] = -1;
			last_viol = negatif;
			last_un = negatif;
		} else {
			//[000-1]
			tab_sortie[place - hdbn] = 0;
			tab_sortie[place] = -1;
			last_viol = negatif;
			last_un = negatif;
		}
	} else {
		if (last_un == positif){
			//[0001]]
			tab_sortie[place-hdbn] = 0;
			tab_sortie[place] = 1;
			last_viol = positif;
			last_un = positif;
		} else {
			//[1001]
			tab_sortie[place - hdbn] = 1;
			tab_sortie[place] = 1;
			last_viol = positif;
			last_un = positif;
		}
	}
}

void afficher(void){
	int i;
	printf("\nLa trame HDB%i est donc :\n",hdbn);
	for(i=0;i<N;i++){
		printf("%i", tab_sortie[i]);
	}
	printf("\n");
}
