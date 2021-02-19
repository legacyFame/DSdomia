
// String manipulation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char** split(char str[], char delims[]) {
    char *token = strtok(str, delims);
    char **answer= (char **) malloc(sizeof(token)*50);
    int top = 0;
    while (token != NULL) {
        answer[top] = token;
        top++;
        token = strtok(NULL, delims);
    }
    return answer;
}

int len(char str[], char delims[]) {
    char *token = strtok(str, delims);
    int size = 0;
    while (token != NULL) {
        size++;
        token = strtok(NULL, delims);
    }
    return size;
}

int toInt(char c[]) {
    int value;
    sscanf(c, "%d", &value);
    return value;
}

char* toString(char *str, int no) { // usage - char *str; str = toString(str,100);
    sprintf(str, "%d", no);
    return str;
}
bool isequal(char str[], char str1[]){
    if(str==str1)
        return true;
    return false;
}
//int main(){
//    char str[]="Hi Hiro";
//    char **hi = split(str);
////    for(int i=0; i<sizeof(hi);i++){
////        printf(hi[i]);
////    }
//return 0;
//}