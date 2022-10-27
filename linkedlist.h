#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct linkedList {
    struct node * head;
    long size;
};

struct node * getHead(struct linkedList * LL) {
    return LL->head;
}

void setHead(struct linkedList * LL, struct node * n) {
    LL->head = n;
}

long getSize(struct linkedList * LL) {
    return LL->size;
}

void setSize(struct linkedList * LL, double newsize) {
    LL->size = newsize;
}

void insertNode(struct linkedList * LL, double value) {
    struct node * n = (struct node *)malloc(sizeof(struct node));
    struct node * iter = getHead(LL);

    // set up the new node
    n->prev = NULL;
    n->val = value;
    n->next = NULL;

    if (iter == NULL) {
        // LL was empty
        setHead(LL, n);
        setSize(LL, getSize(LL) + 1);
        return;
    }

    // iterate through the linked list till end or where the node needs to go
    while (iter != NULL) {
        if (iter->val >= n->val) {
            if (iter->prev == NULL) {
                // new head
                iter->prev = n;
                n->next = iter;
                setSize(LL, getSize(LL) + 1);
                setHead(LL, n);
                return;
            } else {
                // insert into list between two existing nodes
                iter->prev->next = n;
                n->prev = iter->prev;
                iter->prev = n;
                n->next = iter;
                setSize(LL, getSize(LL) + 1);
                return;
            }
        } else {
            if (iter->next == NULL) {
                // new last node
                iter->next = n;
                n->prev = iter;
                setSize(LL, getSize(LL) + 1);
                return;
            } else {
                // iterate
                iter = iter->next;
            }
        }
    }
}

void removeNode(struct linkedList * LL, double value) {
    struct node * iter = getHead(LL);

    while (iter != NULL) {
        if (iter->val == value) {
            if (iter->prev == NULL && iter->next == NULL) {
                // LL is being made empty
                setHead(LL, NULL);
                setSize(LL, getSize(LL) - 1);
                return;
            } else if (iter->prev != NULL && iter->next == NULL) {
                // new last node
                iter->prev->next = iter->next;
                free(iter);
                setSize(LL, getSize(LL) - 1);
                return;
            } else if (iter->prev == NULL && iter->next != NULL) {
                // new head
                iter->next->prev = NULL;
                setHead(LL, iter->next);
                setSize(LL, getSize(LL) - 1);
                return;
            } else {
                // remove node between two existing nodes
                iter->prev->next = iter->next;
                iter->next->prev = iter->prev;
                free(iter);
                setSize(LL, getSize(LL) - 1);
                return;
            }
        }

        iter = iter->next;
    }

    printf("NOTICE: %lf was not found in the linked list.\n", value);
}

void printLinkedList(struct linkedList * LL) {
    struct node * iter = getHead(LL);

    // iterate through the linked list and print the value of each node
    while (iter != NULL) {
        printf("Node value: %lf\n", getVal(iter));
        iter = iter->next;
    }

    //printf("PRINTED THE ENTIRE LINKED LIST.\n");
}

#endif