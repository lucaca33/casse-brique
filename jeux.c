#include "jeux.h"
#include <Windows.h>

int main()
{
    char tableau_jeux[32][52]; // 31 en hauteur et 52 en largeur, 2 pour les bords (gauche + droite) et un bord en haut
    remplir_tableau(tableau_jeux);
    char touche = 'N';
    int balle[3] = {26, 25, 0}; // x, y, numro de diagonale (0 -> haut gauche, 1 -> haut droite, ect)
    while (1)
    {
        system("cls"); // clear le cmd
        afficher_tab(tableau_jeux);
        touche = get_touche();
    }

    return 0;
}