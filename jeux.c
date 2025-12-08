#include "jeux.h"

int main(){
    char tableau_jeux[30][50];
    remplir_tableau(tableau_jeux);
    while (1)
    {
        afficher_tab(tableau_jeux);
    }
    
    return 0;
}