#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"
#include <stdbool.h>

int main(void)
{
    initTable();
    int i = 0;

    hashAdd("Keo");
    hashAdd("kjeo");
    hashAdd("fdds");

    if (hashFind("Fdds"))
    {
        printf("true");
    } else
    {
        printf("false");
    }
    

    printTable();
    freeList();
}