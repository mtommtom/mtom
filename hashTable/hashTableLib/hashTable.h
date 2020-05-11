#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include <stdlib.h>
#include <stdio.h>
#include "cowList.h"
#include <stdbool.h>
#include <string.h>

node *hashTable[26];

int hash(char *s)
{
    if (s[0] >= 'A' && s[0] <= 'Z') // Some general function to get the the hash
    {
        return (int) s[0] - 65;
    } else
    {
        return (int) s[0] - 97;
    }
}

void hashAdd(char *name)
{
    node *list = hashTable[hash(name)];
    node *tmp;
    tmp = addF(list, name);
    tmp->next = list;
    list = tmp;
    hashTable[hash(name)] = list;
}

void initTable()
{
    for (int i = 0; i < 26; i++)
    {
        hashTable[i] = NULL;
    }
}

void printTable()
{
    for (int i = 0; i < 26; i++)
    {
        if (hashTable[i] == NULL)
        {
            printf("\t%i)________\n", i);
        } else
        {
            printf("\t%i)__", i);
            for (node *tmp = hashTable[i]; tmp != NULL; tmp = tmp->next)
            {
                printf("%s - ", hashTable[i]->name);
            }
            printf("\n");
        }
        
    }
}

void freeList()
{
    for (int i = 0; i < 26; i++)
    {
        if (hashTable[i] != NULL)
        {
            while (hashTable[i] != NULL)
            {
                node *tmp = hashTable[i]->next;
                free(hashTable[i]);
                hashTable[i] = tmp;
            }              
        }
      
    }

}

bool hashFind(char *name)
{
    int y = hash(name);
    node *n = hashTable[y];
    while (n != NULL)
    {
        if (strcmp(n->name, name) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

#endif