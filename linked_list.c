#include <stdio.h>
#include <stdlib.h>

/**
 * @brief A struct representing a node in a linked list.
 *
 */
typedef struct linked_list
{
    int data;                 /**< The data stored in the node. */
    struct linked_list *next; /**< A pointer to the next node in the linked list. */
} node;

node *insert_beg(node *h);
node *insert_end(node *h);
node *insert_after(node *h);
node *del_beg(node *h);
node *del_end(node *h);
node *del_any(node *h);
void traverse(node *h);
void display(node *h);

int main()
{
    int c;
    node *h = NULL;

    while (1)
    {
        printf("\n\n1. Insert at beginning\n2. Insert at end\n3. Insert after a node\n4. Delete from beginning\n5. Delete from end\n6. Delete any node\n7. Traverse\n8. Display\n9. Exit\n\nEnter your choice: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            h = insert_beg(h);
            break;
        case 2:
            h = insert_end(h);
            break;
        case 3:
            h = insert_after(h);
            break;
        case 4:
            h = del_beg(h);
            break;
        case 5:
            h = del_end(h);
            break;
        case 6:
            h = del_any(h);
            break;
        case 7:
            traverse(h);
            break;
        case 8:
            display(h);
            break;
        case 9:
            exit(0);
        default:
            printf("\nInvalid choice!");
        }
    }

    return 0;
}

/**
 * This function inserts a node at the beginning of the linked list.
 *
 * @param h The head node of the linked list.
 * @return The updated head node after insertion.
 */
node *insert_beg(node *h)
{
    // Declare a pointer variable 'p' of type 'node'
    node *p;

    // Declare an integer variable 'x'
    int x;

    // Prompt the user to enter data
    printf("\nEnter data: ");

    // Read an integer input from the user and store it in 'x'
    scanf("%d", &x);

    // Allocate memory for a new node and assign the address to 'p'
    p = (node *)malloc(sizeof(node));

    // Set the 'data' field of the new node to the value of 'x'
    p->data = x;

    // Set the 'next' field of the new node to the current head node 'h'
    p->next = h;

    // Update the head node 'h' to point to the new node 'p'
    h = p;

    // Return the updated head node 'h'
    return h;
}

/**
 * This function inserts a node at the end of the linked list.
 *
 * @param h The head node of the linked list.
 * @return The updated head node after insertion.
 */
node *insert_end(node *h)
{
    // Declare two pointers of type 'node'
    node *p, *q;

    // Declare an integer variable 'x'
    int x;

    // Prompt the user to enter data
    printf("\nEnter data: ");

    // Read an integer value from the user and store it in 'x'
    scanf("%d", &x);

    // Allocate memory for a new node and assign its address to 'p'
    p = (node *)malloc(sizeof(node));

    // Set the 'data' field of the newly created node to the value of 'x'
    p->data = x;

    // Set the 'next' field of the newly created node to NULL
    p->next = NULL;

    /**
     * This condition checks if the head of the linked list is NULL.
     * If it is NULL, it assigns the value of 'p' to 'h', making 'p' the new head of the linked list.
     * This is used to handle the case when the linked list is empty and we need to add the first node.
     */
    if (h == NULL)
        h = p;

    else
    {
        // Assigns the value of 'h' to 'q'.
        q = h;

        // Traverse the linked list until the last node is reached
        while (q->next != NULL)
        {
            // Move to the next node
            q = q->next;

            // Set the next pointer of the current node to point to the new node 'p'
            q->next = p;
        }
    }

    return h;
}

/**
 * This function inserts a node after a given node in the linked list.
 *
 * @param h The head node of the linked list.
 * @return The updated head node after insertion.
 */
node *insert_after(node *h)
{
    // Declare two pointers of type 'node'
    node *p, *q;

    // Declare two variables 'x' and 'val' to store user input
    int x, val;

    // Prompt the user to enter data and store it in 'x'
    printf("\nEnter data: ");
    scanf("%d", &x);

    // Prompt the user to enter a value after which the data will be inserted and store it in 'val'
    printf("\nEnter value after which data is to be inserted: ");
    scanf("%d", &val);

    // Allocate memory for a new node and assign its address to 'p'
    p = (node *)malloc(sizeof(node));

    // Set the 'data' field of the new node to the value stored in 'x'
    p->data = x;

    // Set the 'next' field of the new node to NULL
    p->next = NULL;

    // Assign the address of the head node to 'q'
    q = h;
    // Traversing the linked list to find the node with the given value
    while (q != NULL)
    {
        // Checking if the current node's data matches the given value
        if (q->data == val)
        {
            // Reordering the nodes to insert the current node after the previous node
            p->next = q->next;
            q->next = p;

            // Returning the updated head of the linked list
            return h;
        }

        // Moving to the next node in the linked list
        q = q->next;
    }

    // If the value is not found in the linked list, printing a message
    printf("\nValue not found!");

    // Returning the original head of the linked list
    return h;
}

/**
 * This function deletes the first node from the linked list.
 *
 * @param h The head node of the linked list.
 * @return The updated head node after deletion.
 */
