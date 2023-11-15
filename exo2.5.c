#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
     printf("Linked List: ");
    // Initialize an empty linked list
    struct ListNode* myList = NULL;
   

    // Add elements to the linked list
    addElement(&myList, 11);
    addElement(&myList, 32);
    addElement(&myList, 53);
    addElement(&myList, 79);
    printf("test");
    
    printf("link before circualr :");
    displayList(myList);

    circularList(myList);
    printf("nombre de noeuds: %d\n", countNodes(myList));
    //checkCircularList(myList);
    

    // Display the linked list
    displayList(myList);
  

    // Free the memory allocated for the linked list
    freeList(myList);

    return 0;
}
