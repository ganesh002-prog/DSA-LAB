 Aim:To implement a program that performs basic stack operations such as push, pop and peek
demonstrating the use of the stack data structure using an array 
#include <stdio.h>

int TOP = -1;
int MAX = 0;

int isFull() {
    return TOP == MAX - 1;
}

int isEmpty() {
    return TOP == -1;
}

void push(int stack[]) {
    int value;
    printf("Enter value to push: ");
    if (scanf("%d", &value) != 1) {
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
        printf("Invalid input. Push cancelled.\n");
        return;
    }

    if (isFull()) {
        printf("Stack Overflow! Cannot push.\n");
    } else {
        TOP++;
        stack[TOP] = value;
        printf("Pushed %d\n", value);
    }
}

void pop(int stack[]) {
    if (isEmpty()) {
        printf("Stack Underflow! Nothing to pop.\n");
    } else {
        printf("Popped element: %d\n", stack[TOP]);
        TOP--;
    }
}

void peek(int stack[]) {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d (index %d)\n", stack[TOP], TOP);
    }
}

void display(int stack[]) {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Current stack elements (top -> bottom):\n");
        for (int i = TOP; i >= 0; i--) {
            if (i == TOP)
                printf("[%d] %d  <-- TOP\n", i, stack[i]);
            else
                printf("[%d] %d\n", i, stack[i]);
        }
    }
}

void clear_stack() {
    TOP = -1;
    printf("Stack cleared.\n");
}

int main() {
    int operation = 0;

    printf("Enter the size of stack (positive integer): ");
    if (scanf("%d", &MAX) != 1 || MAX <= 0) {
        printf("Invalid stack size. Exiting.\n");
        return 1;
    }

    int STACK[MAX];

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display Stack\n5. Display Capacity\n6. Clear Stack\n7. Exit\n");
        printf("Choose operation: ");
        if (scanf("%d", &operation) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            printf("Invalid input. Please enter a number between 1 and 7.\n");
            continue;
        }

        switch (operation) {
            case 1:
                push(STACK);
                display(STACK);
                break;

            case 2:
                pop(STACK);
                display(STACK);
                break;

            case 3:
                peek(STACK);
                break;

            case 4:
                display(STACK);
                break;

            case 5:
                printf("Stack capacity: %d, Current size: %d\n", MAX, TOP + 1);
                break;

            case 6:
                clear_stack();
                break;

            case 7:
                printf("Exiting.\n");
                return 0;

            default:
                printf("Invalid choice! Please select 1-7.\n");
        }
    }

    return 0;
}


output:
Enter the size of stack: 3

1. Push
2. Pop
3. Peek
4. Exit
Choose operation: 1
Enter value to push: 10
Pushed 10
Current stack elements:
10 (TOP)

Choose operation: 1
Enter value to push: 20
Pushed 20
Current stack elements:
20 10 (TOP)

Choose operation: 3
Top element is: 20

Choose operation: 2
Popped element: 20
Current stack elements:
10 (TOP)

Choose operation: 4

result:
The program successfully implements the stack data structure 
using an array and performs the operations push, pop, peek, and display.
