#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>

typedef struct noeud
{
    int valeur;
    struct noeud *gauche;
    struct noeud *droite;
} Noeud;

Noeud* creerNoeud(int valeur) {
    Noeud* nouveauNoeud = (Noeud*)malloc(sizeof(Noeud));
    if (nouveauNoeud == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }
    nouveauNoeud->valeur = valeur;
    nouveauNoeud->gauche = NULL;
    nouveauNoeud->droite = NULL;
    return nouveauNoeud;
}

Noeud* ajouterElement(Noeud* racine, int valeur) {
    if (racine == NULL) {
        return creerNoeud(valeur);
    }

    // Si la valeur est inférieure, elle va à gauche
    if (valeur < racine->valeur) {
        racine->gauche = ajouterElement(racine->gauche, valeur);
    }
    // Sinon, elle va à droite
    else if (valeur > racine->valeur) {
        racine->droite = ajouterElement(racine->droite, valeur);
    }
    return racine;
}


void libererArbre(Noeud* racine) {
    if (racine != NULL) {
        libererArbre(racine->gauche);
        libererArbre(racine->droite);
        free(racine);
    }
}
#endif