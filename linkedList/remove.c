#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

node *add(node *head, int value);
node *addF(node *head, int value);
node *getNode(node *head, int pos);
node *findNode(node *head, int value);

int main(void)
{
    node *list = NULL;
    node *tmp;

    for (int i = 0; i < 25; i++)
    {
        tmp = addF(list, i);
        tmp->next = list;
        list = tmp;
    }

    tmp = findNode(list, 8);
    printf("%i found from looking at value 8\n", tmp->number);

    tmp = getNode(list, 7);
    printf("%i found from postion 7\n", tmp->number);

    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i - ", tmp->number);
    }

    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
    printf("\n");
}

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