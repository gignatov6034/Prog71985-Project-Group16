//Prog71985 - Project - Group 16
//Gleb I, Tatsiana L, Friday N. - RecipeManipulation.c contains all 
//functions related to modifying the array of recipes 

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "RecipeManipulation.h"

void addRecipe(RECIPE* AllRecipes)
{
	bool isFull = true;

	for (int i = 0; i < MAXRECIPES; i++)
	{
		if (AllRecipes[i].exists != true)					
		{
			isFull = false;
			break;
		}
	}

	if (isFull)
	{
		fprintf(stdout, "\t\t\tThe list is full!\n");			//if the array is full, then return
		return;
	}

	char recipeTitle[MAXTITLE];
	char recipeDescription[MAXDESCRIPTION];

	fprintf(stdout, "\t\tPlease enter the title of your recipe (0 to go back):\n\t\t");
	
	if (fgets(recipeTitle, MAXTITLE, stdin) == NULL)
	{
		fprintf(stdout, "\t\tInappropriate input\n");
		return;
	}
	
	if (recipeTitle[0] == '0')
		return;

	fprintf(stdout, "\t\tPlease enter the description of your recipe (0 to cancel and go back):\n\t\t");

	if (fgets(recipeDescription, MAXDESCRIPTION, stdin) == NULL)
	{
		fprintf(stdout, "\t\tInappropriate input\n");
		return;
	}

	if (recipeDescription[0] == '0')
		return;

	for (int i = 0; i < MAXRECIPES; i++)
	{
		if (AllRecipes[i].exists != true)
		{
			strcpy(&AllRecipes[i].title[0], &recipeTitle);
			strcpy(&AllRecipes[i].description[0], &recipeDescription);
			AllRecipes[i].exists = true;
			break;
		}
	}
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

	fprintf(stdout, "\n\t\t\t\tThe recipe was successfully added.\n\n");
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

	setRecipesIndex(&AllRecipes[0]);
}

void deleteRecipe(RECIPE* AllRecipes)
{
	if (!checkIfExists(&AllRecipes[0]))
	{
		fprintf(stdout, "\t\tNo recipes were added\n");
		return;
	}

	fprintf(stdout, "\t\tPlease enter the number of the recipe to be deleted (0 to go back):\n\t\t");

	int recipeNumber;

	if ((fscanf(stdin, "%d", &recipeNumber) != 1))
	{
		fprintf(stdout, "\t\tInappropriate input\n");
		return;
	}
	else if (recipeNumber < 0 || recipeNumber > 50)
	{
		fprintf(stdout, "\t\tThe value is not in range. Shoud be from 1 to 50\n");
		return;
	}
	else if (recipeNumber == 0)
		return;
	else if (AllRecipes[recipeNumber - 1].exists != true)
	{
		fprintf(stdout, "\t\tA recipe with this number does not exist\n");
		return;
	}

	AllRecipes[recipeNumber - 1].title[0] = 0;
	AllRecipes[recipeNumber - 1].description[0] = 0;
	AllRecipes[recipeNumber - 1].exists = false;

	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
	fprintf(stdout, "\n\t\t\t\tThe recipe was successfully deleted.\n\n");
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

	setRecipesIndex(&AllRecipes[0]);
}

