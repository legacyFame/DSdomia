#include <stdio.h>
#include <stdlib.h>
#include "string.c"

typedef struct node node;
typedef struct poly poly;

struct node {
    int exp;
    int coef;
    node *next;
} chead;

struct poly {
    node *head;
    node *cur;
    node *temp;

} A, B, C;

void *inialize(poly *p) {
    node *head = (node *) malloc(sizeof(node));
    head->next = NULL;
    p->head = head;
    p->cur = head;
    puts("COEF EXP");
    char *in = input();
    while (strlen(in) > 0) {
        node *new = (node *) malloc(sizeof(node));
        char **li = split(in, " ");
//        if(sizeof(li)/sizeof(li[0]) <2) continue;
        new->exp = toInt(li[1]);
        new->coef = toInt(li[0]);
        new->next = NULL;
        p->cur->next = new;
        p->cur = p->cur->next;
        puts("COEF EXP");
        in = input();
    }
}

void display(poly *p) {
    p->temp = p->head->next;
    while (p->temp != NULL) {
        printf("%dx^%d", p->temp->coef, p->temp->exp);
        p->temp = p->temp->next;
        if (p->temp != NULL)
            printf("+");
    }
    puts("");
}

void *add() {
    A.temp = A.head->next;
    B.temp = B.head->next;
    chead.next = NULL;
    C.head = &chead;
    C.cur = C.head;
    int exp, cf;
    while (A.temp != NULL && B.temp != NULL) {
        node *new = (node *) malloc(sizeof(node));
        if (A.temp->exp == B.temp->exp) {
            exp = A.temp->exp;
            cf = A.temp->coef + B.temp->coef;
            A.temp = A.temp->next;
            B.temp = B.temp->next;
        } else if (A.temp->exp < B.temp->exp) {
            exp = B.temp->exp;
            cf = B.temp->coef;
            B.temp = B.temp->next;
        } else {
            exp = A.temp->exp;
            cf = A.temp->coef;
            A.temp = A.temp->next;
        }
        new->coef = cf;
        new->exp = exp;
        new->next = NULL;
        C.cur->next = new;
        C.cur = C.cur->next;
    }
    while (A.temp != NULL) {
        node *new = (node *) malloc(sizeof(node));
        new->coef = A.temp->coef;
        new->exp = A.temp->exp;
        new->next = NULL;
        C.cur->next = new;
        C.cur = C.cur->next;
        A.temp = A.temp->next;
    }
    while (B.temp != NULL) {
        node *new = (node *) malloc(sizeof(node));
        new->next = NULL;
        new->coef = B.temp->coef;
        new->exp = B.temp->exp;
        C.cur->next = new;
        C.cur = C.cur->next;
        B.temp = B.temp->next;
    }
    display(&C);
}

void *mul() {
    A.temp = A.head->next;
    B.temp = B.head->next;
    chead.next = NULL;
    C.head = &chead;
    C.cur = C.head;
    w1:
    while (A.temp != NULL) {
        node *new = (node *) malloc(sizeof(node));
        new->next = NULL;
        while (B.temp != NULL) {
            new->coef = A.temp->coef * B.temp->coef;
            new->exp = A.temp->exp + B.temp->exp;
            C.cur->next = new;
            C.cur = C.cur->next;
            B.temp = B.temp->next;
            goto w1; //break not working
        }
        B.temp = B.head->next;
        A.temp = A.temp->next;
    }
    display(&C);
};

int main() {
    puts("Polynomial A");
    inialize(&A);
    puts("Polynomial B");
    inialize(&B);
    int x;
    while (1) {
        puts("1. Add 2.Multiply ");
        scanf("%d", &x);
        void *choice = (x == 1) ? add() : mul();
    }
    return 0;
}