
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node *next;
};

// Initialize top pointer
struct Node *top = NULL;

// Check whether stack is empty
int isEmpty() {
    return top == NULL;
}

// Push an element onto the stack
void push(int val) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow (Memory allocation failed)\n");
        return;
    }

    newNode->data = val;
    newNode->next = top;
    top = newNode;

    printf("Pushed %d\n", val);
}

// Pop an element from the stack
void pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node *temp = top;

    printf("Popped %d\n", temp->data);

    top = top->next;
    free(temp);
}

// View the top element
void peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

// Display all stack elements
void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }

    struct Node *ptr = top;

    printf("Stack (Top -> Bottom): ");

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

// Main function
int main() {
    int choice, val;

    while (1) {
        printf("\n----- STACK OPERATIONS -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
