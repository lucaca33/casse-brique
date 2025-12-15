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
void remplir_mur(char mur[8][45])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 45; j++)
        {
            mur[i][j] = '#';
        }
    }
}
void ajouter_briques(char tableau[32][52], char mur[8][45])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 45; j++)
        {
            tableau[2+i][3+j] = mur[i][j];
        }
    }
}
void ajouter_balles(char tableau[32][52], int balle[3])
{
    tableau[balle[1]][balle[0]] = 'O';
}

// beaucoup de conditions identiques ou quasi qui se répètent => il faudrait extraire le code en commun et en faire une fonction
void modifier_pos_balle(char tableau[32][52], int balle[3], char mur[8][45])
{
    int temp_balle = balle[2];
    switch (balle[2])
    {
    case 0:
        balle[1] -= 1;
        if (tableau[balle[1]][balle[0]] != ' ')
        {
            if (mur[balle[1]-3][balle[0]-2] == '#') // /!\ avec ce genre de choses, il faut vérifier que l'on est bien dans le tableau
            {
                mur[balle[1]-3][balle[0]-2] = ' ';
            }
            balle[1] += 2;
            temp_balle = 3;
        }
        balle[0] -= 1;
        if (tableau[balle[1]][balle[0]] != ' ')
        {
            if (mur[balle[1]-3][balle[0]-2] == '#')
            {
                mur[balle[1]-3][balle[0]-2] = ' ';
            }
            balle[0] += 2;
            temp_balle = 1;
            if (temp_balle == 3)
            {
                temp_balle = 2;
            }
        }
        break;
    case 1:
        balle[1] -= 1;
        if (tableau[balle[1]][balle[0]] != ' ')
        {
            if (mur[balle[1]-3][balle[0]-2] == '#')
            {
                mur[balle[1]-3][balle[0]-2] = ' ';
            }
            balle[1] += 2;
            temp_balle = 2;
        }
        balle[0] += 1;
        if (tableau[balle[1]][balle[0]] != ' ')
        {
            if (mur[balle[1]-3][balle[0]-2] == '#')
            {
                mur[balle[1]-3][balle[0]-2] = ' ';
            }
            balle[0] -= 2;
            temp_balle = 0;
            if (temp_balle == 2)
            {
                temp_balle = 3;
            }
        }
        break;
    case 2:
        balle[1] += 1;
        if (tableau[balle[1]][balle[0]] != ' ')
        {
            if (mur[balle[1]-3][balle[0]-2] == '#')
            {
                mur[balle[1]-3][balle[0]-2] = ' ';
            }
            balle[1] -= 2;
            temp_balle = 1;
        }
        balle[0] += 1;
        if (tableau[balle[1]][balle[0]] != ' ')
        {
            if (mur[balle[1]-3][balle[0]-2] == '#')
            {
                mur[balle[1]-3][balle[0]-2] = ' ';
            }
            balle[0] -= 2;
            temp_balle = 3;
            if (temp_balle == 1)
            {
                temp_balle = 0;
            }
        }
        break;
    case 3:
        balle[1] += 1;
        if (tableau[balle[1]][balle[0]] != ' ')
        {
            if (mur[balle[1]-3][balle[0]-2] == '#')
            {
                mur[balle[1]-3][balle[0]-2] = ' ';
            }
            balle[1] -= 2;
            temp_balle = 0;
        }
        balle[0] -= 1;
        if (tableau[balle[1]][balle[0]] != ' ')
        {
            if (mur[balle[1]-3][balle[0]-2] == '#')
            {
                mur[balle[1]-3][balle[0]-2] = ' ';
            }
            balle[0] += 2;
            temp_balle = 2;
            if (temp_balle == 0)
            {
                temp_balle = 1;
            }
        }
        break;
    }
    balle[2] = temp_balle;
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

void ajouter_plateforme(char tableau[32][52], int plateforme[3])
{
    int x = plateforme[0];
    int y = plateforme[1];
    int taille = plateforme[2];

    for (int i = 0; i < taille; i++)
    {
        tableau[y][x + i] = '=';
    }
}

int deplacer_plateforme(char tableau[32][52], int plateforme[3], char commande)
{
    int x = plateforme[0];
    int y = plateforme[1];
    int taille = plateforme[2];

    for (int i = 0; i < taille; i++)
        tableau[y][x + i] = ' ';

    if (commande == 'q' && x - taille> 1)
        plateforme[0]--;

    if (commande == 'd' && x + taille < 50)
        plateforme[0]++;

    if (commande == 's')
        return 1;

    for (int i = 0; i < taille; i++)
        tableau[y][plateforme[0] + i] = '=';
    return 0;
}