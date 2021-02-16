#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

/** Postfix evaluation
 *
 * author - Hiro*/

int main() {
    bool checkoperator(char op);
    int priority(char c);
    int top = -1, i = 0;
    char *stk="", op;
    char *exp = "1 + 2";
    printf("Infinix expresion %s\n", exp);
    while (i < strlen(exp)) {
        op = exp[i];
        i++;
//        printf("Stk top %c %d \n",stk[top],top);
        if (op == ' ')
            continue;
        else if (checkoperator(op)) {
            while (top > -1 && priority(op) >= priority(stk[top])) {
                printf("%c ", stk[top]);
                top--;
            }
            if(op==')'|| op=='(')
                continue;
            top++;
            stk[top] = op;
        } else if (isdigit(op)) {
            char *string = "";
            while (isdigit(op)) {
                strncat(string, &op, 1);
                op = exp[i];
                i++;
            }
            printf("%s ", string);
        }
    }
    while(top>-1){
        printf(&stk[top]);
        top--;
    }
}

bool checkoperator(char op) {
    char operators[] = {'+', '-', '/', '^', '*', ')', '('};
    bool flag = false;
    for (int i = 0; i < 7; i++) {
        if (op == operators[i]) {
            flag = true;
            break;
        }
    }
    return flag;
}

int priority(char c) {
    int priority = (c=='+')?1:((c=='-')?1:((c=='*')?2:((c=='^')?3:((c=='/')?2:((c==')')?9:0)))));
    return priority;
}




