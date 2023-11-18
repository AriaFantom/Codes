#include <stdio.h>
#include <stdlib.h>

/**
 * @brief A struct representing a node in a linked list.
 * 
 */
typedef struct linked_list
{
    int data; /**< The data stored in the node. */
    struct linked_list *next; /**< A pointer to the next node in the linked list. */
} node;


/**
 * This file contains function declarations for performing various operations on a linked list.
 * The operations include inserting a node at the beginning, end, or after a given node, deleting a node from the beginning, end, or any position, and traversing and displaying the linked list.
 * The linked list is implemented using a struct node, which contains a data field and a pointer to the next node.
 * 
 */
node *insert_beg(node *);
node *insert_end(node *);
node *insert_after(node *);

node *del_beg(node *);
node *del_end(node *);
node *del_any(node *);

void traverse(node *);
void display(node *);

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

node *insert_beg(node *h)
{
    node *p;
    int x;

    printf("\nEnter data: ");
    scanf("%d", &x);

    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = h;
    h = p;

    return h;
}


node *insert_end(node *h)
{
    node *p, *q;
    int x;

    printf("\nEnter data: ");
    scanf("%d", &x);

    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;

    if (h == NULL)
        h = p;
    else
    {
        q = h;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }

    return h;
}

node *insert_after(node *h)
{
    node *p, *q;
    int x, val;

    printf("\nEnter data: ");
    scanf("%d", &x);

    printf("\nEnter value after which data is to be inserted: ");
    scanf("%d", &val);

    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;

    q = h;
    while (q != NULL)
    {
        if (q->data == val)
        {
            p->next = q->next;
            q->next = p;
            return h;
        }
        q = q->next;
    }

    printf("\nValue not found!");
    return h;
}

node *del_beg(node *h)
{
    node *p;

    if (h == NULL)
    {
        printf("\nList is empty!");
        return h;
    }

    p = h;
    h = h->next;
    free(p);

    return h;
}

node *del_end(node *h)
{
    node *p, *q;

    if (h == NULL)
    {
        printf("\nList is empty!");
        return h;
    }

    if (h->next == NULL)
    {
        free(h);
        h = NULL;
        return h;
    }

    p = h;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    free(p);

    return h;
}

node *del_any(node *h)
{
    node *p, *q;
    int val;

    if (h == NULL)
    {
        printf("\nList is empty!");
        return h;
    }

    printf("\nEnter value to be deleted: ");
    scanf("%d", &val);

    if (h->data == val)
    {
        p = h;
        h = h->next;
        free(p);
        return h;
    }

    p = h;
    while (p != NULL)
    {
        if (p->data == val)
        {
            q->next = p->next;
            free(p);
            return h;
        }
        q = p;
        p = p->next;
    }

    printf("\nValue not found!");
    return h;
}

/**
 * Traverses the linked list starting from the given head node and prints its elements.
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


