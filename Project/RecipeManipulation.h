//Prog71985 - Project - Group 16
//Gleb I, Tatsiana L, Friday N. - Header file for RecipeManipulation.c; 
//Recipe struct. 

#pragma once

#include <stdbool.h>

#define MAXTITLE 80
#define MAXDESCRIPTION 400
#define MAXRECIPES 50

typedef struct recipe {

	char title[MAXTITLE];
	char description[MAXDESCRIPTION]; 

	int number;
	bool exists;

} RECIPE;

void addRecipe(RECIPE* AllRecipes);
void deleteRecipe(RECIPE* AllRecipes);
void updateRecipe(RECIPE* AllRecipes);
void singleRecipe(RECIPE* AllRecipes);
void displayAllRecipes(RECIPE* AllRecipes);
void searchRecipe(RECIPE* AllRecipes);