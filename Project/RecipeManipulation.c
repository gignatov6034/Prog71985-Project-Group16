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
	if (!checkIfExists)
	{
		fprintf(stdout, "No recipes were added\n");
		return;
	}


}

void updateRecipe(RECIPE* AllRecipes)
{
	if (!checkIfExists)
	{
		fprintf(stdout, "No recipes were added\n");
		return;
	}


}

void displaySingleRecipe(RECIPE* AllRecipes)
{
	if (!checkIfExists)
	{
		fprintf(stdout, "No recipes were added\n");
		return;
	}

	int numberOfRecipe;

	fprintf(stdout, "Please enter the number of recipe you want to display.\n");
	if (scanf_s("%d", &numberOfRecipe) != 1)
	{
		fprintf(stdout, "Inappropriate input\n");
		return;
	}
	fprinf(stdout, "Integer: %d", numberOfRecipe);

	if (numberOfRecipe <= 0 || numberOfRecipe > 50 
		|| AllRecipes[numberOfRecipe - 1].exists == false)
	{
		fprintf(stdout, "The recipe does not exist");
		return;
	}
	else
	{
		fprintf(stdout, "\t\t---Recipe number %2d ---\n", AllRecipes[numberOfRecipe - 1].index);
		fprintf(stdout, "\t Title: %s\n", AllRecipes[numberOfRecipe - 1].title);
		fprintf(stdout, "\t Description: %s\n\n", AllRecipes[numberOfRecipe - 1].description);
	}
}

void displayAllRecipes(RECIPE* AllRecipes)
{

	if (!checkIfExists)
	{
		fprintf(stdout, "No recipes were added\n");
		return;
	}


	for (int i = 0; i < MAXRECIPES; i++)
	{
		if (AllRecipes[i].exists == true) 
		{
			fprintf(stdout, "\t\t---Recipe number %2d ---\n", AllRecipes[i].index);
			fprintf(stdout, "\t Title: %s\n", AllRecipes[i].title);
			fprintf(stdout, "\t Description: %s\n\n", AllRecipes[i].description);
		}
	}
}

void searchForRecipe(RECIPE* AllRecipes)
{

}

void setRecipesIndex(RECIPE* AllRecipes)
{
	int countExist = 1;
	for (int i = 0; i < MAXRECIPES; i++)
	{
		if (AllRecipes[i].exists == true)
		{
			AllRecipes[i].index = countExist;
			countExist++;
		}							
	}
}

bool checkIfExists(RECIPE* AllRecipes)					//cheks if the array has at least 1 recipe
{
	bool exists = false;

	for (int i = 0; i < MAXRECIPES; i++)
	{
		if (AllRecipes[i].exists == true)
		{
			exists = true;
			break;
		}
	}

	return exists;
}