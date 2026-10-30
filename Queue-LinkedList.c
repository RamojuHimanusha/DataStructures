
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node *next;
};

// Initialize front and rear pointers
struct Node *front = NULL;
struct Node *rear = NULL;

// Check whether queue is empty
int isEmpty() {
    return front == NULL;
}

// Insert an element into the queue (Enqueue)
void enqueue(int val) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Queue Overflow (Memory allocation failed)\n");
        return;
    }

    newNode->data = val;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Inserted %d\n", val);
}

// Delete an element from the queue (Dequeue)
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node *temp = front;

    printf("Deleted %d\n", temp->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

// View the front element
void peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element: %d\n", front->data);
}

// Display all queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    struct Node *ptr = front;

    printf("Queue (Front -> Rear): ");

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
        printf("\n----- QUEUE OPERATIONS -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
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
