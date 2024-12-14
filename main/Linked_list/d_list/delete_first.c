#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link_next;
    struct node *link_prev;
};

void delete_first(struct node **head)
{
    struct node *p;

    if(!(*head))
        return ();
    p = *head;
    *head = p->link_next;
    if(p->link_next != NULL)
        p->link_next->link_prev = NULL;
    free(p);
}