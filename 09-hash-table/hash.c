#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "hash.h"

#define HCONST 3567892

HashTable *NewTable(int size)
{
	// creates a new hash table (allocates the structure itself and the array of pointers)
	HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
	if (newTable == NULL) return 0;
	newTable->table =(HashElement**)malloc(size * sizeof(HashElement));
	if (newTable->table == NULL) return 0;
	
	newTable->size = size;
	newTable->load = 0;

	for (int i = 0; i <= size; i++) 
		newTable->table[i] = NULL;

	return newTable;
}

unsigned int hash(char *word)
{
	// generates a hash code from the key
	unsigned int key = 0;
	while(*word != '\0')
	{
		key = key*HCONST + *word;
		word++;
	}
	return key;
}

HashElement* createElement(char* word) {
	HashElement* newSlot = (HashElement*)malloc(sizeof(HashElement));
	if (newSlot == NULL) return 0;

	newSlot->word = _strdup(word);
	newSlot->next = NULL;

	return newSlot;
}

void Insert(HashTable *ht, char *word)
{
	// adds a new word to the list in the matching bucket
	int key = hash(word) % ht->size;
	
	if (ht->table[key] == NULL)
		ht->table[key] = createElement(word);
	else {
		HashElement* lastWord = ht->table[key];

		while (lastWord->next) 
			lastWord = lastWord->next;
		lastWord->next = createElement(word);
	}
	(ht->load)++;
}

int Get(HashTable *ht, char *word)
{
	// returns 0 or 1 depending on whether the word exists in the table
	int key = hash(word) % ht->size;

	return (ht->table[key] == NULL) ? 0 : 1;
}

void deleteElement(HashElement* element) {
	if (element == NULL) return;

	deleteElement(element->next);
	free(element->word);
	free(element);
	return;
}

void DeleteTable(HashTable *ht)
{
	// deletes the whole hash table (the lists in all buckets (word and list element), the buckets ...)

	//RECURSIVE
	/*if (ht->size == 0) return;

	deleteElement(ht->table[ht->size]);
	(ht->size)--;
	DeleteTable(ht);*/

	for (int i = 0; i < ht->size; i++) {
		if (ht->table[i] == NULL)
			continue;
		else {
			HashElement* curr = ht->table[i];
			while (curr) {
				HashElement* delete = curr;
				curr = curr->next;
				free(delete->word);
				free(delete);
			}
		}
	}
}