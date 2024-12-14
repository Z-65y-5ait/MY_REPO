#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link_next;
    struct node *link_prev;
};

void add_btw(struct node **head, int key, int found)
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
    while(p->link_next != NULL && p->data != found)
        p = p->link_next;
    if (p->data == found)
    {
        ptr->link_prev = p;
        p->link_next = ptr;
        if (p->link_next != NULL || p->link_prev != NULL)
        {
            p->link_next->link_prev = ptr;
        }
        ptr->link_next = p->link_next;
        if (p-link_prev == NULL)
        {
            *head = ptr;
        }
    }
}