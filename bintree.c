#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
typedef struct node node;
typedef struct BT BT;

struct node {
    int data;
    struct node *lc;
    struct node *rc;
} root;

struct BT {
    node *root;
    node *parent;
    node *lc;
    node *rc;
    node *cur;
} bt1;

node* addNode(node* parent,node* new){
    if(parent == NULL) return NULL;
    if(parent->lc== NULL) parent->lc=new;
    else addNode(parent->lc->lc,new);
    if(parent->rc== NULL) parent->rc=new;
    else addNode(parent->rc->lc,new);
    return parent;
}

void *append() {
    int data;
    printf("Item?");
    scanf("%d", &data);
    node *new = (node *) malloc(sizeof(node));
    new->data = data;
    new->rc = NULL;
    new->lc = NULL;
    addNode(bt1.root,new);
    return NULL;
};

void *delTree(node* tree) {
    delTree(tree->lc);
    delTree(tree->rc);
    free(tree);
    return NULL;
}

void *inorder(struct node* parent) {
    if (parent == NULL) return NULL;
    inorder(parent->lc);
    printf("%d ->", parent->data);
    inorder(parent->rc);
}

void *preorder(struct node* parent) {
    if (parent == NULL) return NULL;
    printf("%d ->", parent->data);
    preorder(parent->lc);
    preorder(parent->rc);
}

// Postorder traversal
void *postorder(struct node* parent) {
    if (parent == NULL) return NULL;
    postorder(parent->lc);
    postorder(parent->rc);
    printf("%d ->", parent->data);
}

void* traversal() {
    void *p;
    int x;
    puts("1. In , 2. Pre , 3. Post Order");
    scanf("%d", x);
    p = (x == 1) ? inorder(bt1.root) : ((x == 2) ? preorder(bt1.root) : postorder(bt1.root));
    return p;
}

int main() {
    root.data = NULL;
    root.lc = NULL;
    root.rc = NULL;
    bt1.root = &root;
//    bt1.parent = &root;
//    bt1.lc = NULL;
//    bt1.rc = NULL;

    int x;
    void *choice;
    while (1) {
        printf("\n1. Append 2. Delete 3.Traverse");
        scanf("%d", &x);
        choice = (x == 1) ? append() : ((x == 2) ? delTree(bt1.root) : traversal());
    }

    return 0;
}