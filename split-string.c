
// String manipulation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** split(char str[]){
    char *token = strtok(str, " ");
    char **answer;int top=0;
    answer = (char **) malloc(sizeof(token));
    while (token!=NULL){
//        printf("%s",token);
        answer[top] = token;
        top++;
        token = strtok(NULL, " ");}
    return answer;
}

//int main(){
//    char str[]="Hi Hiro shdhsdhhs sdhsh";
//    char **hi = split(str);
////    for(int i=0; i<sizeof(hi);i++){
////        printf(hi[i]);
////    }
//return 0;
//}