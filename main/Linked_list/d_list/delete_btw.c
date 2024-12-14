#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link_next;
    struct node *link_prev;
};

void delete_btw(struct node **head, int found)
{
    struct node *p;

    if (*head == NULL)
        return ();
    p = *head;
    while(p->link_next != NULL && p->data != found)
        p = p->link_next;
    if (p->data == found)
    {
        if(p->link_prev != NULL)
            p->link_prev->link_next = p->link_next;
        else
            *head = p->link_next;
        if(p->link_next != NULL)
            p->link_next->link_prev = p->link_prev;
        free(p);
    }
}