//Prog71985 - Project - Group 16
//Gleb I, Tatsiana L, Friday N. - RecipeManipulation.c contains all 
//functions related to using or modifying the array of recipes 


#include <stdio.h>
#include "RecipeManipulation.h"

void addRecipe(RECIPE* AllRecipes)
{
	bool isFull = true;

	for (int i = 0; i < MAXRECIPES; i++)
	{
		if (AllRecipes[i].exists == false)					
		{
			isFull = false;
			break;
		}
	}

	if (isFull)
	{
		fprintf(stdout, "\t\t\tThe list is full!");			//if the array is full, then return
		return;
	}

	char recipeTitle[MAXTITLE];
	char recipeDescription[MAXDESCRIPTION];

	fprintf(stdout, "\t\t\tPlease enter the title of your recipe (q to go back):\n");
	
	if (fscanf(stdin, "%s", recipeTitle) != 1)
	{
		fprintf(stdout, "\t\t\tInappropriate input\n");
		return;
	}
	
	if (recipeTitle == 'q')
		return;

	fprintf(stdout, "\t\t\tPlease enter the description of your recipe (q to go back):\n");

	if (fscanf(stdin, "%s", recipeDescription) != 1)
	{
		fprintf(stdout, "\t\t\tInappropriate input\n");
		return;
	}

	if (recipeTitle == 'q')
		return;

	for (int i = 0; i < MAXRECIPES; i++)
	{
		if (AllRecipes[i].exists == false)
		{
			strcpy(&AllRecipes[i].title[0], &recipeTitle);
			strcpy(&AllRecipes[i].description[0], &recipeDescription);
		}
	}

	setRecipesIndex(&AllRecipes[0]);
}

void deleteRecipe(RECIPE* AllRecipes)
{
	if (!checkIfExists)
	{
		fprintf(stdout, "\t\t\tNo recipes were added\n");
		return;
	}

	fprintf(stdout, "\t\t\tPlease enter the number of the recipe to be deleted (0 to go back):\n");

	int recipeNumber;

	if ((fscanf(stdin, "%d", &recipeNumber) != 1))
	{
		fprintf(stdout, "\t\t\tInappropriate input\n");
		return;
	}
	else if (recipeNumber <= 0 || recipeNumber > 50)
	{
		fprintf(stdout, "\t\t\tThe value is not in range. Shoud be from 1 to 50\n");
		return;
	}
	else if (AllRecipes[recipeNumber - 1].exists == false)
	{
		fprintf(stdout, "\t\t\tA recipe with this number does not exist\n");
		return;
	}

	AllRecipes[recipeNumber - 1].title[0] = 0;
	AllRecipes[recipeNumber - 1].description[0] = 0;
	AllRecipes[recipeNumber - 1].exists = false;

	setRecipesIndex(&AllRecipes[0]);
}

void updateRecipe(RECIPE* AllRecipes)
{
	if (!checkIfExists)
	{
		fprintf(stdout, "\t\t\tNo recipes were added\n");
		return;
	}

	printUpdateMenu();

	fprintf(stdout, "\t\t\tPease enter 1 char to select an option...\n");
	char menuChoice = getch();
	fprintf(stdout, "\t\t\tChar: = %c\n\n", menuChoice);

	switch (menuChoice)
	{
	case 'a':

		break;
	case 'b':

		break;
	case 'c':

		break;
	case 'd':
		break;
	default:
		fprintf(stdout, "\t\t\tInappropriate input\n");
		fprintf(stdout, "\t\t\tPlease be careful next time!\n");
		fprintf(stdout, "\t\t\tEnd of the program...\n");
		exit(1);
		break;
	}
}

void displaySingleRecipe(RECIPE* AllRecipes)
{
	if (!checkIfExists)
	{
		fprintf(stdout, "\t\t\tNo recipes were added\n");
		return;
	}

	int numberOfRecipe;

	fprintf(stdout, "\t\t\tPlease enter the number of recipe you want to display.\n");
	if (scanf_s("%d", &numberOfRecipe) != 1)
	{
		fprintf(stdout, "\t\t\tInappropriate input\n");
		return;
	}
	fprinf(stdout, "\t\t\tInteger: %d", numberOfRecipe);

	if (numberOfRecipe <= 0 || numberOfRecipe > 50 
		|| AllRecipes[numberOfRecipe - 1].exists == false)
	{
		fprintf(stdout, "\t\t\tThe recipe does not exist");
		return;
	}
	else
	{
		fprintf(stdout, "\t\t---Recipe number %2d ---\n", AllRecipes[numberOfRecipe - 1].index);
		fprintf(stdout, "\t Title: %s\n", AllRecipes[numberOfRecipe - 1].title);
		fprintf(stdout, "\t Description: %s\n\n", AllRecipes[numberOfRecipe - 1].description);
	}
}

void displayRangeOfRecipes(RECIPE* AllRecipes)
{
	if (!checkIfExists)
	{
		fprintf(stdout, "\t\t\tNo recipes were added\n");
		return;
	}

	int lowerLimit;
	int upperLimit;

	fprintf(stdout, "\t\t\tPlease enter the lower and upper limits for the range:\n");
	if (scanf_s("%d %d", &lowerLimit, &upperLimit) != 2)
	{
		fprintf(stdout, "\t\t\tInappropriate input\n");
		return;
	}
	
	if (lowerLimit <= 0 || lowerLimit > 50 || 
		upperLimit > 50 || upperLimit <= 0 ||
		lowerLimit > upperLimit)
	{
		fprintf(stdout, "\t\t\tInappropriate input");
	}

	if (lowerLimit == upperLimit)
	{
		fprintf(stdout, "\t\t---Recipe number %2d ---\n", AllRecipes[lowerLimit].index);
		fprintf(stdout, "\t Title: %s\n", AllRecipes[lowerLimit].title);
		fprintf(stdout, "\t Description: %s\n\n", AllRecipes[lowerLimit].description);
	}
	else
	{
		for (int i = lowerLimit; i <= upperLimit; i++)
		{
			fprintf(stdout, "\t\t---Recipe number %2d ---\n", AllRecipes[i].index);
			fprintf(stdout, "\t Title: %s\n", AllRecipes[i].title);
			fprintf(stdout, "\t Description: %s\n\n", AllRecipes[i].description);
		}
	}
}

void displayAllRecipes(RECIPE* AllRecipes)
{

	if (!checkIfExists)
	{
		fprintf(stdout, "\t\t\tNo recipes were added\n");
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