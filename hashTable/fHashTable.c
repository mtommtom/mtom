#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cowList.h"

// The hash function will give you an int to where to look
// Should use use all and just that data
// No random numbers
// You shouldn't use your own hash functions

node *hashTable[26];

int hash(char *s);
void hashAdd(char *name);
void init_table();

int main(void)
{

    init_table();

    hashAdd("Aeo");
    hashAdd("Aoeee");
    hashAdd("Aoooooooooo");
    hashAdd("Cyn");
    hashAdd("Ckeo");
    hashAdd("Zeodsdf");
    hashAdd("cat");
    hashAdd("Zzzes");
    hashAdd("caterpiller");

    for (int i = 0; i < 26; i++)
    {
        if (hashTable[i] == NULL) {
            printf("");
        } else {
            printList(hashTable[i]);
            while (hashTable[i] != NULL)
            {
                node *tmp = hashTable[i]->next;
                free(hashTable[i]);
                hashTable[i] = tmp;
            }
        }
    }
    printf("\n");

}

void init_table()
{
    for (int i = 0; i < 26; i++)
    {
        hashTable[i] = NULL;
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

int hash(char *s)
{
    if (s[0] >= 'A' && s[0] <= 'Z')
    {
        return (int) s[0] - 65;
    } else
    {
        return (int) s[0] - 97;
    }
}