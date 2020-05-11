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

int main(void)
{
    node *list = NULL;
    list = addF(list, 12);
    list->next = add(list, 19);
    list->next = add(list, 99);

    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }

    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}

node *add(node *head, int value)
{
    node *n = malloc(sizeof(node));
    n->number = value;
    n->next = head->next;

    return n;
}

node *addF(node *head, int value)
{
    node *n = malloc(sizeof(node));
    n->number = value;
    n->next = NULL;

    return n;
}
