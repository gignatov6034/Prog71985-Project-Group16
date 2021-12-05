//Prog71985 - Project - Group 16
//Gleb I, Tatsiana L, Friday N. - RecipeManipulation.c contains all 
//functions related to using or modifying the array of recipes 


#include <stdio.h>
#include "RecipeManipulation.h"

void addRecipe(RECIPE* AllRecipes)
{

}

void deleteRecipe(RECIPE* AllRecipes)
{

}

void updateRecipe(RECIPE* AllRecipes)
{

}

void displaySingleRecipe(RECIPE* AllRecipes)
{

}

void displayAllRecipes(RECIPE* AllRecipes)
{

}

void searchForRecipe(RECIPE* AllRecipes)
{

}

void setRecipesIndex(RECIPE* AllRecipes)
{
	for (int i = 0; i < MAXRECIPES; i++)
	{
		AllRecipes[i].index = (i + 1);							
	}
}