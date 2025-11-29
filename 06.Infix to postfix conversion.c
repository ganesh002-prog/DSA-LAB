Aim:
To write a C program that converts an infix expression (like A+B*C) into a postfix expression (like ABC*+) using a stack. 
This program should follow operator precedence and use stack operations for the conversion.

Program:
#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[]) {
    char postfix[20];
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[k++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            if (top != -1) pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[20];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}


sample output:
Enter infix expression: A+B*C
Postfix expression: ABC*+


Result:
The program successfully converts a given infix expression into its equivalent also shows how infix to postfix works.
