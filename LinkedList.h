#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int data;
    struct ListNode *next;
};


struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addElement(struct ListNode** head, int data) {
    struct ListNode* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct ListNode* current = *head;
        while (current->next != NULL && current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteNode(struct ListNode** head, int value) {
    if (*head == NULL) {
        return;
    }

    struct ListNode* current = *head;
    struct ListNode* prev = NULL;

    do {
        if (current->data == value) {
            if (prev != NULL) {
                prev->next = current->next;
                free(current);
            } else {
                // If the node to be deleted is the first node
                struct ListNode* lastNode = *head;
                while (lastNode->next != *head) {
                    lastNode = lastNode->next;
                }
                if (*head == (*head)->next) {
                    // Special case: Only one node in the list
                    free(*head);
                    *head = NULL;
                } else {
                    // Update pointers to remove the first node
                    lastNode->next = (*head)->next;
                    struct ListNode* temp = *head;
                    *head = (*head)->next;
                    free(temp);
                }
            }
            return;
        }
        prev = current;
        current = current->next;
    } while (current != *head);
}


void displayList(struct ListNode* head) {
    struct ListNode* current = head;

    if (head == NULL) {
        printf("list vide \n");
        return;
    }

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head && current != NULL);
       current == NULL ? printf("NULL\n") : printf("...circular.....\n");
    
}


void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

void circularList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return;  
    }

    struct ListNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head;

    printf("List made circular successfully.\n");
}





void checkCircularList(struct ListNode *head) {
    if (head == NULL) {
        printf("La liste est vide\n");
        return;
    }

    struct ListNode *deb = head->next;

    while (deb != NULL && deb != head) {
        deb = deb->next;
    }

    if (deb == NULL) {
        printf("La liste n'est pas circulaire\n");
                return;

    } else {
        printf("La liste est circulaire\n");
                return;

    }
}

int countNodes(struct ListNode *head){
    if(head == NULL){
        printf("La liste est vide\n");
        return 0;
    }
    int count = 1;
    
    struct ListNode *deb = head->next; 
    while (deb !=NULL && deb != head)
    {
        count++;
        deb = deb->next;
        
    }

    return count;
    
    
}


struct ListNode* reverseList(struct ListNode* head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *pre = NULL;
    struct ListNode *curr = head;
    struct ListNode *nxt = NULL;

    while (curr != NULL) {
        nxt = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nxt;
    }

    return pre;


}

struct ListNode* reverseListrecursive(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode *rest = reverseListrecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}



void checkLoop (struct ListNode* head){
    if (head==NULL){
        printf("list vide\n");
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while (slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast){
            printf("loop found !!\n");
            return;
        }
    }
    printf("loop not found\n");
}

void makeLoop(struct ListNode* head,int n){
    if(head==NULL){
        printf("list vide\n");
    }
    struct ListNode *temp = head;
    struct ListNode *temp2 ;
    int i = 0;
    bool loop = false;
    while (temp->next != NULL){
        temp = temp->next;
        
        if (i==n){
            temp2 = temp;
            loop = true;
        }
        i++;
    }
    
    if(loop){
        temp->next = temp2;
        printf("loop created at Node %d\n" ,n);

    }
    else{
        printf("loop not created\n");
    }
    return;
}

#endif
