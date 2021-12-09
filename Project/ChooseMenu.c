//Prog71985 - Project - Group 16
//Gleb I, Tatsiana L, Friday N. - ChooseMenu.c contains all functions related to menu selection

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ChooseMenu.h"
#include "PrintMenu.h"

void PrintWelcomeMenu(RECIPE* AllRecipes)
{
	setRecipesIndex(&AllRecipes[0]);					//sets all recipes' inicators (index) in ordinal

	PrintWelcome();

	bool continueProgram = true;

	while (continueProgram)
	{
		printMainMenu();

		fprintf(stdout, "\t\t\t\tPease enter 1 char to select an option...\n");
		char menuChoice = getch();		
		fprintf(stdout, "\t\t\t\tChar: = %c\n", menuChoice);
		fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");

		menuChoice = tolower(menuChoice);									//even if you type capital letters - the program will pass the input 

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
			deleteAllRecipes(&AllRecipes[0]);
			break;
		case 'i':
			printProgramDescription();
			break;
		case 'j':
			continueProgram = false; 
			break;
		default:
			fprintf(stdout, "\t\t\tInappropriate input\n");
			fprintf(stdout, "\t\t\tPlease be careful next time!\n");
			fprintf(stdout, "\t\t\tEnd of the program...\n");
			continueProgram = false; 
			break;
		}
	}
}

