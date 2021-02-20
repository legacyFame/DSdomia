#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
/** Postfix evaluation
 * author - Hiro*/

int main() {
    bool checkoperator(char op);
    int performoperation(int a, int b, char c);
    int toInt(char c[]);
    int stk[100], top = -1, operand1, operand2, i = 0;
    char op;
    char *exp = "5 3 2 + 8 * +";
    while (i < strlen(exp)) {
        op = exp[i];
        i++;
        if (op == ' ')
            continue;
        else if (checkoperator(op)) {
            operand1 = stk[top];
            top--;
            operand2 = stk[top];
            stk[top] = performoperation(operand2, operand1, op);
        } else if (isdigit(op)) {
            char string[8] = "";
            while (isdigit(op)) {
                strncat(string, &op, 1);
                op = exp[i];
                i++;
            }
            top++;
            stk[top] = toInt(string);
        }
    }
    printf("Evaluation of Postfix-%d", stk[top]);
    return 0;
}

bool checkoperator(char op) {
    char operators[] = {'+', '-', '/', '^', '*'};
    bool flag = false;
    for (int i = 0; i < 5; i++) {
        if (op == operators[i]) {
            flag = true;
            break;
        }
    }
    return flag;
}

int performoperation(int a, int b, char c) {
    int result = (c=='+')?(a+b):((c=='-')?(a-b):((c=='*')?(a*b):((c=='^')?(a^b):((c=='/')?(a/b):0))));
    //    printf("%d %c %d = %d \n", a, c, b, result);
    return result;
}

int toInt(char c[]) {
    int value;
    sscanf(c, "%d", &value);
    return value;
}



