#include<stdio.h>
#include<stdbool.h>

#define size 5

char item[8];
int rear = size;
int front = -1;
int q[size];

bool isfull() {
    if (front >= rear - 1) { return true; }
    return false;
}

bool isempty() {
    if (front == -1 && rear == size)
        return true;
    return false;
}

void* display() {
    if (isempty()) {
        printf("Empty");
        return;
    }
    for (int i = 0; i <= front; i++) { printf("%d ", q[i]); } //front *p print
    for (int i = size - 1; i >= rear; i--) { printf("%d ", q[i]); }
    return;
}

const char *pop() {
    if (front == -1) { return "Empty"; }
    else {
        sprintf(item, "%d", q[front]);
        front--;
        return item;
    }
}

const char *deq() {
    if (rear == size) { return "Empty"; }
    else {
        sprintf(item, "%d", q[rear]);
        rear++;
        return item;
    }
}

void* enq() {
    if (isfull()) { printf("q overflow"); }
    else {
        printf("Item????");
        rear--;
        scanf("%d", &q[rear]);
        printf("Item added");
    }
    return;
}

void* push() {
    if (isfull()) { printf("q overflow"); }
    else {
        printf("Item????");
        front++;
        scanf("%d", &q[front]);
        printf("Item added");
    }
    return;
}


void main() {
    int x;
    void *choice;
    while (1) {
        printf("\n 1. enq 2. deq 3.Display 4. push 5. pop ");
        scanf("%d", &x);
        choice = (x==1)?enq():((x==2)?puts(deq()):((x==3)?display():(x==4)?push():puts(pop())));
    }
}