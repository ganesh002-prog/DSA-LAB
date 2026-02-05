AIM:
To write a C program that uses an array to implement a stack and performs basic stack operations such as Push, Pop, Peek, and Display.

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
        printf("Invalid input! Push cancelled.\n");
        while (getchar() != '\n');
        return;
    }

    if (isFull()) {
        printf("Stack Overflow! Cannot push.\n");
    } else {
        TOP++;
        stack[TOP] = value;
        printf("Pushed %d into the stack.\n", value);
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
        printf("Top element: %d (at index %d)\n", stack[TOP], TOP);
    }
}

void display(int stack[]) {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (Top to Bottom):\n");
        for (int i = TOP; i >= 0; i--) {
            if (i == TOP)
                printf("[%d] %d <-- TOP\n", i, stack[i]);
            else
                printf("[%d] %d\n", i, stack[i]);
        }
    }
}

void clearStack() {
    TOP = -1;
    printf("Stack has been cleared.\n");
}

int main() {
    int choice;
    
    printf("Enter the size of the stack: ");
    if (scanf("%d", &MAX) != 1 || MAX <= 0) {
        printf("Invalid stack size.\n");
        return 1;
    }

    int STACK[MAX];

    while (1) {
        printf("\n----- STACK MENU -----\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Stack Capacity\n6. Clear Stack\n7. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: push(STACK); break;
            case 2: pop(STACK); break;
            case 3: peek(STACK); break;
            case 4: display(STACK); break;
            case 5: printf("Capacity: %d, Current size: %d\n", MAX, TOP + 1); break;
            case 6: clearStack(); break;
            case 7: printf("Exiting program.\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}


OUTPUT:
Enter the size of the stack: 3

----- STACK MENU -----
1. Push
2. Pop
3. Peek
4. Display
5. Stack Capacity
6. Clear Stack
7. Exit
Enter your choice: 1
Enter value to push: 10
Pushed 10 into the stack.

Enter your choice: 1
Enter value to push: 20
Pushed 20 into the stack.

Enter your choice: 3
Top element: 20 (at index 1)

Enter your choice: 2
Popped element: 20

Enter your choice: 4
Stack elements (Top to Bottom):
[0] 10 <-- TOP

RESULT:
The program successfully demonstrates how a stack works using an array and performs operations such as push, pop, peek, and display.
  It helps understand the LIFO (Last In, First Out) nature of the stack data structure.
 