void updateRecipe(RECIPE* AllRecipes)
{
	if (!checkIfExists(&AllRecipes[0]))
	{
		fprintf(stdout, "\t\tNo recipes were added\n");
		return;
	}

	printUpdateMenu();

	fprintf(stdout, "\t\t\t\tPease enter 1 char to select an option...\n\t\t");
	char menuChoice = getch();
	fprintf(stdout, "\t\tChar: = %c\n", menuChoice);
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

	menuChoice = tolower(menuChoice);									//even if you type capital letters - the program will pass the input 

	char recipeTitle[MAXTITLE];
	char recipeDescription[MAXTITLE];
	int numberOfRecipe;

	switch (menuChoice)
	{
	case 'a':																				
		
		fprintf(stdout, "\t\tPlease enter the number of a recipe you want to update (0 to go back):\n\t\t");
		if (scanf("%d", &numberOfRecipe) != 1)
		{
			fprintf(stdout, "\t\tInappropriate input\n\n");
			return;
		}

		if (numberOfRecipe == 0)													//go back to the main menu if 0
			return;
		else if (numberOfRecipe < 0 || numberOfRecipe > 50									//cheks if the input is appropriate 
			|| AllRecipes[numberOfRecipe - 1].exists != true)
		{
			fprintf(stdout, "\t\tThe recipe does not exist\n\n");
			return;
		}

		while ((getchar()) != '\n');																		//clear the input buffer
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

		fprintf(stdout, "\n\t\t\t\t---Recipe number %2d ---\n\n", AllRecipes[numberOfRecipe - 1].index);
		fprintf(stdout, "\t Title: %s\n", AllRecipes[numberOfRecipe - 1].title);
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

		fprintf(stdout, "\t\t\tPlease enter the new title (0 to go back):\n\t\t\t");

		if (fgets(recipeTitle, MAXTITLE, stdin) == NULL)
		{
			fprintf(stdout, "\t\tInappropriate input\n");
			return;
		}
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

		if (recipeTitle[0] == '0')
			return;

		strcpy(&AllRecipes[numberOfRecipe - 1].title[0], &recipeTitle);

		fprintf(stdout, "\n\t New Title: %s\n", AllRecipes[numberOfRecipe - 1].title);
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

		fprintf(stdout, "\t\t\t\tThe recipe was successfully updated.\n");
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
		break;
	case 'b':
		fprintf(stdout, "\t\tPlease enter the number of a recipe you want to update (0 to go back):\n\t\t");
		if (scanf("%d", &numberOfRecipe) != 1)
		{
			fprintf(stdout, "\t\tInappropriate input\n\n");
			return;
		}
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

		if (numberOfRecipe == 0)													//go back to the main menu if 0
			return;
		else if (numberOfRecipe < 0 || numberOfRecipe > 50									//cheks if the input is appropriate 
			|| AllRecipes[numberOfRecipe - 1].exists != true)
		{
			fprintf(stdout, "\t\tThe recipe does not exist\n\n");
			return;
		}

		while ((getchar()) != '\n');																		//clear the input buffer

		fprintf(stdout, "\n\t\t\t\t---Recipe number %2d ---\n\n", AllRecipes[numberOfRecipe - 1].index);
		fprintf(stdout, "\t Description: %s\n", AllRecipes[numberOfRecipe - 1].description);
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

		fprintf(stdout, "\t\t\tPlease enter the new description (0 to go back):\n\t\t\t");

		if (fgets(recipeDescription, MAXDESCRIPTION, stdin) == NULL)
		{
			fprintf(stdout, "\t\tInappropriate input\n");
			return;
		}
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

		if (recipeDescription[0] == '0')
			return;

		strcpy(&AllRecipes[numberOfRecipe - 1].description[0], &recipeDescription);

		fprintf(stdout, "\t New description: %s\n\n", AllRecipes[numberOfRecipe - 1].description);

		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
		fprintf(stdout, "\t\t\t\tThe recipe was successfully updated.\n");
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
		break;
	case 'c':

		fprintf(stdout, "\t\tPlease enter the number of a recipe you want to update (0 to go back):\n\t\t");
		if (scanf("%d", &numberOfRecipe) != 1)
		{
			fprintf(stdout, "\t\tInappropriate input\n\n");
			return;
		}
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

		if (numberOfRecipe == 0)													//go back to the main menu if 0
			return;
		else if (numberOfRecipe < 0 || numberOfRecipe > 50									//cheks if the input is appropriate 
			|| AllRecipes[numberOfRecipe - 1].exists != true)
		{
			fprintf(stdout, "\t\tThe recipe does not exist\n\n");
			return;
		}

		while ((getchar()) != '\n');																		//clear the input buffer

		fprintf(stdout, "\t\t\t\t---Recipe number %2d ---\n\n", AllRecipes[numberOfRecipe - 1].index);
		fprintf(stdout, "\t Title: %s\n", AllRecipes[numberOfRecipe - 1].title);
		fprintf(stdout, "\t Description: %s\n\n", AllRecipes[numberOfRecipe - 1].description);
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

		fprintf(stdout, "\t\t\tPlease enter the new title (0 to go back):\n\t\t\t");

		if (fgets(recipeTitle, MAXTITLE, stdin) == NULL)
		{
			fprintf(stdout, "\t\tInappropriate input\n");
			return;
		}

		if (recipeTitle[0] == '0')
			return;

		fprintf(stdout, "\t\t\tPlease enter the new description (0 to go back):\n\t\t\t");

		if (fgets(recipeDescription, MAXDESCRIPTION, stdin) == NULL)
		{
			fprintf(stdout, "\t\tInappropriate input\n");
			return;
		}
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

		if (recipeDescription[0] == '0')
			return;

		strcpy(&AllRecipes[numberOfRecipe - 1].title[0], &recipeTitle);
		strcpy(&AllRecipes[numberOfRecipe - 1].description[0], &recipeDescription);

		fprintf(stdout, "\n\t New Title: %s\n\n", AllRecipes[numberOfRecipe - 1].title);
		fprintf(stdout, "\t New description: %s\n\n", AllRecipes[numberOfRecipe - 1].description);
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

		fprintf(stdout, "\t\t\t\tThe recipe was successfully updated.\n");
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
		break;
	case 'd':
		break;
	default:
		fprintf(stdout, "\t\tInappropriate input\n");
		return;
		break;
	}
}


void setRecipesIndex(RECIPE* AllRecipes)
{
	int countExist = 1;
	for (int i = 0; i < MAXRECIPES; i++)
	{
		if (AllRecipes[i].exists != false)
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
		if (AllRecipes[i].exists != false)
		{
			exists = true;
			break;
		}
	}

	return exists;
}


void SetArray(RECIPE* AllRecipes)
{
	for (int i = 0; i < MAXRECIPES; i++)
	{
		AllRecipes[i].exists = false;
	}
}

void deleteAllRecipes(RECIPE* AllRecipes)
{
	if (!checkIfExists(&AllRecipes[0]))
	{
		fprintf(stdout, "\t\tNo recipes were added\n");
		return;
	}

	deleteAllRecipesMenu();

	fprintf(stdout, "\t\t\t\tPease enter 1 char to select an option...\n\t\t");
	char menuChoice = getch();
	fprintf(stdout, "\t\tChar: = %c\n", menuChoice);
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

	menuChoice = tolower(menuChoice);									//even if you type capital letters - the program will pass the input 

	switch (menuChoice)
	{
	case 'a':
		for (int i = 0; i < MAXRECIPES; i++)
		{
			AllRecipes[i].title[0] = 0;
			AllRecipes[i].description[0] = 0;
			AllRecipes[i].exists = false;
		}

		fprintf(stdout, "\t\t\t\tRecipes were successfully deleted\n");
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

		setRecipesIndex(&AllRecipes[0]);
		break;
	case 'b':
		break;
	default:
		fprintf(stdout, "\t\tInappropriate input\n");
		return;
		break;
	}

	setRecipesIndex(&AllRecipes[0]);
}