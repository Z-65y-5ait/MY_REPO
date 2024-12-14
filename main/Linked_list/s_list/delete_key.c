#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link;
};

void    ft_delete_last(struct node *head, int key)
{
    struct node *p;
    struct node *ptr;

    if(!head)
        return (NULL);
    if(p != NULL && p->data == key)
    {
        head = p->link;
        free(p);
        return ();
    }
    while(p != NULL && p->data == key)
    {
        ptr = p;
        p = p->link;
    }
    if(p == NULL)
        return ();
    ptr->link = p->link;
    free(p);
}