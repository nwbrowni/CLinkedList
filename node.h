#ifndef NODE_H
#define NODE_H

struct node {
    struct node * prev;
    double val;
    struct node * next;
};

struct node * getPrev(struct node * n) {
    return n->prev;
}

void setPrev(struct node * n, struct node * newprev) {
    n->prev = newprev;
}

double getVal(struct node * n) {
    return n->val;
}

void setVal(struct node * n, double newval) {
    n->val = newval;
}

struct node * getNext(struct node * n) {
    return n->next;
}

void setNext(struct node * n, struct node * newnext) {
    n->next = newnext;
}

#endif