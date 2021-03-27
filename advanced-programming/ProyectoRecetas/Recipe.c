//
//  Recipe.c
//  Proyecto Recetas
//
//  Created by Jair Antonio on 10/03/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Recipe.h"

void create_recipe(Recipe *recipe, char *name) {
	recipe->name = strdup(name);
	recipe->count = 0;
	recipe->ingredients = (char**) calloc(NUM_INGREDIENTS, sizeof(char*));
	recipe->percent = (int*) calloc(NUM_INGREDIENTS, sizeof(int));
	recipe->indexes = (HashTable*) malloc(sizeof(HashTable));
	create_hash(recipe->indexes, NUM_INGREDIENTS);
}

void delete_recipe(Recipe *recipe) {
	free(recipe->name);
	free(recipe->ingredients);
	free(recipe->percent);
	delete_hash(recipe->indexes);
	free(recipe);
}

void insert_ingredient(Recipe *recipe, char *ingredient, int percent) {
	if (recipe->count == NUM_INGREDIENTS) {
		printf("Error: recipe is full\n");
		return;
	}

	recipe->ingredients[recipe->count] = strdup(ingredient);
	recipe->percent[recipe->count] = percent;
	insert_hash(recipe->indexes, ingredient, (int) recipe->count);
	recipe->count++;
}

int find_percent(Recipe *recipe, char *ingredient) {
	int index = find_hash(recipe->indexes, ingredient);
	return index == -1 ? -1 : recipe->percent[index];
}

