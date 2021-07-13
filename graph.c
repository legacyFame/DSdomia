#include <stdio.h>
#include <stdbool.h>
#include "string.c"

typedef struct graph graph;
enum V {
    a, b, c
};

struct graph {
    int vc; //total no of vertices
    char *adjmat; //adjacency matrix
} G1;

bool visit(const int arr[], int item, int size) {
    bool flag = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == item) {
            flag = true;
            break;
        }
    }
    return flag;
}

void DFS(graph G) {
    char **rows;
    char **row;
    char *adjmat = G.adjmat;
    int vs = G.vc;
    rows = split(adjmat, ",");
    int stk[vs + 1], visited[vs + 1], top = 0, vi = 0, item;

    stk[top++] = a; // 1st step
    visited[vi++] = a; //Advance visit
    while (top > 0) {
        item = stk[top--];
        printf("\nItems-%d\n", item);
        row = split(rows[item], " ");
        for (int i = a; i < vs; i++) {
            if (toInt("1") == toInt(row[i]) && !visit(visited, i, vi)) {//== or strcmp not working..
                stk[top++] = i;
                visited[vi++] = i;
            }
        }
    }
}

void BFS(graph G) {
    char **rows;
    char **row;
    char *adjmat = G.adjmat;
    int vs = G.vc;
    rows = split(adjmat, ",");
    int q[vs + 1], visited[vs + 1], r = 0, f = 0, vi = 0, item;

    q[r++] = a; // 1st step
    visited[vi++] = a; //Advance visit
    while (f < r) {
        item = q[f++];
        printf("\nItems-%d\n", item);
        row = split(rows[item], " ");
        for (int i = a; i < vs; i++) {
            if (toInt("1") == toInt(row[i]) && !visit(visited, i, vi)) {//== or strcmp not working..
                q[r++] = i;
                visited[vi++] = i;
            }
        }
    }
}

int main() {
//    char adjmat[] = " 0 1 1 , 1 0 1 , 1 1 0 "; //0 1 1 1, 1 0 1 1, 1 1 0 1, 1 1 1 0
    char adjmat[100];
    gets(adjmat);
    G1.adjmat = adjmat;
    G1.vc = 3;
//    DFS(G1);
//    BFS(G1);
    return 0;
}