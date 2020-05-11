#ifndef __COWLIST_H__
#define __COWLIST_H__

#include <stdio.h>
#include <string.h>

typedef struct node
{
    char* name;
    struct node *next;
}
node;

node *addF(node *head, char* value)
{
    node *n = malloc(sizeof(node));
    n->name = value;
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

node *findNode(node *head, char* value)
{
    node *n = head;
    while (n != NULL)
    {
        if (strcmp(n->name, value))
        {
            return n;
        }
        n = n->next;
    }
    return NULL;
}

node* add(node *head, char* value)
{
    node *n = malloc(sizeof(node));
    n->name = value;
    n->next = head->next;

    return n;
}

void *printList(node *head)
{
    for (node *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        printf("%s - ", tmp->name);
    }
}
#endif