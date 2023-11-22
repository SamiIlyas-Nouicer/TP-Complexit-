#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };
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
int applyOperation(int operand1, int operand2, char operat) {
    switch (operat) {
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

void entasser(int T[], int n, int i) {
    int imax = i;
    int gauche = 2 * i + 1;
    int droite = 2 * i + 2;
    int temp;

    if (gauche < n && T[gauche] > T[imax]) {
        imax = gauche;
    }

    if (droite < n && T[droite] > T[imax]) {
        imax = droite;
    }

    if (imax != i) {
        // Échanger T[i] et T[imax]
        temp = T[i];
        T[i] = T[imax];
        T[imax] = temp;

        // Rappel récursif pour l'entassement sur le sous-arbre modifié
        entasser(T, n, imax);
    }
}

void constructionTas(int T[], int n) {
    // Dernier noeud interne
    int dernierNoeudInterne = (n / 2) - 1;

    // Effectuer l'entassement sur tous les noeuds internes
    for (int i = dernierNoeudInterne; i >= 0; i--) {
        entasser(T, n, i);
    }
}

void ajouterElementTas(int T[], int *n, int element) {
    // Augmenter la taille du tableau
    (*n)++;

    // Ajouter l'élément à la fin du tableau
    T[(*n) - 1] = element;
    entasser(T, *n, 0);

  
}


int goodNodes(struct noeud* root){

    if(root ==NULL) {return 0;}
    if (root->gauche == NULL && root->droite == NULL){
        return 1;
    }
    int droite = goodNodes(root->droite);
    int gauche = goodNodes(root->gauche);

    
    if (fmax(root->valeur,root->gauche->valeur) == root->gauche->valeur ){ return gauche + 1;}
    if  (fmax(root->valeur,root->droite->valeur) == root->droite->valeur ){ return droite + 1;}

    return (droite + gauche);

}



struct TreeNode* deleteNodeIter(struct TreeNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val == key) {
        // Node to delete is the root
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        } else {
            // Node has two children
            struct TreeNode* successorParent = root;
            struct TreeNode* successor = root->right;

            // Find the successor (the leftmost node in the right subtree)
            while (successor->left != NULL) {
                successorParent = successor;
                successor = successor->left;
            }

            // Copy the key of the successor to the root
            root->val = successor->val;

            // Delete the successor
            if (successor == successorParent->left) {
                successorParent->left = successor->right;
            } else {
                successorParent->right = successor->right;
            }

            free(successor);

            return root;
        }
    }

    // The node to delete is not the root
    struct TreeNode* curr = root;
    struct TreeNode* precurr = root;

    while (curr != NULL && curr->val != key) {
        if (curr->val > key) {
            precurr = curr;
            curr = curr->left;
        } else if (curr->val < key) {
            precurr = curr;
            curr = curr->right;
        }
    }

    if (curr == NULL) {
        return root; // Node not found
    } else {
        // Handle deletion for nodes that are not the root (as you've done)
        // ...

        return root;
    }
}

#endif