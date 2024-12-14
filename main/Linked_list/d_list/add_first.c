#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link_next;
    struct node *link_prev;
};

void add_first(struct node **head, int key)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node *));
    ptr->link_next = NULL;
    ptr->link_prev = NULL;
    ptr->data = key;
    ptr->link_next = (*head);
    if (*head != NULL)
        (*head)->link_prev = ptr;
    *head = ptr;
}