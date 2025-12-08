#ifndef jeux
#define jeux

#include <stdio.h>

void remplir_tableau(char tableau_jeux[32][52]);
void afficher_tab(char tableau_jeux[32][52]);
char lireCommandeNonBloquante();
void ajouter_briques(char tableau[32][52]);
void ajouter_balles(char tableau[32][52], int balle[3]);
void modifier_pos_balle(char tableau[32][52], int balle[3]);
#endif