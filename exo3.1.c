#include <stdio.h>
#include <stdlib.h>
#include "Arbre.h"

int main() {

Noeud* arbre = NULL;
    arbre = ajouterElement(arbre, 28);
    arbre = ajouterElement(arbre, 19);
    arbre = ajouterElement(arbre, 33);
    arbre = ajouterElement(arbre, 10);
    arbre = ajouterElement(arbre, 21);
    arbre = ajouterElement(arbre, 31);
    arbre = ajouterElement(arbre, 48);
    arbre = ajouterElement(arbre, 2);
    arbre = ajouterElement(arbre, 17);
    arbre = ajouterElement(arbre, 20);
    arbre = ajouterElement(arbre, 25);

    prefixedisplay(arbre);

    printf("la profondeur de l'arbre est %d\n", profondeurArbre(arbre));
    printf("le nombre de feuilles de l'arbre est %d\n", nbrFeuille(arbre));

    libererArbre(arbre);
    return 0;}