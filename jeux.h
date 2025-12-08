#ifndef jeux
#define jeux

#include <stdio.h>

void remplir_tableau(char tableau_jeux[32][52]);
void afficher_tab(char tableau_jeux[32][52]);
void remplir_mur(char mur[8][45]);
char lireCommandeNonBloquante();
void ajouter_briques(char tableau[32][52], char mur[8][45]);
void ajouter_balles(char tableau[32][52], int balle[3]);
void modifier_pos_balle(char tableau[32][52], int balle[3], char mur[8][45]);
void ajouter_plateforme(char tableau[32][52], int plateforme[3]);
int deplacer_plateforme(char tableau[32][52], int plateforme[3], char commande);
#endif