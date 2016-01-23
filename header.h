#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef enum {positif, negatif} t_signe; 
int tab_sequence[50];
int tab_posi[50];
int tab_nega[50];
extern t_signe last_viol; 
extern t_signe last_un;
extern int hdbn;

void reset (void);
void recup_message(void);
void choix_hdbn(void);
void recherche_zero(void);
void transforme(int i);
void afficher(void);
