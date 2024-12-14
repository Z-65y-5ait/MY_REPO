#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void    ft_add_at_end(struct node *head, int data)
{
    if(!head)
        return (NULL);
    struct node *str;
    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    str = head;
    while(str->link != NULL)
    {
        str = str->link;
    }
    str->link = temp;
}