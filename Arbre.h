#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


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



void prefixedisplay(Noeud* racine){
    if(racine != NULL){
        printf("%d  ", racine->valeur);
        prefixedisplay(racine->gauche);
        prefixedisplay(racine->droite);
    
    }

}

void infixdisplay(Noeud* racine){
    if(racine != NULL){
        
    
        infixdisplay(racine->gauche);
        printf("%d  ", racine->valeur);
        infixdisplay(racine->droite);
    }

}

void postfixedisplay(Noeud* racine){
    if(racine != NULL){ 
            postfixedisplay(racine->gauche);
            postfixedisplay(racine->droite);
            printf("%d  ", racine->valeur);   
    }
}

int profondeurArbre (Noeud * racine){
    if (racine == NULL){
        return 0;
    }

    int profondeurGauche = profondeurArbre(racine->gauche);
    int profondeurDroite = profondeurArbre(racine->droite);

    return (profondeurGauche > profondeurDroite ? profondeurGauche : profondeurDroite) + 1;
}


int nbrFeuille (Noeud * racine){
    if (racine == NULL){
        return 0;
    }
    int feuilleGauche = nbrFeuille(racine->gauche);
    int feuilleDroite = nbrFeuille(racine->droite);

    return (feuilleDroite + feuilleGauche) + 1 ;
}






//******************************************************************************


// Structure de la pile
struct Stack {
    int top;
    int capacity;
    int* array;
};

// Fonction pour créer une pile
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Fonction pour vérifier si la pile est vide
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Fonction pour empiler un élément sur la pile
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Fonction pour dépiler un élément de la pile
int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// Fonction pour évaluer une expression postfixée
int evaluatePostfix(char* expression) {
    struct Stack* stack = createStack(strlen(expression));
    int i, operand1, operand2;

    for (i = 0; expression[i] != '\0'; ++i) {
        if (isdigit(expression[i])) {
            // Si le caractère est un chiffre, le convertir en entier et empiler
            push(stack, expression[i] - '0');
        } else {
            // Sinon, le caractère est un opérateur
            operand2 = pop(stack);
            operand1 = pop(stack);

            // Effectuer l'opération correspondante
            switch (expression[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }
    // Le résultat final est au sommet de la pile
    return pop(stack);
}

int evaluatePrefix(char* expression) {
    struct Stack* stack = createStack(strlen(expression));
    int i, operand1, operand2;

    // Parcourir l'expression en sens inverse
    for (i = strlen(expression) - 1; i >= 0; --i) {
        if (isdigit(expression[i])) {
            // Si le caractère est un chiffre, le convertir en entier et empiler
            push(stack, expression[i] - '0');
        } else {
            // Sinon, le caractère est un opérateur
            operand1 = pop(stack);
            operand2 = pop(stack);

            // Effectuer l'opération correspondante
            switch (expression[i]) {
                case '+':
                    push(stack, operand1 + operand2);
                    break;
                case '-':
                    push(stack, operand1 - operand2);
                    break;
                case '*':
                    push(stack, operand1 * operand2);
                    break;
                case '/':
                    push(stack, operand1 / operand2);
                    break;
            }
        }
    }
    // Le résultat final est au sommet de la pile
    return pop(stack);
}


int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;  // Opérateur non pris en charge
}

// Fonction pour effectuer une opération
int applyOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            return 0;  // Opérateur non pris en charge
    }
}


char peek(struct Stack* stack) {
    return stack->array[stack->top];
}
int evaluateInfix(char* expression) {
    struct Stack* operandStack = createStack(strlen(expression));
    struct Stack* operatorStack = createStack(strlen(expression));
    int i, operand;

    for (i = 0; expression[i] != '\0'; ++i) {
        if (isdigit(expression[i])) {
            // Si le caractère est un chiffre, le convertir en entier et empiler sur la pile d'opérandes
            operand = expression[i] - '0';
            push(operandStack, operand);
        } else if (expression[i] == '(') {
            // Si le caractère est une parenthèse ouvrante, empiler sur la pile d'opérateurs
            push(operatorStack, expression[i]);
        } else if (expression[i] == ')') {
            // Si le caractère est une parenthèse fermante, effectuer les opérations jusqu'à la parenthèse ouvrante
            while (!isEmpty(operatorStack) && peek(operatorStack) != '(') {
                operand = pop(operandStack);
                operand = applyOperation(pop(operandStack), operand, pop(operatorStack));
                push(operandStack, operand);
            }
            // Dépiler la parenthèse ouvrante
            pop(operatorStack);
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            // Si le caractère est un opérateur, effectuer des opérations jusqu'à ce que la pile d'opérateurs soit vide ou que l'opérateur en cours ait une priorité inférieure
            while (!isEmpty(operatorStack) && precedence(peek(operatorStack)) >= precedence(expression[i])) {
                operand = pop(operandStack);
                operand = applyOperation(pop(operandStack), operand, pop(operatorStack));
                push(operandStack, operand);
            }
            // Empiler l'opérateur en cours
            push(operatorStack, expression[i]);
        }
    }

    // Effectuer les opérations restantes
    while (!isEmpty(operatorStack)) {
        operand = pop(operandStack);
        operand = applyOperation(pop(operandStack), operand, pop(operatorStack));
        push(operandStack, operand);
    }

    // Le résultat final est au sommet de la pile d'opérandes
    return pop(operandStack);
}

struct noeud* deletenoeud(struct noeud* root, int valeur) {
    if (root == NULL) return root;

    if (valeur < root->valeur)
        root->gauche = deletenoeud(root->gauche, valeur);

    else if (valeur > root->valeur)
        root->droite = deletenoeud(root->droite, valeur);

    else {
    
            if (root->gauche == NULL) {
                struct noeud* temp = root->droite;
                free(root);
                return temp;
            } else if (root->droite == NULL) {
                struct noeud* temp = root->gauche;
                free(root);
                return temp;
            }

        struct noeud* temp = root->droite;
        while (temp->gauche != NULL)
            temp = temp->gauche;

        root->valeur = temp->valeur;

        root->droite = deletenoeud(root->droite, temp->valeur);
    }

    return root;
}


#endif