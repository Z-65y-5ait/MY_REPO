#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link;
};

void    ft_delete_first(struct node *head)
{
    struct node *p;

    if(!head)
        return (NULL);
    p = head;
    head = head->link;
    free(p);
}