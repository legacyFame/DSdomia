#include <stdio.h>
#include <stdlib.h>
typedef struct node node;
typedef struct SLL SLL;
//typedef void (*fp)(SLL sl, int data);//function pointer fp
// Return Type       ( * function pointer's variable name ) ( parameters )

struct node {
    int data;
    struct node *next;
} head,n1,n2,n3;
struct SLL {
    node *head;
    node *cur;
    node *temp;
} s1;

void traversal(SLL s1) {
    s1.temp = s1.head->next;
    printf("\n");
    while (s1.temp != NULL) {
        printf("%d ", s1.temp->data);
        s1.temp = s1.temp->next;
    }
    return;
}

//SLL addNode(SLL s1, int data) {
//    node new;
//    new.data = data;
//    new.next = NULL;//Very im
//    s1.temp = s1.head;
//    while (s1.temp->next != NULL) {
//        s1.temp = s1.temp->next;
//    }
//    s1.temp->next = &new;
////    s1.cur->next = &new;
////    s1.cur = s1.cur->next;
////    printf("\n%d",s1.cur->data);
////    traversal(s1);
//    return s1;
//};
node* addNode(int data) {
    node *new = (node*) malloc(sizeof(node));
    new->data = data;
    new->next = NULL;//Very iimp
    return new;
};
SLL addNodes(SLL s1,int data){
    node* f = addNode(data);
    s1.cur->next = (node *) malloc(sizeof(node));
    s1.cur->next = f;
    s1.cur->next = s1.cur->next;
    return s1;
}

SLL delNode(SLL s1, int data) {
    s1.temp = s1.head;
    while (s1.temp->next != NULL) {
        if (s1.temp->next->data == data) {
            s1.temp->next = s1.temp->next->next;
            if (s1.cur->data == data)
                s1.cur = s1.temp; //tail case
            break;
        }
        s1.temp = s1.temp->next;
    }
    traversal(s1);
    return s1;
}

int main() {
    s1.head = &head;
    s1.head->data = NULL;
    s1.cur = s1.head;
    s1.temp = NULL;
    s1 = addNodes(s1,1);
    s1 = addNodes(s1,2);
    s1 = addNodes(s1,3);
//    struct node* p = (node*) malloc(sizeof(node));
////     p = addNode(1);
////    s1.cur->next=p;
////    s1.cur = s1.cur->next;


//    printf("%d", s1.head->next->data);

//    printf("%d",s1.head->next->next->data);
    traversal(s1);
    return 0;
}
//// String manipulation
//#include <stdio.h>
//#include <string.h>
//#include "string.c"
//#define len(arr) (sizeof(arr)/sizeof(arr[0]))
//int main(){
//    char str1[]="Hi Hiro THis is  me Hiii";
//    char **hi = split(str1," ");
//    printf(hi[1]);
//    char *str;
////    str = toString(str,100);
//
//    printf("%s HHS",str);
//return 0;
//}