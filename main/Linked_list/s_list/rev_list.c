#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

struct node*    ft_rev_list(struct node *head)
{
    if(!head)
        return (NULL);
    struct node *temp;
    struct node *temp2;
    while(head != NULL)
    {
        temp2 = head->link;
        head->link = temp;
        temp = head;
        head = temp2;
    }
    head = temp;
    return (head);
}