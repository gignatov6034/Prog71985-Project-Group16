//Prog71985 - Project - Group 16
//Gleb I, Tatsiana L, Friday N. - Header file for RecipeManipulation.c; 
//Recipe struct. 

#pragma once

#include <stdbool.h>

#define MAXTITLE 80
#define MAXDESCRIPTION 400
#define MAXRECIPES 25

typedef struct recipe {

	char title[MAXTITLE];
	char description[MAXDESCRIPTION]; 

	int index;
	bool exists;

} RECIPE;

void addRecipe(RECIPE* AllRecipes);
void deleteRecipe(RECIPE* AllRecipes);
void updateRecipe(RECIPE* AllRecipes);
void setRecipesIndex(RECIPE* AllRecipes);
bool checkIfExists(RECIPE* AllRecipes);
void SetArray(RECIPE* AllRecipes);