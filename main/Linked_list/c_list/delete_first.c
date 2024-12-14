#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link;
};

void delete_first(struct node *buttom)
{
    struct node *p;

    if(!buttom)
        return ();
    p = buttom->link;
    if(p != buttom)
        buttom->link = p->link;
    else
        buttom->link = NULL;
    free(p);
}