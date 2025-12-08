#include "jeux.h"

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
            if (i < 10 && i > 2 && j < 48 && j > 3)
            {
                tableau_jeux[i][j] = 'x';
            }
            
        }
    }
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

int get_touche()
{
    char temp;
    scanf("%c", &temp);
    return temp;
}