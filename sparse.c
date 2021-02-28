#include <stdio.h>
#include <stdlib.h>

typedef struct sparse sparse;
typedef struct node node;
struct node {
    struct node *next;
    int row;
    int cln;
    int val;
};
struct sparse {
    struct node *head;
    struct node *cur;
    struct node *temp;
    struct node *temp2;
} sp1;

void addNode(int row, int cln, int val, sparse *sp) {
    node *new = (node *) malloc(sizeof(node));
    new->val = val;
    new->row = row;
    new->cln = cln;
    new->next = NULL;
    sp->cur->next = new;
    sp->cur = sp->cur->next;
}

sparse transpose(sparse sp) {
    sparse res = sp;
    res.temp = res.head->next;
    while (res.temp != NULL) {
        int rw = res.temp->row;
        res.temp->row = res.temp->cln;
        res.temp->cln = rw;
        res.temp = res.temp->next;
    }
    return res;
}

void display(sparse sp) {
    sp.temp = sp.head->next;
    while (sp.temp != NULL) {
        printf("Row %d Cln %d Val %d", sp.temp->row, sp.temp->cln, sp.temp->val);
        sp.temp = sp.temp->next;
    }
}

void selfadd(sparse *A) {
    A->temp = A->head->next;
    A->temp2 = A->head->next;

    int row, cln, val;
    while (A->temp != NULL) {
        row = A->temp->row;
        cln = A->temp->cln;
        val = A->temp->val;
        while (A->temp2 != NULL) {
            if (A->temp2->row == row && A->temp2->cln == cln && A->temp2->val != val)
                A->temp2->val *= val;
        }
    }
}

sparse mul(sparse A, sparse B) {
    sparse tB = transpose(B);
    sparse res;
    node head;
    head.val = NULL;
    head.next = NULL;
    res.head = &head;
    res.cur = &head;
    A.temp = A.head->next;
    tB.temp = tB.head->next;

    while (A.temp != NULL) {
        node *new = (node *) malloc(sizeof(node));
        new->row = A.temp->row;
        new->val = 0;
        res.cur->next = new;
        res.cur = res.cur->next;
        while (tB.temp != NULL) { //Add same clns of A B
            if (A.temp->cln == tB.temp->cln) { //new.cln = tb.row
                new->val += A.temp->val * tB.temp->val;
                new->cln = tB.temp->row;
                break;
            }
        }
        selfadd(&res);
        return res;
    }
}

sparse add(sparse A, sparse B) {
    sparse res;
    node head;
    head.next = NULL;
    res.head = &head;
    res.cur = &head;
    A.temp = A.head->next;
    B.temp = B.head->next;
    while (A.temp != NULL) {
        addNode(A.temp->row, A.temp->cln, A.temp->val, &res);
        A.temp = A.temp->next;
    }
    while (B.temp != NULL) {
        addNode(B.temp->row, B.temp->cln, B.temp->val, &res);
        B.temp = B.temp->next;
    }
    selfadd(&res);
    return res;
}

int main() {
    node head;
    head.val = NULL;
    head.row = NULL;
    head.cln = NULL;
    head.next = NULL;
    sp1.head = &head;
    sp1.cur = &head;
//    int x;
//    void *choice;
//        puts("1. AddNode 2.Display 3.Transpose ")
//        scanf("%d",&x);
//        choice = (x==1)?addNode():
    return 0;
}