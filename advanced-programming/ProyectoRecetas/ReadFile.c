//
//  ReadFile.c
//  Proyecto Recetas
//
//  Created by Jair Antonio on 10/03/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Recipe.h"
#include "ReadFile.h"

#define bool int
#define true 1
#define false 0

bool is_emptyline(char* line) {
	for (int i = 0; line[i] != '\0'; i++) {
		if (!isspace(line[i]))
			return false;
	}

	return true;
}

char* get_after_colons(char *buffer) {
	return strstr(buffer, ":") + 1;
}

void read_file(FILE *file, Recipe *recipes, size_t *size, HashTable *ingredients) {
	if (file == NULL) return;

	size_t buff_size = 50;
	char* buffer = (char*) calloc(buff_size, sizeof(char));

	bool read_ingredients = false;
	int ingredient_id = 0;

	while (!feof(file)) {
		getline(&buffer, &buff_size, file);

		if (is_emptyline(buffer)) {
			read_ingredients = false;
			(*size)++;

		} else if (read_ingredients) {
			int i = 0;

			while (buffer[i] != ':') i++;

			buffer[i] = '\0';

			insert_ingredient(&recipes[*size], buffer, atoi(buffer + i + 1));

			if (find_hash(ingredients, buffer) == -1) {
				insert_hash(ingredients, buffer, ingredient_id);
				ingredient_id++;
			}

		} else if (strstr(buffer, "Recipe") != NULL) {
			create_recipe(&recipes[*size], get_after_colons(buffer));

		} else if (strstr(buffer, "Ingredients")) {
			read_ingredients = true;
		}
	}

	free(buffer);
}

