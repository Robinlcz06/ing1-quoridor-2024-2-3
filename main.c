#include <stdio.h>
#include "sauvegarde.h"


int main(void) {
    Partie partie = {0};
    snprintf(partie.joueur1_name, sizeof(partie.joueur1_name), "pierre");
    snprintf(partie.joueur2_name, sizeof(partie.joueur2_name), "antoine");
    snprintf(partie.joueur3_name, sizeof(partie.joueur3_name), "Talmo");
    snprintf(partie.joueur4_name, sizeof(partie.joueur4_name), "JeanFils");

    //Initialiser position et score
    partie.joueur1_x = 1;
    partie.joueur1_y = 1;
    partie.joueur2_x = 2;
    partie.joueur2_y = 2;
    partie.joueur3_x = 3;
    partie.joueur3_y = 3;
    partie.joueur4_x = 4;
    partie.joueur4_y = 4;

    //Initialiser les murs à zéro
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            partie.murs[i][j] = 0;
        }
    }
    sauvegarde(&partie, "sauvegarde_partie.txt");

    // Charger la partie
    Partie charger_partie;
    charger(&charger_partie, "sauvegarde_partie.txt");

    // Enregistrer le score final
    int final_score = partie.current_score; // Exemple : utiliser le score courant comme score final
    score(final_score, partie.joueur1_name, partie.joueur2_name, partie.joueur3_name, partie.joueur4_name, "score_final.txt");

    return 0;
}


