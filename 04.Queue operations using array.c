Aim
To write a simple C program that shows how a queue works using an array.
The program should be able to add elements (enqueue), remove elements (dequeue), and display the current elements in the queue.

PROGRAM:
#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item) 
{
    if (rear == MAX_SIZE - 1) 
    {
        printf("QUEUE OVERFLOW\n");
        return;
    }
    if (front == -1) 
    {
        front = 0;
    }
    rear++;
    queue[rear] = item;
    printf("%d has been added to the queue.\n", item);
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("QUEUE UNDERFLOW\n");
        return -1;
    }
    int item = queue[front];
    front++;
    printf("%d has been removed from the queue.\n", item);
    return item;
}

void display() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) 
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() 
{
    int choice, item;

    while (1) 
    {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program Ended.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}


--- QUEUE MENU ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter the value to insert: 10
10 has been added to the queue.

Enter your choice: 1
Enter the value to insert: 20
20 has been added to the queue.

Enter your choice: 3
Queue elements: 10 20

Enter your choice: 2
10 has been removed from the queue.

Enter your choice: 3
Queue elements: 20

Enter your choice: 4
Program Ended.

Result:
The program correctly demonstrates how a queue works using an array.
It allows the user to add, remove, and view elements from the queue, proving that the basic queue operations are functioning properly
