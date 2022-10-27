#include <stdio.h>
#include "node.h"
#include "linkedlist.h"

int main() {
    // testing the node 'class'
    struct node node1 = { NULL, 100.0, NULL };
    printf("Node 1 Value: %lf\n", getVal(&node1));
    setVal(&node1, 100.1);
    printf("Node 1 Value: %lf\n", getVal(&node1));

    // testing empty LL functionality
    struct linkedList LLTEST = { NULL, 0 };
    printf("Testing Empty LL functionality.\n");
    printf("Printing an empty LL.\n");
    printLinkedList(&LLTEST);
    removeNode(&LLTEST, 10.0);
    insertNode(&LLTEST, 10.0);
    printf("Printing a LL with one node, 10.\n");
    printLinkedList(&LLTEST);
    printf("LL size is: %d (should be %d)\n", getSize(&LLTEST), 1);
    removeNode(&LLTEST, 10.0);
    printf("Printing an empy LL.\n");
    printLinkedList(&LLTEST);
    printf("LL size is: %d (should be %d)\n", getSize(&LLTEST), 0);

    // testing the linked list 'class' for normal use cases
    struct linkedList LL = { &node1, 1 };
    printf("Printing the Linked list before additional nodes are added.\n");
    printLinkedList(&LL);
    insertNode(&LL, 99.9);
    printf("Added 101.0 as a node value to the linked list.\n");
    printLinkedList(&LL);
    insertNode(&LL, 101.0);
    printf("Added 101.0 as a node value to the linked list.\n");
    printLinkedList(&LL);
    insertNode(&LL, 103.0);
    printf("Added 103.0 as a node value in the linked list.\n");
    printLinkedList(&LL);
    insertNode(&LL, 102.0);
    printf("Added 102.0 as a node value in the linked list.\n");
    printLinkedList(&LL);
    insertNode(&LL, 102.0);
    printf("Added 102.0 as a node value in the linked list, again.\n");
    printLinkedList(&LL);
    insertNode(&LL, 99.0);
    printf("Added 99.0 as a node value in the linked list.\n");
    printLinkedList(&LL);
    insertNode(&LL, 99.5);
    printf("Added 99.5 as a node value in the linked list.\n");
    printLinkedList(&LL);
    insertNode(&LL, 101.5);
    printf("Added 101.5 as a node value in the linked list.\n");
    printLinkedList(&LL);
    removeNode(&LL, 102.0);
    printf("Removed 102.0 from the linked list.\n");
    printLinkedList(&LL);
    removeNode(&LL, 99.0);
    printf("Removed 99.0 from the linked list.\n");
    printLinkedList(&LL);
    removeNode(&LL, 102.0);
    printf("Removed 102.0 from the linked list.\n");
    printLinkedList(&LL);
    removeNode(&LL, 103.0);
    printf("Removed 103.0 from the linked list.\n");
    printLinkedList(&LL);
    printf("LL size is: %d\n", getSize(&LL));

    return 0;
}