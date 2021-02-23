#include <stdio.h>
#include <stdlib.h>
#include "string.c"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
typedef struct node node;
typedef struct DLL DLL;
//typedef void (*fp)(DLL sl, int data);//function pointer fp
// Return Type       ( * function pointer's variable name ) ( parameters )

struct node {
    int data;
    struct node *prev;
    struct node *next;
} head;

struct DLL {
    node *head;
    node *tail;
    node *cur;
} d1;

void *traversal() {
    d1.cur = d1.head->next;
    if (d1.cur == NULL)
        puts("Empty");
    while (d1.cur != NULL) {
        printf("%d ", d1.cur->data);
        d1.cur = d1.cur->next;
    }
    return NULL;
}

void *addNode() {
    int data;
    printf("Item?");
    scanf("%d", &data);
    node *new = (node *) malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    new->prev = d1.tail;
    d1.tail->next = new;
    d1.tail = new;
    return NULL;
}

void *delNode() {
    int data;
    node temp;
    printf("Node?");
    scanf("%d", &data);
    d1.cur = d1.head->next;
    while (d1.cur != NULL) {
        if (d1.cur->data == data) {
            if (d1.tail->data == data) d1.tail = d1.tail->prev;
            d1.cur->next->prev = d1.cur->prev;
            d1.cur->prev = d1.cur->next;
            free(d1.cur);
            return NULL;
        }
        d1.cur = d1.cur->next;
    }
    printf("Not in DLL");
    return NULL;
}

void *search() {
    int data = 0, pos = 0;
    printf("Node?");
    scanf("%d", &data);
    d1.cur = d1.head->next;
    while (d1.cur != NULL && d1.cur->data != data) {
        d1.cur = d1.cur->next;
        pos++;
    }
    if (d1.cur->data == data) printf("\nPresent %d", pos);
    else puts("Not Present");
    return pos;
}

int main() {
    d1.head = &head;
    d1.head->data = NULL;
    d1.tail = d1.head;
    d1.cur = NULL;
    int x;
    void *choice;
    while (1) {
        printf("\n1. Append 2. Delete 3.Display 4.Search ");
        scanf("%d", &x);
        choice = (x == 1) ? addNode() : ((x == 2) ? delNode() : ((x == 4)) ? search() : traversal());
    }
    return 0;
}