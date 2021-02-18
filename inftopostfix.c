#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

/** Infinix to postfix
 * author - Hiro*/
int main() {
    bool checkoperator(char op);
    int priority(char c);
    int top = -1, i = 0;
    char *stk, *exp, op;
    stk = (char *) malloc(100);
//    exp = "12 + 2 * 3";
    exp = (char *) malloc(100);
    gets(exp);
    printf("Infinix expresion %s\n", exp);
    while (i < strlen(exp)) {
        op = exp[i];
        i++;
        if (op == ' ')
            continue;
        else if (checkoperator(op)) {
            while (top > -1 && priority(op) <= priority(stk[top])) {
//              printf("%c ", stk[top]);
                putchar(stk[top]);
                top--;
            }
            if (op == ')' || op == '(')
                continue;
            top++;
            stk[top] = op;
        } else if (isdigit(op)) {
            while (isdigit(op)) {
                printf("%c", op); // for multi digit nos
                op = exp[i];
                i++;
            }
            printf(" ");
        }
    }
    while (top > -1) {
        printf("%c ", stk[top]);
        top--;
    }
}

bool checkoperator(char op) { // Not necessary isdigit should do everything .. just to ensure other symbols ..
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
    int priority = (c == '+') ? 1 : ((c == '-') ? 1 : ((c == '*') ? 2 : ((c == '^') ? 3 : ((c == '/') ? 2 : ((c == ')')
                                                                                                             ? 9
                                                                                                             : 9)))));
    return priority;
}