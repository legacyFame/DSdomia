#include <stdio.h>
#include <stdbool.h>
#include "string.c"

enum V {
    a, b, c
};

bool visit(int arr[], int item, int size) {
    bool flag = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == item) {
            flag = true;
            break;
        }
    }
    return flag;
}


int main() {
    char *adjmat, **rows, **row;
    int *stk = (int *) malloc(100), top=-1,vi = -1, item;
    adjmat = "0 1 1 , 1 0 1 , 1 1 0";
    rows = split(adjmat, ",");
    int size = len(adjmat, ",");
    int visited[size];

    top++;
    stk[top] = a; // 1st step
    while (top > -1) {
        printf("%d",top);
        item = stk[top];
        top--;
        vi++;
        visited[vi] = item;
        row = split(rows[item], " ");
        for (int i = 0; i < size; i++) {
            if (toInt(row[i]) == 1) {
                if (!visit(visited, i, vi)) {
                    top++;
                    stk[top]=i;
                }
            }
        }
    }
    return 0;
}