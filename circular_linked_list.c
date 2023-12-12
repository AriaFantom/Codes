#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning of a circular linked list
void insertAtBeginning(struct Node** head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    // If the list is empty, make the new node as the head and point its next to itself
    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
    }
    else {
        // Find the last node
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }

        // Insert the new node at the beginning
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
    }
}

// Function to delete a node from a circular linked list
void deleteNode(struct Node** head, int key) {
    // If the list is empty, return
    if (*head == NULL) {
        return;
    }

    // Find the node to be deleted
    struct Node* curr = *head;
    struct Node* prev = NULL;
    while (curr->data != key) {
        // If the node is not found and we have traversed the entire list, return
        if (curr->next == *head) {
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    // If the node to be deleted is the head node
    if (curr == *head && curr->next == *head) {
        *head = NULL;
        free(curr);
        return;
    }

    // If the node to be deleted is the head node but there are other nodes in the list
    if (curr == *head) {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        *head = curr->next;
        last->next = *head;
        free(curr);
    }
    else {
        // If the node to be deleted is not the head node
        prev->next = curr->next;
        free(curr);
    }
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    // Display the circular linked list
    printf("Circular linked list: ");
    display(head);

    // Delete a node from the circular linked list
    deleteNode(&head, 2);

    // Display the updated circular linked list
    printf("Updated circular linked list: ");
    display(head);

    return 0;
}
