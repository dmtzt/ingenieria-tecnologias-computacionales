//
//  Recipe.c
//  Proyecto Recetas
//
//  Created by Jair Antonio on 10/03/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HashTable.h"

void create_hash(HashTable *hash, size_t capacity) {
	hash->capacity = capacity;
	hash->size = 0;
	hash->data = (H_Reg*) calloc(capacity, sizeof(H_Reg));
}

void delete_hash(HashTable *hash) {
	for (int i = 0; i < hash->capacity && hash->size > 0; i++) {
		if (hash->data[i].key != NULL) {
			free(hash->data[i].key);
			hash->size--;
		}
	}

	free(hash->data);
	free(hash);
}

int hash_function(char *str, size_t capacity) {
	int result = 0;

	for (int i = 0; str[i] != '\0'; i++)
		result += (i + 1) * ((int) str[i]);

	return result % capacity;
}

int increment(int index, size_t capacity) {
	return (index + 1) % capacity;
}

void insert_hash(HashTable *hash, char *key, int value) {
	if (hash->size == hash->capacity) {
		printf("Error: HashTable is full\n");
		return;
	}

	int index = hash_function(key, hash->capacity);

	while (hash->data[index].key != NULL)
		index = increment(index, hash->capacity);

	hash->data[index].key = strdup(key);
	hash->data[index].value = value;
	hash->size++;
}

int get_index(HashTable *hash, char *key, int index) {
	if (hash->data[index].key == NULL)
		return -1;

	if (strcmp(hash->data[index].key, key) == 0)
		return index;

	size_t remain = hash->capacity;

	while (remain > 0 && strcmp(hash->data[index].key, key) != 0) {
		index = increment(index, hash->capacity);
		remain = hash->data[index].key == NULL ? 0 : remain - 1;
	}

	return remain == 0 ? -1 : index;
}

int find_hash(HashTable *hash, char *key) {
	int index = get_index(hash, key, hash_function(key, hash->capacity));
	return index == -1 ? -1 : hash->data[index].value;
}

void erase_hash(HashTable *hash, char *key) {
	int index = get_index(hash, key, hash_function(key, hash->capacity));

	if (index != -1) {
		free(hash->data[index].key);
		hash->data[index].key = NULL;
		hash->size--;
	}
}

