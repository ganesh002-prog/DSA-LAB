Aim:
To write a C program to create a doubly linked list and perform all basic operations like inserting a node (at beginning, end, or any position),
 deleting a node (from beginning, end, by value, or at any position), searching for a value, and displaying the list in both forward and backward directions.

Program:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("%d inserted at beginning.\n", value);
}

void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        printf("%d inserted at end.\n", value);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    printf("%d inserted at end.\n", value);
}

void insertAtPosition(int value, int pos) {
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }
    struct Node* temp = head;
    int i = 1;
    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    printf("%d inserted at position %d.\n", value, pos);
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    printf("%d deleted from beginning.\n", temp->data);
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    printf("%d deleted from end.\n", temp->data);
    free(temp);
}

void deleteByValue(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL) {
        printf("%d not found in list.\n", value);
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    printf("%d deleted from list.\n", value);
    free(temp);
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    int i = 1;
    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    printf("Node at position %d deleted.\n", pos);
    free(temp);
}

void search(int value) {
    struct Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("%d found at position %d.\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d not found in list.\n", value);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Forward: ");
    while (temp->next != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int choice, value, position;
    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n2. Insert at Position\n3. Insert at End\n");
        printf("4. Delete at Beginning\n5. Delete by Value\n6. Delete at Position\n");
        printf("7. Delete at End\n8. Search\n9. Display\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                scanf("%d %d", &value, &position);
                insertAtPosition(value, position);
                break;
            case 3:
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                scanf("%d", &value);
                deleteByValue(value);
                break;
            case 6:
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                scanf("%d", &value);
                search(value);
                break;
            case 9:
                display();
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

Result:
The program efficiently performs all operations on a doubly linked list.
including inserting nodes, deleting nodes, searching for values, and displaying the list in both forward and backward directions.
 using a single consolidated program as outlined in the provided algorithms.

