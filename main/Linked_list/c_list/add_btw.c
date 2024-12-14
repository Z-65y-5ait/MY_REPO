#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link;
};

void add_btw(struct node *buttom, int found, int key)
{
    struct node *ptr;
    struct node *p;

    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->link = NULL;
    ptr->data = key;
    if(!buttom)
    {
        buttom = ptr;
        return ();
    }
    p = buttom->link;
    while(!p && ptr->data != found)
        p = p->link;
    if(ptr->data == found)
    {
        ptr->link = p->link;
        p->link = ptr;
        if(p == buttom)
            buttom = ptr;
    }
}