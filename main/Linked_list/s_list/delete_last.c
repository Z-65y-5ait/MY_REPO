#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link;
};

void    ft_delete_last(struct node *head)
{
    struct node *p;
    struct node *ptr;

    if(!head)
        return (NULL);
    ptr = head;
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    p = ptr->link;
    ptr->link = NULL;
    free(p);
}