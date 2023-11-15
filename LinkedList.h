#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>

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
    // Create a new node with the given data
    struct ListNode* newNode = createNode(data);

    // If the linked list is empty, set the new node as the head
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Traverse to the end of the linked list and add the new node
        struct ListNode* current = *head;
        while (current->next != NULL && current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteNode(struct ListNode** head, int value) {
    if (*head == NULL) {
        // Empty list, nothing to delete
        return;
    }

    struct ListNode* current = *head;
    struct ListNode* prev = NULL;

    // Traverse the list to find the node with the given value
    do {
        if (current->data == value) {
            // Node found, update pointers to remove the node
            if (prev != NULL) {
                // If the node to be deleted is not the first node
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

    if (current == NULL) {
        printf("NULL\n");
        return;
    }

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("NULL\n");
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
        return;  // Nothing to do for an empty or single-node list
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

#endif
