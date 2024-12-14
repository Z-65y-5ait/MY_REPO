#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link;
};

bool    search_list(struct node *head, int score)
{
    struct node *p;

    if(!head)
        return (false);
    p = head;
    if(p->data == score)
        return (true);
    return(search_list(p->link,score));
}