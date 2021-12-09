//Prog71985 - Project - Group 16
//Gleb I, Tatsiana L, Friday N. - PrintMenu.c contains all functions related to the UI 
//Editor - Gleb Ignatov.

#include <stdio.h>
#include "PrintMenu.h"

void printMainMenu()
{
	fprintf(stdout, "\n\t\t\t\t\t\tMain Menu\n\n");
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
	fprintf(stdout, "\ta) Add new recipe\n");
	fprintf(stdout, "\tb) Delete existing recipe\n");
	fprintf(stdout, "\tc) Update existing recipe\n");
	fprintf(stdout, "\td) Display single recipe\n");
	fprintf(stdout, "\te) Display range of recipes\n");
	fprintf(stdout, "\tf) Display all recipes\n");
	fprintf(stdout, "\tg) Search for recipes\n\n");
	fprintf(stdout, "\th) Delete all recipes\n\n");
	fprintf(stdout, "\ti) Show program description\n\n");
	fprintf(stdout, "\tj) Save changes and quit\n");
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
}

void PrintWelcome()
{
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
	fprintf(stdout, "\n\t\t\t\t\t  Welcome to Simple Recipe!\n\n");
	fprintf(stdout, "\t\t\t\t     A program that stores your recipes \n\n");
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
}

void printProgramDescription()
{
	fprintf(stdout, "\n\t\t\t\t\t\tDevelopers:\n\n");
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
	fprintf(stdout, "\t\t\tGleb Ignatov\n");
	fprintf(stdout, "\t\t\tTatsiana Lesnikouskaya\n");
	fprintf(stdout, "\t\t\tFriday Nsiadu\n");
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
	fprintf(stdout, "\n\t\t\t\t\t   Program description:\n\n");
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
	fprintf(stdout, "\t\t\tThe program can memorize up to 25 recipes written by\n");
	fprintf(stdout, "\t\t\ta user. The program also provides various functions\n");
	fprintf(stdout, "\t\t\tfor viewing or modifying existing recipes: a user can\n");
	fprintf(stdout, "\t\t\tdelete, update, display, and search for recipes.\n");
	fprintf(stdout, "\t\t\tEach recipe consists of a titte and description\n");
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
}

void printUpdateMenu()
{
	fprintf(stdout, "\n\t\t\t\tHow do you want to update your recipe?\n\n");
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
	fprintf(stdout, "\ta) Change the title\n");
	fprintf(stdout, "\tb) Change the description\n");
	fprintf(stdout, "\tc) Change the title and description\n");
	fprintf(stdout, "\td) Go back to the main menu\n");
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
}

void deleteAllRecipesMenu()
{
	fprintf(stdout, "\t\t\t\t\tAre you sure?\n");
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
	fprintf(stdout, "\ta) Yes\n");
	fprintf(stdout, "\tb) No\n");
	fprintf(stdout, "------------------------------------------------------------------------------------------------------------\n");
}