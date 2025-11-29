Aim:
To implement a stack using a linked list in C and perform basic operations.
 like push, pop, and display. The stack should dynamically manage memory using nodes created at runtime.

Program:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* Top = NULL;

struct Node* CreateNewNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode != NULL) {
        newNode->data = x;
        newNode->next = NULL;
    }
    return newNode;
}

void push(int x) {
    struct Node* newNode = CreateNewNode(x);
    if(newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->next = Top;
    Top = newNode;
    printf("Element pushed into stack\n");
}

int pop() {
    if(Top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    int popped = Top->data;
    struct Node* temp = Top;
    Top = Top->next;
    free(temp);
    return popped;
}

void display() {
    if(Top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* t = Top;
    printf("Stack elements are:\n");
    while(t != NULL) {
        printf("%d\n", t->data);
        t = t->next;
    }
}

int main() {
    int choice, value;
    while(1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if(value != -1)
                    printf("Popped element: %d\n", value);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice, try again!\n");
        }
    }
}


output:
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter value to push: 10
Element pushed into stack

Enter your choice: 1
Enter value to push: 20
Element pushed into stack

Enter your choice: 1
Enter value to push: 30
Element pushed into stack

Enter your choice: 3
Stack elements are:
30
20
10

Enter your choice: 2
Popped element: 30

Enter your choice: 3
Stack elements are:
20
10

Enter your choice: 2
Popped element: 20

Enter your choice: 2
Popped element: 10

Enter your choice: 2
Stack Underflow

Enter your choice: 4
Exiting program...


Result:
I successfully implemented a stack using a linked list in C. 
The program can push elements onto the stack, pop elements from it, and display the current elements.
 It also handles underflow and overflow conditions correctly.
 This helped me understand dynamic memory allocation and how linked lists can be used to manage stacks efficiently.
