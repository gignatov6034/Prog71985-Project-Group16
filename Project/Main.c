//Prog71985 - Project - Group 16
//Gleb I, Tatsiana L, Friday N. - Main function

#include <stdio.h>

#include "ChooseMenu.h"
#include "OpenCloseFile.h"
#include "PrintMenu.h"
#include "RecipeManipulation.h"

int main(void)
{
	RECIPE AllRecipes[MAXRECIPES];							//set the main array that will "hold recipes"

	SetArray(&AllRecipes[0]);

	OpenAndLoadFile(&AllRecipes[0]);

	PrintWelcomeMenu(&AllRecipes[0]);

	SaveAndCloseFile(&AllRecipes[0]);

	return (0);
}