# include<stdlib.h>
# include<string.h>
# include<stdio.h>
# define N 23

#define raz     "\x1B[0m"
#define red     "\x1B[31m"
#define green   "\x1B[32m"
#define yellow  "\x1B[33m"
#define blue    "\x1B[34m"
#define magenta "\x1B[35m"
#define cyan    "\x1B[36m"
#define white   "\x1B[37m"


typedef enum {positif, negatif} t_signe;
int tab_sortie[N];
int tab_Posi[N];
int tab_Nega[N];

extern int tab_sequence[N];
extern t_signe last_viol;
extern t_signe last_un;
extern int hdbn;

void reset (void);
void recup_message(void);
void choix_hdbn(void);
void recherche_zero(void);
void transforme(int i);
void afficher(void);
void Tab_2Tab(void);
