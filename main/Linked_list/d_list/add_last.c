#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link_next;
    struct node *link_prev;
};

void add_last(struct node **head, int key)
{
    struct node *ptr;
    struct node *p;
    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->link_next = NULL;
    ptr->link_prev = NULL;
    ptr->data = key;
    if (*head == NULL)
    {
        *head = ptr;
        return ();
    }
    p = *head;
    while(p->link_next != NULL)
        p = p->link_next;
    p->link_next = ptr;
    ptr->link_prev = p;
}