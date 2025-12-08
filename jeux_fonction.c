#include "jeux.h"

void remplir_tableau(char tableau_jeux[30][50]){
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            tableau_jeux[i][j] = ' ';
        }
    }
}

void afficher_tab(char tableau_jeux[30][50]){
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            printf("%c", tableau_jeux[i][j]);
        }
        printf("\n");
    }
}