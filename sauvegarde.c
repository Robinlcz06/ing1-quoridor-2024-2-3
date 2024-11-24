
#include "sauvegarde.h"
#include <stdio.h>

void sauvegarde(Partie *partie, const char *filename) {
    FILE *file = fopen(filename, "w"); // Ouvrir en mode texte pour écriture
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde\n");
        return;
    }

    // Sauvegarder les pseudos
    fprintf(file, "%s\n", partie->joueur1_name);
    fprintf(file, "%s\n", partie->joueur2_name);
    fprintf(file, "%s\n", partie->joueur3_name);
    fprintf(file, "%s\n", partie->joueur4_name);
    // Enregistrer les positions des joueurs et le score
    fprintf(file, "%d %d\n", partie->joueur1_x, partie->joueur1_y);
    fprintf(file, "%d %d\n", partie->joueur2_x, partie->joueur2_y);
    fprintf(file, "%d %d\n", partie->joueur3_x, partie->joueur3_y);
    fprintf(file, "%d %d\n", partie->joueur4_x, partie->joueur4_y);
    fprintf(file, "%d\n", partie->current_score);

    // Enregistrer la grille des murs
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fprintf(file, "%d ", partie->murs[i][j]);
        }
        fprintf(file, "\n"); // Nouvelle ligne après chaque rangée
    }

    fclose(file); // Fermer le fichier
    printf("La partie a été sauvegardée dans le fichier %s.\n", filename);
}


void charger(Partie *partie, const char *filename) {
    FILE *file = fopen(filename, "r"); // Ouvrir en mode texte pour lecture
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier de chargement\n");
        return;
    }
    fscanf(file, "%s", partie->joueur1_name);
    fscanf(file, "%s", partie->joueur2_name);
    fscanf(file, "%s", partie->joueur3_name);
    fscanf(file, "%s", partie->joueur4_name);
    // Lire les positions des joueurs et le score
    fscanf(file, "%d %d", &partie->joueur1_x, &partie->joueur1_y);
    fscanf(file, "%d %d", &partie->joueur2_x, &partie->joueur2_y);
    fscanf(file, "%d %d", &partie->joueur3_x, &partie->joueur3_y);
    fscanf(file, "%d %d", &partie->joueur4_x, &partie->joueur4_y);
    fscanf(file, "%d", &partie->current_score);

    // Lire la grille des murs
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fscanf(file, "%d", &partie->murs[i][j]);
        }
    }

    fclose(file); // Fermer le fichier
    printf("La partie a été chargée depuis le fichier %s.\n", filename);
}
