//Prog71985 - Project - Group 16
//Gleb I, Tatsiana L, Friday N. - ChooseMenu.c contains all functions related to displaying recipes

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "DisplayRecipes.h"

void displaySingleRecipe(RECIPE* AllRecipes)
{
	if (!checkIfExists(&AllRecipes[0]))
	{
		fprintf(stdout, "\t\tNo recipes were added\n");
		return;
	}

	int numberOfRecipe;

	fprintf(stdout, "\t\tPlease enter the number of recipe you want to display (0 to go back).\n\t\t");
	if (scanf("%d", &numberOfRecipe) != 1)
	{
		fprintf(stdout, "\t\tInappropriate input\n\n");
		return;
	}
	fprintf(stdout, "\t\t\tInteger: %d\n\n", numberOfRecipe);

	if (numberOfRecipe == 0)													//go back to the main menu if 0
		return;
	else if (numberOfRecipe < 0 || numberOfRecipe > 50									//cheks if the input is appropriate 
		|| AllRecipes[numberOfRecipe - 1].exists != true)
	{
		fprintf(stdout, "\t\tThe recipe does not exist\n\n");
		return;
	}
	else
	{
		fprintf(stdout, "\t\t\t\t---Recipe number %2d ---\n", AllRecipes[numberOfRecipe - 1].index);
		fprintf(stdout, "\t Title: %s\n", AllRecipes[numberOfRecipe - 1].title);
		fprintf(stdout, "\t Description: %s\n\n", AllRecipes[numberOfRecipe - 1].description);
	}
}

void displayRangeOfRecipes(RECIPE* AllRecipes)
{
	if (!checkIfExists(&AllRecipes[0]))
	{
		fprintf(stdout, "\t\t\tNo recipes were added\n");
		return;
	}

	int lowerLimit;
	int upperLimit;

	fprintf(stdout, "\t\tPlease enter the lower and upper limits for the range:\n\t\t");
	if (scanf("%d %d", &lowerLimit, &upperLimit) != 2)
	{
		fprintf(stdout, "\t\tInappropriate input\n\n");
		return;
	}

	if (lowerLimit <= 0 || lowerLimit > 50 ||
		upperLimit > 50 || upperLimit <= 0 ||
		lowerLimit > upperLimit)
	{
		fprintf(stdout, "\t\tInappropriate input\n\n");
		return;
	}

	bool notExist = false;

	for (int i = lowerLimit - 1; i <= upperLimit - 1; i++)
	{
		if (AllRecipes[i].exists != true)
		{
			notExist = true;
			break;
		}
	}

	if (notExist)
	{
		fprintf(stdout, "\t\tSome recipes in a range do not exist\n\n");
		return;
	}

	if (lowerLimit == upperLimit)
	{
		fprintf(stdout, "\t\t\t\t---Recipe number %2d ---\n", AllRecipes[lowerLimit - 1].index);
		fprintf(stdout, "\t Title: %s\n\n", AllRecipes[lowerLimit - 1].title);
		fprintf(stdout, "\t Description: %s\n\n", AllRecipes[lowerLimit - 1].description);
	}
	else
	{
		for (int i = lowerLimit - 1; i <= upperLimit - 1; i++)
		{
			fprintf(stdout, "\t\t\t\t---Recipe number %2d ---\n", AllRecipes[i].index);
			fprintf(stdout, "\t Title: %s\n\n", AllRecipes[i].title);
			fprintf(stdout, "\t Description: %s\n\n", AllRecipes[i].description);
		}
	}
}

void displayAllRecipes(RECIPE* AllRecipes)
{

	if (!checkIfExists(&AllRecipes[0]))
	{
		fprintf(stdout, "\t\tNo recipes were added\n");
		return;
	}


	for (int i = 0; i < MAXRECIPES; i++)
	{
		if (AllRecipes[i].exists != false)
		{
			fprintf(stdout, "\t\t\t\t---Recipe number %2d ---\n", AllRecipes[i].index);
			fprintf(stdout, "\t Title: %s\n\n", AllRecipes[i].title);
			fprintf(stdout, "\t Description: %s\n\n", AllRecipes[i].description);
		}
	}
}

void searchForRecipe(RECIPE* AllRecipes)
{
	fprintf(stdout, "\t\tYou can find recipes by typing their titles\n");
	fprintf(stdout, "\t\tPress ENTER when you want to find coincidences (type 0 to go back)\n");

	char recipeTitle[MAXTITLE];

	if (gets(recipeTitle) == NULL)
	{
		fprintf(stdout, "\t\tInappropriate input\n");
		return;
	}

	if (recipeTitle[0] == '0')
		return;

	int i = 0;

	while (recipeTitle[i])
	{
		putchar(tolower(recipeTitle[i]));
		i++;
	}

	char changeCapitals[MAXRECIPES];

	memcpy(changeCapitals, AllRecipes, MAXRECIPES);

	int b = 0;

	for (i = 0; i < MAXRECIPES; i++)
	{
		while (AllRecipes[i].title[b])
		{
			putchar(tolower(AllRecipes[i].title[b]));
			b++;
		}
	}

	for (i = 0; i < MAXRECIPES; i++)
	{

	}
}
