// Implements a dictionary's functionality

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char *word;
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[26];

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    if (word[0] >= 'A' && word[0] <= 'Z') // Some general function to get the the hash
    {
        return (int) word[0] - 65;
    } else
    {
        return (int) word[0] - 97;
    }
}


// Returns true if word is in dictionary else false
bool check(const char *word)    //MAKE CHECK TO UPPER OR TO LOWER
{
    // Look throught the dictionaries and if the word (using random access) is in there retrun true else return false
    // TODO
    int y = hash(word);
    node *n = table[y];
    while (n != NULL)
    {
        if (strcasecmp(n->word, word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}


node *add(node *head, char* value)
{
    node *n = malloc(sizeof(node));
    n->word = value;
    n->next = NULL;

    return n;
}

void hashAdd(char *name)
{
    node *list = table[hash(name)];
    list = table[hash(name)];
    node *tmp;
    tmp = add(list, name);
    tmp->next = list;
    list = tmp;
    table[hash(name)] = list;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)   // The load function is not working properly. The hash table state is never saved
{
    // TODO
    for (int i = 0; i < 26; i++)    // Init table
    {
        table[i] = NULL;
    }
    // Open file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    // read strings line by line (store in hash table)
    char *word = malloc(LENGTH);
    while (!feof(file))
    {
        // Create new node for each word
        fscanf(file, "%s", word);

        char *tmp = malloc(45);

        // the varible word has to be a coppy because it just will overide
        strcpy(tmp, word);

        hashAdd(tmp);

        // hash the word
        // node *list = table[y];
        // node *tmp;

        // // add it to the correct linked list
        // tmp = add(list, word);
        // tmp->next = list;
        // table[y] = tmp;
    }
    free(word);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int con = 0;
    for (int i = 0; i < sizeof(table); i++)
    {
        if (table[i] != NULL)
        {
            for (node *tmp = table[i]; tmp != NULL; tmp = tmp->next)
            {
                con++;
            }
        }
    }
    // TODO
    return con - 1;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < 26; i++)
    {
        if (table[i] != NULL)
        {
            while (table[i] != NULL)
            {
                node *tmp = table[i]->next;
                free(tmp);
                table[i] = tmp;
            }
        }

    }
    return true;
}
