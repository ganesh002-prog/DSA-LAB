Aim:
To reverse a string entered by the user using a stack.

Program:
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top != MAX - 1) {
        top++;
        stack[top] = c;
    }
}

char pop() {
    if (top != -1) {
        char c = stack[top];
        top--;
        return c;
    }
    return '\0';
}

int main() {
    char str[MAX];
    printf("Enter a string to reverse: ");
    fgets(str, MAX, stdin);

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    for (size_t i = 0; i < len; i++) {
        push(str[i]);
    }

    printf("Reversed string: ");
    for (size_t i = 0; i < len; i++) {
        printf("%c", pop());
    }
    printf("\n");

    return 0;
}

Enter a string to reverse: hello
Reversed string: olleh

result: The program successfullY demonstrates string reversal using POP & PUSH.
