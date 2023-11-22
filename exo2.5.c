#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
     printf("Linked List: \n");
    // Initialize an empty linked list
    struct ListNode* myList = NULL;
   

    // Add elements to the linked list
    addElement(&myList, 11);
    addElement(&myList, 32);
    addElement(&myList, 53);
    addElement(&myList, 79);
    addElement(&myList, 12);
    addElement(&myList, 45);
    addElement(&myList, 67);
    addElement(&myList, 89);
    addElement(&myList, 90);
    addElement(&myList, 100);
    addElement(&myList, 110);
    addElement(&myList, 120);
    addElement(&myList, 130);
    addElement(&myList, 140);
    addElement(&myList, 150);
    addElement(&myList, 160);
    addElement(&myList, 170);
    addElement(&myList, 180);
    addElement(&myList, 190);
    addElement(&myList, 200);
    addElement(&myList, 210);
    addElement(&myList, 220);
    addElement(&myList, 230);
    addElement(&myList, 240);
    addElement(&myList, 250);
    addElement(&myList, 260);
    addElement(&myList, 270);
    addElement(&myList, 280);
    addElement(&myList, 290);
    addElement(&myList, 300);
    addElement(&myList, 310);




    makeLoop(myList, 29);
    checkLoop(myList);
    // Display the linked list
  

    // Free the memory allocated for the linked list
    //freeList(myList);

    return 0;
}