node *del_beg(node *h)
{
    // Declare a pointer variable 'p' of type 'node'
    node *p;

    // Check if the linked list is empty
    if (h == NULL)
    {
        // If the linked list is empty, print a message indicating that the list is empty
        printf("\nList is empty!");

        // Return the original head pointer 'h'
        return h;
    }

    /**
     * Moves the head pointer to the next node in the linked list.
     */
    p = h;       // Assigns the value of 'h' to 'p', making 'p' point to the same node as 'h'.
    h = h->next; // Updates the value of 'h' to point to the next node in the linked list.
    free(p);     // Free the memory allocated for the node pointed by p.

    // Return the original head pointer 'h'
    return h;
}

/**
 * This function deletes the last node from the linked list.
 *
 * @param h The head node of the linked list.
 * @return The updated head node after deletion.
 */
node *del_end(node *h)
{
    /**
     * Removes the last node from a linked list.
     * 
     * @param h The head of the linked list.
     * @return The updated head of the linked list after removing the last node.
     */
    node *p, *q;

    // Check if the linked list is empty
    if (h == NULL)
    {
        printf("\nList is empty!");
        return h;
    }

    // Check if there is only one node in the linked list
    if (h->next == NULL)
    {
        /**
         * Frees the memory allocated for the head node of a linked list
         * and sets the head pointer to NULL. beacuse there is not more node to connect
         */
        free(h);
        h = NULL;
        return h;

    }

    p = h;
    // Traverse to the last node of the linked list
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    // Set the next pointer of the current node to NULL.
    q->next = NULL;

    // Free the memory allocated for the current node.
    free(p);

    return h;
}

/**
 * This function deletes a specific node from the linked list.
 *
 * @param h The head node of the linked list.
 * @return The updated head node after deletion.
 */
node *del_any(node *h)
{

    node *p, *q; // Declare two pointers of type 'node' to traverse the linked list.
    int val; // Declare a variable to store the value to be deleted.

    if (h == NULL) // Check if the linked list is empty.
    {
        printf("\nList is empty!"); // Print a message indicating that the list is empty.
        return h; // Return the head of the linked list.
    }

    printf("\nEnter value to be deleted: "); // Prompt the user to enter the value to be deleted.
    scanf("%d", &val); // Read the value from the user.

    if (h->data == val) // Check if the head node contains the value to be deleted.
    {
        p = h; // Assign the head node to pointer 'p'.
        h = h->next; // Update the head to the next node.
        free(p); // Free the memory occupied by the head node.
        return h; // Return the updated head of the linked list.
    }

    p = h; // Assign the head node to pointer 'p'.
    while (p != NULL) // Traverse the linked list until the end is reached.
    {
        if (p->data == val) // Check if the current node contains the value to be deleted.
        {
            q->next = p->next; // Update the 'next' pointer of the previous node to skip the current node.
            free(p); // Free the memory occupied by the current node.
            return h; // Return the head of the linked list.
        }
        q = p; // Assign the current node to pointer 'q'.
        p = p->next; // Move to the next node.
    }

    printf("\nValue not found!"); // Print a message indicating that the value was not found in the linked list.
    return h; // Return the head of the linked list.


    // Declare two pointers of type 'node'
    node *p, *q;

    // Declare a variable 'val' to store the value to be deleted
    int val;

    // Check if the linked list is empty
    if (h == NULL)
    {
        printf("\nList is empty!");
        return h;
    }

    // Prompt the user to enter the value to be deleted
    printf("\nEnter value to be deleted: ");

    // Read the value entered by the user and store it in 'val'
    scanf("%d", &val);

    // Check if the data of the head node is equal to the given value
    if (h->data == val)
    {
        // If it is, assign the head node to a temporary variable 'p'
        p = h;
        // Move the head pointer to the next node
        h = h->next;
        // Free the memory occupied by the previous head node
        free(p);
        // Return the updated head node
        return h;
    }

    // If the data of the head node is not equal to the given value,
    // assign the head node to the temporary variable 'p'
    p = h;
    // Traverse the linked list until the end or until the desired value is found
    while (p != NULL)
    {
        // Check if the current node's data matches the desired value
        if (p->data == val)
        {
            // If a match is found, update the previous node's next pointer to skip the current node
            q->next = p->next;

            // Free the memory occupied by the current node
            free(p);

            // Return the head of the modified linked list
            return h;
        }

        // Move to the next node
        q = p;
        p = p->next;
    }

    // Print a message indicating that the value was not found in the linked list.
    printf("\nValue not found!");

    // Return the head of the linked list.
    return h;
}

/**
 * This function traverses the linked list starting from the given head node and prints its elements.
 * If the list is empty, it prints "List is empty!".
 *
 * @param h The head node of the linked list.
 */
void traverse(node *h)
{
    node *p;

    if (h == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    printf("\nList is: ");
    p = h;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

/**
 * This function displays the linked list.
 *
 * @param h The head node of the linked list.
 */
void display(node *h)
{
    node *p;

    if (h == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    printf("\nList is: ");
    p = h;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
