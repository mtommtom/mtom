#include <stdio.h>
#include <stdlib.h>
#include "cowList.h"

node *addF(node *head, int value)
{
    node *n = malloc(sizeof(node));
    n->number = value;
    n->next = NULL;

    return n;
}

node *getNode(node *head, int pos)
{
    node *n = head;
    for (int i = 0; i < pos; i++)
    {
        n = n->next;
    }
    return n;
}

node *findNode(node *head, int value)
{
    node *n = head;
    while (n != NULL)
    {
        if (n->number == value)
        {
            return n;
        }
        n = n->next;
    }
    return NULL;
}

node* add(node *head, int value)
{
    node *n = malloc(sizeof(node));
    n->number = value;
    n->next = head->next;

    return n;
}

void *printList(node *head)
{
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%i - ", tmp->number);
    }
}