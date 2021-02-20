#include <stdio.h>
#include<stdlib.h>

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
    node *cur;
};

struct node* addNode(struct node* cur, int data) {
    node *new = (node *) malloc(sizeof(node));
    new->data = data;
    cur->next=new;
    cur = cur->next;
};

int main() {
    SLL s1;
    s1.head = &head;
    s1.cur = s1.head;
    s1.head->next = s1.cur;
    addNode(s1.cur, 2);
    addNode(s1.cur, 23);
    addNode(s1.cur, 232);
    printf("%d",s1.head->data);
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