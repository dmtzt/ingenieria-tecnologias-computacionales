//
//  Recipe.h
//  Proyecto Recetas
//
//  Created by Jair Antonio on 10/03/21.
//

#ifndef Recipe_h
#define Recipe_h

#define NUM_INGREDIENTS 0xFF

#include "HashTable.h"

typedef struct Recipe {
	char *name;
	size_t count;
	char **ingredients;
	int *percent;
	HashTable *indexes;
} Recipe;

void create_recipe(Recipe *recipe, char *name);

void delete_recipe(Recipe *recipe);

void insert_ingredient(Recipe *recipe, char *ingredient, int percent);

int find_percent(Recipe *recipe, char *ingredient);

#endif /* Recipe_h */
