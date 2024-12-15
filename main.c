//1. Calculator Problem Statement-

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPR_LEN 100
//check operator
int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
//evaluate based on the operator
int apply_op(int x, int y, char op) {
    switch(op) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': 
            if (y == 0) {
                printf("Error: Division by zero.\n");
                exit(1);
            }
            return x / y;
        default: 
            return 0;
    }
}
//get precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
//evaluate expression
int evaluate_expression(char* expr) {
    int values[MAX_EXPR_LEN], values_top = -1;
    char ops[MAX_EXPR_LEN];
    int ops_top = -1;

    for (int i = 0; i < strlen(expr); i++) {
        if (isspace(expr[i])) continue;
        if (isdigit(expr[i])) {
            int value = 0;
            while (i < strlen(expr) && isdigit(expr[i])) {
                value = value * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            values[++values_top] = value;
        }
        else if (is_operator(expr[i])) {
            while (ops_top != -1 && precedence(ops[ops_top]) >= precedence(expr[i])) {
                int val2 = values[values_top--];
                int val1 = values[values_top--];
                char op = ops[ops_top--];
                values[++values_top] = apply_op(val1, val2, op);
            }
            ops[++ops_top] = expr[i];
        }
        else {
            printf("Error: Invalid expression.\n");
            exit(1);
        }
    }
    while (ops_top != -1) {
        int val2 = values[values_top--];
        int val1 = values[values_top--];
        char op = ops[ops_top--];
        values[++values_top] = apply_op(val1, val2, op);
    }

    return values[values_top];
}
//main function
int main() {
    char expr[MAX_EXPR_LEN];

    printf("Enter an expression: ");
    if (fgets(expr, MAX_EXPR_LEN, stdin) == NULL) {
        printf("Error: Invalid expression.\n");
        exit(1);
    }
    expr[strcspn(expr, "\n")] = 0;

    int result = evaluate_expression(expr);
    printf("Result: %d\n", result);

    return 0;
}
//end