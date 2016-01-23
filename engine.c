#include "header.h"

void reset (void) {
	int i = 0;
	printf("\n");
	for (i = 0; i < 50; i++){
		tab_sequence[i] = -2;
		printf("%i", tab_sequence[i]);
	}
	printf("\n");
	for (i = 0; i < 50; i++){
		tab_nega[i] = 100;
		printf("%i", tab_nega[i]);
	}
	printf("\n");
	for (i = 0; i < 50; i++){
		tab_posi[i] = -5;
		printf("%i", tab_posi[i]);
	}
	printf("\n");	
}

void recup_message(void){
	int tmp = 0;
	int  i = 0;
	printf("Envoyez la sequence de la trame et -2 pour stopper la saisie : \n");
	/*scanf("%s", tmp);
	int longueur = strlen(tmp);
	while(i < longueur){
		tab_sequence[i] = tmp[i];
		i++;
	}*/
	while (tmp != -2){
		scanf("%i", &tmp);
		tab_sequence[i] = tmp;
		i++;
	}
}

void choix_hdbn(void){
	printf("Quel est votre HDBn ? ");
	scanf("%i",&hdbn);
}

void recherche_zero(void){
	int nb_zero = 0, i = 0, tmp = 0;
	for (i = 0; i < 50; i++){
		if (tab_sequence[i] == 1){
<<<<<<< HEAD
			tab_posi[i] = 1;
			tab_nega[i] = 0;
		} else {
			if (tab_sequence[i] == 0) nb_zero++;
			if (nb_zero == hdbn+1){


				transforme(i); 
				nb_zero = 0;



			}
		nb_zero = 0;
		}
	}
}

void transforme(int i){
	int place=i;
	int longueur = place+hdbn-1;
	if(last_viol == negatif){
		if(last_un == negatif){
			place = i;
			tab_posi[place] = 1;
			tab_nega[place] = 0;
			for(place=place+1;place<=longueur;place++){
				tab_posi[place] = 0;
				tab_nega[place] = 0;
			}
			tab_posi[place+1] = 1;
			tab_nega[place+1] = 0;
			last_un = positif;
		}
		else{
			tab_posi[place] = 0;
			tab_nega[place] = 0;
			for(place=place+1;place<=longueur;place++){
				tab_posi[place] = 0;
				tab_nega[place] = 0;
			}
			tab_posi[place+1] = 1;
			tab_nega[place+1] = 0;
		}
		last_viol = positif;
	}
	else{
		if(last_un == negatif){
			tab_posi[place] = 0;
			tab_nega[place] = 0;
			for(place=place+1;place<=longueur;place++){
				tab_posi[place] = 0;
				tab_nega[place] = 0;
			}
			tab_posi[place] = 0;
			tab_nega[place] = 1;
		}
		else{
			tab_posi[place] = 0;
			tab_nega[place] = 1;
			for(place=place+1;place<=longueur;place++){
				tab_posi[place] = 0;
				tab_nega[place] = 0;
			}
			tab_posi[place] = 0;
			tab_nega[place] = 1;
			last_un = negatif;
		}
		last_viol = negatif;
	}
}

void afficher(void){
	int tab_s[50];
	int i;
	printf("La trame HDB%i est donc :\n",hdbn);
	for(i=0;i<50;i++){
		tab_s[i] = tab_posi[i] + tab_nega[i] * (-1);
		if ((tab_s[i] == 1) || (tab_s[i] == 0) || (tab_s[i] == -1)) printf("%i", tab_s[i]);
	}
	printf("\n");
}
