#ifndef HEADER_H_G9K5UTVS
#define HEADER_H_G9K5UTVS

# include<stdlib.h>
# include<string.h>
# include<stdio.h>

#define raz     "\x1B[0m"
#define red     "\x1B[31m"
#define green   "\x1B[32m"
#define yellow  "\x1B[33m"
#define blue    "\x1B[34m"
#define magenta "\x1B[35m"
#define cyan    "\x1B[36m"
#define white   "\x1B[37m"


#define N 100 /*taille max de la trame*/

typedef enum {positif, negatif} t_signe;
int tab_sortie[N];
int tab_Posi[N];
int tab_Nega[N];

extern int tab_sequence[N];
extern t_signe last_viol;
extern t_signe last_un;
extern int hdbn;

void reset (void);
int recup_message(void);
void choix_hdbn(void);
void recherche_zero(int max);
void transforme(int i);
void afficher(int max);
void Tab_2Tab(int max);
void decode(int max);
#endif /* end of include guard: HEADER_H_G9K5UTVS */
