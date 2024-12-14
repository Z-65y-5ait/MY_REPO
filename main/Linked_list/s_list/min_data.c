#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link;
};

int    min_data(struct node *head)
{
    struct node *p;
    struct node *min;

    if(!head)
        return ();
    p = head->link;
    min = head->data;
    while(p->link != NULL)
    {
        if(min > p->data)
            min = p->data;
        p = p->link;
    }
    return (min);
}