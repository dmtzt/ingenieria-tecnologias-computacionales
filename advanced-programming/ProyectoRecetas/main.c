#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "HashTable.h"
#include "Recipe.h"
#include "ReadFile.h"

int main(void) {
	/* Ejemplo de uso de HashTable
	 HashTable *table = (HashTable*) malloc(sizeof(HashTable));
	 create_hash(table, 0xFF);

	 insert_hash(table, "Hello,", 10);
	 insert_hash(table, "World!", 12);
	 insert_hash(table, "I'm", 42);
	 insert_hash(table, "Jair", 22);
	 insert_hash(table, "Antonio", 4);

	 printf("Jair %i\n", find_hash(table, "Jair"));
	 printf("Antonio %i\n", find_hash(table, "Antonio"));
	 printf("Not Found %i\n", find_hash(table, "Not Found"));

	 erase_hash(table, "Jair");

	 printf("Jair %i\n", find_hash(table, "Jair"));
	 printf("Antonio %i\n", find_hash(table, "Antonio"));
	 printf("Not Found %i\n", find_hash(table, "Not Found"));

	 delete_hash(table);
	 
    Ejemplo de uso de Recipe
	Recipe *recipe = (Recipe*) malloc(sizeof(Recipe));
	create_recipe(recipe, "Limonada");

	insert_ingredient(recipe, "Agua", 90);
	insert_ingredient(recipe, "Limon", 4);
	insert_ingredient(recipe, "Azucar", 6);

	for (int i = 0; i < recipe->count; i++) {
		char *ingredient = recipe->ingredients[i];
		printf("%i\t%s\n", find_percent(recipe, ingredient), ingredient);
	}

	delete_recipe(recipe);
	printf("////////////////////////////////////////////////////\n");
	*/
	FILE *file = fopen("Recipes.txt", "r");

	Recipe *recipes = (Recipe*) malloc(500);
	size_t size = 0;
	HashTable *ingredients = malloc(sizeof(HashTable));
	create_hash(ingredients, 500);

	read_file(file, recipes, &size, ingredients);

	for (int i = 0; i < size; i++) {
		printf("%s", recipes[i].name);

		for (int j = 0; j < recipes[i].count; j++) {
			char *ingredient = recipes[i].ingredients[j];

			printf("ID: %i\t%i\t%s\n",
				find_hash(ingredients, ingredient),
				find_percent(&recipes[i], ingredient),
				ingredient);
		}
	}
	///////////////////////////////////////////////////////////////////////////////
	char *ingredient_names[100];
	//Sacar los ID de los ingredientes en todas las recetas y meterlas en un arreglo, en otro se guardan los nombres de los ingredientes
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < recipes[i].count; j++) {
			char *ingredient = recipes[i].ingredients[j];
			ingredient_names[find_hash(ingredients, ingredient)] = ingredient;
		}
	}
	//Recorrer receta por receta, si un ingrediente coincide con el de la lista, se guarda su porcentaje, si no, se queda en 0
	printf("-------------------------------------------------------------\n");
	//Se crea la matriz donde se guardaran los datos y se inicializa
	int mat[100][100];

	for(int i = 0; i < ingredients->size; i++){
		for(int j = 0; j < size; j++){
			mat[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < recipes[i].count; j++) {
			char *ingredient = recipes[i].ingredients[j];
			mat[find_hash(ingredients, ingredient)][i] = find_percent(&recipes[i], ingredient);
		}
	}
	//Imprimir la matriz
	for(int i = 0; i < ingredients->size; i++){
		printf("ID: %i\t", i);
		for(int j = 0; j < size; j++){
			printf("%d\t", mat[i][j]);
		}
		printf("%s\n", ingredient_names[i]);
	}

	//Se crea la matriz donde se guardaran las distancias euclideanas y se inicializa
	double matDistance[size][size];

	for (int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			if (i == j){
				matDistance[i][j] = 0;
			} else {
				matDistance[i][j] = 1;
			}
		}
	}

	int suma = 0, aux = 0;

	printf("-------------------------------------------------------------\n");

	for(int i = 0; i < size; i++){
		for (int j = 0; j < ingredients->size; j++){
			if(i == size-1){
				suma += pow((mat[j][i] - mat[j][0]),2);
			} else {
				suma += pow((mat[j][i]-mat[j][i+1]),2);	
			}
		}

		if(i == size-1){
			matDistance[aux][0] = sqrt(suma);
			matDistance[0][aux] = sqrt(suma);
		} else {
			matDistance[i+1][aux] = sqrt(suma);
			matDistance[aux][i+1] = sqrt(suma);
		}
		aux++;
		suma = 0;

	}

	// Función para imprimir las distancias euclideanas
	for (int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			printf("%f\t", matDistance[j][i]);
		}
		printf("\n");
	}
	
	printf("-------------------------------------------------------------\n");
}

