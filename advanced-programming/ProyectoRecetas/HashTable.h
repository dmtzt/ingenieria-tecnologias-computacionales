//
//  Recipe.h
//  Proyecto Recetas
//
//  Created by Jair Antonio on 9/03/21.
//

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

// Register, for hash table

typedef struct H_Reg {
	char *key;
	int value;
} H_Reg;

// Hash table

typedef struct HashTable {
	size_t capacity;
	size_t size;
	H_Reg *data;
} HashTable;

void create_hash(HashTable *hash, size_t capacity);

void delete_hash(HashTable *hash);

void insert_hash(HashTable *hash, char *key, int value);

void erase_hash(HashTable *hash, char *key);

int find_hash(HashTable *hash, char *key);

#endif /* Recipe_h */
