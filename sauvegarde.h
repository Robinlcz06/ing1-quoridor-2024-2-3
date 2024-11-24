//
// Created by Robin Lecluze on 03/11/2024.
//

#ifndef QUORIDOR3_H
#define QUORIDOR3_H
typedef struct {
    int joueur1_x, joueur1_y;       // Position du joueur 1
    int joueur2_x, joueur2_y;       // Position du joueur 2
    int joueur3_x, joueur3_y;
    int joueur4_x, joueur4_y;
    int murs[10][10];              // Grille des murs (10x10 par exemple)
    int current_score;              // Score actuel
    char joueur1_name[50];
    char joueur2_name[50];
    char joueur3_name[50];
    char joueur4_name[50];
} Partie;


void sauvegarde(Partie *partie, const char *filename);
void charger(Partie *partie, const char *filename);
void score(int final_score, const char *joueur1_name,const char *joueur2_name,const char *joueur3_name,const char *joueur4_name,const char *filename);
#endif //QUORIDOR3_H
