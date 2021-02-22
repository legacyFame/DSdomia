#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int priority(char x){
    int p = (x=='+')?1:(x=='-')?1:((x=='*')?2:((x=='/')?2:((x=='^')?3:((x=='(')?0:((x==')')?0:-1))))); //(x=='(')?9:
    return p;
}

int main(){
    char *exp = (char *)malloc(sizeof(100));
    gets(exp);
    char stk[100];
    char x;
    int i =0,top=-1;

    while(i<strlen(exp)){
        x=exp[i];
        i++;
        if(x==' ')
            continue;
        if(isdigit(x)|| priority(x)==-1){
            printf("%c",x);
            x=exp[i];
            while(isdigit(x)){ //muttidigit
                printf("%c",x);
                i++;
                x=exp[i];
            }
            printf(" ");
        }
        else if(x==')'){
            while(top>-1 &&  stk[top]!='('){
                printf("%c ",stk[top]);
                top--;
            }
            top--;
        }
        else if(x=='('){
            top++;
            stk[top]=x;
        }
        else{
            while(top>-1 &&  priority(x)<=priority(stk[top])){
                printf("%c ",stk[top]);
                top--;
            }
            top++;
            stk[top]=x;
        }
    }
    while(top>-1){
        printf("%c ",stk[top]);
        top--;
    }
    return 0;
}