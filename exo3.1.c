#include <stdio.h>
#include <stdlib.h>
#include "Arbre.h"

int main() {

  Noeud *a = creerNoeud(1);
    ajouterElement(a, 2);
    ajouterElement(a, 3);
    ajouterElement(a, 4);
    ajouterElement(a, 5);
    ajouterElement(a, 6);
    ajouterElement(a, 7);
    ajouterElement(a, 8);
    ajouterElement(a, 9);
    ajouterElement(a, 10);

    prefixedisplay(a);
    printf("\n");
    int n = goodNodes(a);
    printf("Nombre de noeuds bon : %d\n", n);

    return 0;}