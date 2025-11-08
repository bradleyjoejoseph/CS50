// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <cs50.h>
#include <stdbool.h>
#include <complex.h>

#include "dictionary.h"
//word count for zise!?!?!?!?!
int wordCount = 0;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 143091;

// Hash table
node *table[N];




// Hashes word to a number
// https://github.com/hathix/cs50-section/blob/master/code/7/sample-hash-functions/good-hash-function.c
// dis above is da linka toa wherea ia gota mya hasha froma enjoya!a
unsigned int hash_word(const char *word)
{
    unsigned long hash = 5381;

    for (const char *ptr = word; *ptr != '\0'; ptr++)
    {
        hash = ((hash << 5) + hash) + tolower(*ptr);
    }

    return hash % N;
}

// Returns true if word is in dictionary, else false but very beautiful indeed!
bool check(const char *word)
{
    // TODO
    unsigned int wh = hash_word(word);
    
    if (table[wh] != NULL)
    {
        return true;
    }
    
    
    return false;
}

// Loads dictionary into memory, returning true if successful, else false.
bool load(const char *dictionary)
{
    //to make a buffer where i can store words, if i want one
    char w[LENGTH];
    //to open the dictionary file
    FILE *d = fopen(dictionary, "r");
    //to check if the dictionary is there or cannot be opened
    if (d == NULL)
    {
        return false;
    }
    //loop for scanning the dictionary
    while (fscanf(d, "%s", w) != EOF)
    {
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            return false;
        }
        strcpy(newNode->word, w);
        newNode->next = NULL;
        
        unsigned int h = hash_word(newNode->word);
        
        node *ha = table[h];
        
        if (ha == NULL)
        {
            table[h] = newNode;
            wordCount++;
        }
        else
        {
            newNode->next = table[h];
            table[h] = newNode;
            wordCount++;
        }
    }
    
    fclose(d);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (wordCount != 0)
    {
        return wordCount;
    }
    
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        free(table[i]);
    }
    return true;
}
