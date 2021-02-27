#include <stdio.h>
#include <stdlib.h>
#include "string.c"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
typedef struct node node;
typedef struct SLL SLL;
//typedef void (*fp)(SLL sl, int data);//function pointer fp
// Return Type       ( * function pointer's variable name ) ( parameters )

struct node {
    int data;
    struct node *next;
} head;

struct SLL {
    node *head;
    node *tail;
    node *cur;
} s1;

void *traversal() {
    s1.cur = s1.head->next;
    if (s1.cur == NULL)
        puts("Empty");
    while (s1.cur != NULL) {
        printf("%d ", s1.cur->data);
        s1.cur = s1.cur->next;
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
    s1.tail->next = new;
    s1.tail = new;
    return NULL;
}

void *delNode() {
    int data;
    printf("Node?");
    scanf("%d", &data);
    s1.cur = s1.head;
    while (s1.cur->next!=NULL) {
        if (s1.cur->next->data == data) {
            s1.cur->next = s1.cur->next->next;
            if (s1.tail->data == data)
                s1.tail = s1.cur; //tail case
            return NULL;
        }
        s1.cur = s1.cur->next;
    }
    printf("\nNot in SLL");
    return NULL;
}

void *search(){
    int data = 0,pos=0;
    printf("Node?");
    scanf("%d", &data);
    s1.cur = s1.head->next;
    while (s1.cur != NULL && s1.cur->data!=data) {
        s1.cur = s1.cur->next;
        pos++;
    }
    if(s1.cur->data==data) printf("\nPresent %d",pos);
    else puts("Not Present");
    return NULL;
}

int main() {
    s1.head = &head;
    s1.head->data = NULL;
    s1.tail = s1.head;
    s1.cur = NULL;
    int x;
    void *choice ;
    while (1) {
        printf("\n1. Append 2. Delete 3.Display 4. Search ");
        scanf("%d", &x);
        choice = (x == 1) ? addNode() : ((x == 2) ? delNode() :((x==4)?search(): traversal()));
    }
    return 0;
}