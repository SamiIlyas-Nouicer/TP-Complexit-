#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Arbre.h"

int main() {

char *c = "10+4*2";

printf("le resultat est : %d", evaluateInfix(c));


    return 0;}
