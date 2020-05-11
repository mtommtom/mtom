#include <stdio.h>
#include <stdlib.h>
#include "cowList.h"

int main(void)
{
    node *list = NULL;  // Setting it as malloc
    node *tmp;

    for (int i = 0; i < 25; i++)
    {
        tmp = addF(list, i);
        tmp->next = list;
        list = tmp;
    }

    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i - ", tmp->number);
    }
    printf("\n");

    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}