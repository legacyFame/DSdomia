#include <stdio.h>
struct node{
    int data;
    struct node* next;
} head;
struct sll{

    struct node* prev = &head;
    void add(int data){
        struct node new* = (struct node*) malloc(sizeof(node));
        prev->next = new;
        new->data = data;
        prev = new;
    };

};

int main(){
    struct sll s1;
    s1.add(2);


return 0;
}