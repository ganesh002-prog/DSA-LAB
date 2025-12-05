Aim:
To make a C program that can do basic operations on a singly linked list like adding elements at the beginning, 
at the end, at any position, and showing the list.

Program:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void addAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void addAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return;
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void addAtPosition(struct Node** head, int value, int pos) {
    if (pos <= 0) return;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) return;
    newNode->data = value;
    newNode->next = NULL;

    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void showList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Add at Beginning\n");
        printf("2. Add at End\n");
        printf("3. Add at Position\n");
        printf("4. Show List\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                addAtBeginning(&head, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                addAtEnd(&head, value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                addAtPosition(&head, value, position);
                break;

            case 4:
                showList(head);
                break;

            case 5:
                freeList(&head);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

OUTPUT:
--- Linked List Menu ---
1. Add at Beginning
2. Add at End
3. Add at Position
4. Show List
5. Exit
Enter choice: 1
Enter value: 10

Enter choice: 2
Enter value: 20

Enter choice: 3
Enter value: 15
Enter position: 2

Enter choice: 4
List: 10 -> 15 -> 20 -> NULL

result: The program successfully performs all basic singly linked list operations,
 including insertion at beginning, insertion at end, insertion at specific position, and displaying the list.

