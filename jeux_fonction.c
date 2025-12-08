#include "jeux.h"
#include <conio.h> /* _kbhit, _getch */

void remplir_tableau(char tableau_jeux[32][52])
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            tableau_jeux[i][j] = ' ';
            if (j == 0 || j == 51)
            {
                tableau_jeux[i][j] = '|';
            }
            if (i == 0 || i == 31)
            {
                tableau_jeux[i][j] = '-';
            }
        }
    }
}
void ajouter_briques(char tableau[32][52])
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            if (i < 10 && i > 2 && j < 48 && j > 3)
            {
                tableau[i][j] = '#';
            }
        }
    }
}
void ajouter_balles(char tableau[32][52], int balle[3])
{
    tableau[balle[1]][balle[0]] = 'O';
}

void afficher_tab(char tableau_jeux[32][52])
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            printf("%c", tableau_jeux[i][j]);
        }
        printf("\n");
    }
}

/* Lit une touche si disponible et la renvoie, sinon renvoie 0 */
char lireCommandeNonBloquante()
{
    if (_kbhit())
    {
        return (char)_getch();
    }
    return 0;
}