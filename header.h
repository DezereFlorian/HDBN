#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define N 50

typedef enum {positif, negatif} t_signe;
int tab_sequence[N];
int tab_sortie[N];
int tab_Posi[N];
int tab_Nega[N]

extern t_signe last_viol;
extern t_signe last_un;
extern int hdbn;

void reset (void);
void recup_message(void);
void choix_hdbn(void);
void recherche_zero(void);
void transforme(int i);
void afficher(void);