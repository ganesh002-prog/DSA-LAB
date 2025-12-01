
AIM:
    To implement a Binary Search Tree (BST) and perform
    Level Order Traversal (Breadth-First Search) using a 
    manually implemented queue in C.
  
Program:
#include <stdio.h>
#include <stdlib.h>

struct Node **queue;
int front = -1, rear = -1, MAX;

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void enqueue(struct Node *temp) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = temp;
}

struct Node* dequeue() {
    if (front == -1 || front > rear)
        return NULL;
    return queue[front++];
}

void levelOrder(struct Node *root) {
    if (root == NULL)
        return;

    enqueue(root);

    while (front <= rear) {
        struct Node *current = dequeue();
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(current->left);
        if (current->right != NULL)
            enqueue(current->right);
    }
}

int main() {
    int value;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &MAX);

    queue = (struct Node**)malloc(MAX * sizeof(struct Node*));

    printf("Enter %d values:\n", MAX);
    for (int i = 0; i < MAX; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nLevel Order Traversal: ");
    levelOrder(root);

    printf("\n\nPROGRAM COMPLETED SUCCESSFULLY.\n");

    return 0;
}



OUTPUT:
    - The program takes N elements as input.
    - Inserts them into a BST.
    - Prints the Level Order Traversal of the BST.

RESULT:
    Displays the BFS traversal of the constructed tree.
