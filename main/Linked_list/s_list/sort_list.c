#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link;
};

void    sort_list(struct node **head)
{
    struct node *p;
    struct node *ptr;
    struct node *temp;

    if(!head)
        return ();
    p = head;
    ptr = p->link;
    while(p->link != NULL)
    {
        while(ptr != NULL)
        {
            if(p->data > ptr->data)
            {
                temp = ptr->data;
                ptr->data = p->data;
                p->data = temp;
            }
            ptr = ptr->link;
        }
        p = p->link;
    }
}