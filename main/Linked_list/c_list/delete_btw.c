#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link;
};

void delete_btw(struct node *buttom, int found)
{
    struct node *p;
    struct node *ptr;

    if(!buttom)
        return();
    p = buttom->link;
    while(p != buttom->link && p->link->data != found)
    p = p->link;
    if(p->link->data == found)
    {
        ptr = p->link;
        p->link = ptr->link;
        if(p == ptr)
            buttom = NULL;
        else if(ptr == buttom)
            buttom = p;
        free(ptr);
    }
}