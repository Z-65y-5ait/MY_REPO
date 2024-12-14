#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head;
    struct node *current;

    head = (struct node *)malloc(sizeof(struct node));
    head->data = 23;
    head->link = NULL;

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 82;
    current->link = NULL;

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 55;
    current->link = NULL;

    head->link->link = current;
}