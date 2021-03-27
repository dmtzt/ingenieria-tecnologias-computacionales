//
//  ReadFile.h
//  Proyecto Recetas
//
//  Created by Jair Antonio on 10/03/21.
//

#ifndef ReadFile_h
#define ReadFile_h

#include <stdio.h>

#include "Recipe.h"

void read_file(FILE *file, Recipe* recipes, size_t *size, HashTable *ingredients);

#endif /* ReadFile_h */
