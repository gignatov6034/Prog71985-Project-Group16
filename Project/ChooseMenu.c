//Prog71985 - Project - Group 16
//Gleb I, Tatsiana L, Friday N. - ChooseMenu.c contains all functions related to menu selection (switch - case functions)

#include <stdio.h>
#include "ChooseMenu.h"
#include "PrintMenu.h"

void PrintWelcomeMenu(RECIPE* AllRecipes)
{
	setRecipesIndex(&AllRecipes[0]);					//sets all recipes' inicators (index) in ordinal

	bool continueProgram = true;

	while (continueProgram)
	{
		printMainMenu();

		fprintf(stdout, "\t\t\t\nPease enter 1 char to select an option...\n");
		char menuChoice = getch();														
		fprintf(stdout, "\t\t\tChar: = %c\n\n", menuChoice);

		switch (menuChoice)
		{
		case 'a':
			addRecipe(&AllRecipes[0]);
			break;
		case 'b':
			deleteRecipe(&AllRecipes[0]);
			break;
		case 'c':
			updateRecipe(&AllRecipes[0]);
			break;
		case 'd':
			displaySingleRecipe(&AllRecipes[0]);
			break;
		case 'e':
			displayRangeOfRecipes(&AllRecipes[0]);
			break;
		case 'f':
			displayAllRecipes(&AllRecipes[0]);
			break;
		case 'g':
			searchForRecipe(&AllRecipes[0]);
			break;
		case 'h':
			printProgramDescription();
			break;
		case 'i':
			continueProgram = false; 
			break;
		default:
			fprintf(stdout, "\t\t\t\nInappropriate input\n");
			fprintf(stdout, "\t\t\tPlease be careful next time!\n");
			fprintf(stdout, "\t\t\t\nEnd of the program...\n");
			continueProgram = false; 
			break;
		}
	}
}