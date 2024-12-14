#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link;
};

void add_first(struct node *buttom, int key)
{
    struct node *ptr;

    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->link = NULL;
    ptr->data = key;
    if(!buttom)
    {
        buttom = ptr;
        return ();
    }
    buttom->link = ptr;
    ptr->link = buttom->link;
    buttom = ptr;
}