AIM:
To implement a Circular Queue using a Linked List in C, providing operations to insert (enqueue), delete (dequeue), and display elements of the queue.

Program:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int item) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = item;

    if (front == NULL) {
        front = rear = newNode;
        newNode->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("%d added to the circular queue.\n", item);
}

void dequeue() {
    if (!front) {
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }

    struct Node *temp = front;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }

    printf("Removed element: %d\n", temp->data);
    free(temp);
}

void display() {
    if (!front) {
        printf("Circular Queue is empty.\n");
        return;
    }

    struct Node *temp = front;
    printf("Circular Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Operations Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

sample output:
--- Circular Queue Operations Menu ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter value to insert: 10
10 added to the circular queue.

--- Circular Queue Operations Menu ---
Enter your choice: 1
Enter value to insert: 20
20 added to the circular queue.

--- Circular Queue Operations Menu ---
Enter your choice: 1
Enter value to insert: 30
30 added to the circular queue.

--- Circular Queue Operations Menu ---
Enter your choice: 3
Circular Queue elements: 10 20 30 

--- Circular Queue Operations Menu ---
Enter your choice: 2
Removed element: 10

--- Circular Queue Operations Menu ---
Enter your choice: 3
Circular Queue elements: 20 30 

--- Circular Queue Operations Menu ---
Enter your choice: 4
Program terminated.



Result:
The Circular Queue using a Linked List was successfully implemented.
The program correctly handled enqueue, dequeue, and display operations while maintaining the circular nature of the queue.
