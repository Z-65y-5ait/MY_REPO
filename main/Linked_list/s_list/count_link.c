#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int ft_count_link(struct node *head)
{
    int count;
    struct node *str;

    count = 0;
    str = head;
    if(!head)
        return (0);
    while(str != NULL)
    {
        count++;
        str = str->link;
    }
    return (count);
}