#include "jeux.h"
#include <Windows.h>

int main()
{
    // cacher curseur
    CONSOLE_CURSOR_INFO cci;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hConsole, &cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cci);
    //
    char tableau[32][52]; // 31 en hauteur et 52 en largeur, 2 pour les bords (gauche + droite) et un bord en haut
    char touche = 'N';
    int balle[3] = {26, 25, 0}; // x, y, numro de diagonale (0 -> haut gauche, 1 -> haut droite, ect)
    while (1)
    {
        system("cls"); // clear le cmd
        remplir_tableau(tableau);
        ajouter_briques(tableau);
        ajouter_balles(tableau, balle);
        afficher_tab(tableau);

        // la balle
        modifier_pos_balle(tableau, balle);
        //get la touche
        touche = lireCommandeNonBloquante();

        Sleep(30); // attendre
    }

    return 0;
}