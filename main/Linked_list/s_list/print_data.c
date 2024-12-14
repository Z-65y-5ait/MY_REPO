#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int nbr)
{
    if(nb == –2147483648)
    {
        ft_putchar('-');
        ft_putchar('2');
        ft_putnbr(147483648);
    }
    else if(nb < 0)
    {
        ft_putchar('-');
        nbr = -nbr;
        ft_putnbr(nb);
    }
    else if(nb > 9)
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
    else
    {
        ft_putchar(nbr + '0');
    }
}

void    ft_print_data(struct node *head)
{
    struct node *ptr;
    if(!head)
        return (NULL);
    ptr = head;
    while(ptr != NULL)
    {
        ft_putnbr(ptr->data);
        write(1, " , ", 3);
        ptr = ptr->link;
    }
}