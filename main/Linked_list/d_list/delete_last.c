#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link_next;
    struct node *link_prev;
};

void delete_last(struct node **head)
{
    struct node *p;

    if(!(*head))
        return ();
    p = *head;
    while(p->link_next != NULL)
        p = p->link_next;
    p->link_prev->link_next = NULL;
    free(p);
}
