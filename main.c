#include <stdio.h>
#include <stdbool.h>
#include "string.c"

enum V {
    a, b, c
};

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


int main() {
    char **rows;
    char **row;
    int stk[c + 1], visited[c + 1], top = -1, vi = -1, item, vs = 3;
    char adjmat[] = " 0 1 1 , 1 0 1 , 1 1 0 ";
    rows = split(adjmat, ",");
    top++;
    stk[top] = b; // 1st step
    visited[vi] = stk[top]; //Advance visit
    while (top > -1) {
        item = stk[top];
        printf("\nItems-%d\n", item);
//        printf(rows[item]);
        top--;
        vi++;
        row = split(rows[item], " ");
        for (int i = a; i < vs; i++) {
            if(toInt(row[i])==1 && !visit(visited, i, vi)) {
                top++;
                stk[top] = i;
                vi++;
                visited[vi] = i;
            }
        }
    }
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