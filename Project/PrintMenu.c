//Prog71985 - Project - Group 16
//Gleb I, Tatsiana L, Friday N. - PrintMenu.c contains all functions related to the UI 

#include <stdio.h>
#include "PrintMenu.h"

void printMainMenu()
{
	fprintf(stdout, "\t\t\t\t\t\tMain Menu\n\n");
	fprintf(stdout, "\ta) Add new recipe\n");
	fprintf(stdout, "\tb) Delete an existing recipe\n");
	fprintf(stdout, "\tc) Update an existing recipe\n");
	fprintf(stdout, "\td) Display a single recipe\n");
	fprintf(stdout, "\te) Display a range of recipes\n");
	fprintf(stdout, "\tf) Display all recipes\n");
	fprintf(stdout, "\tg) Search for a recipe\n\n");
	fprintf(stdout, "\th) Show program description\n\n");
	fprintf(stdout, "\ti) Quit\n\n");
}

void PrintWelcome()
{
	fprintf(stdout, "\n\n\t\t\t\t\t  Welcome to Simple Recipe!\n");
	fprintf(stdout, "\t\t\t\tThe program that records and saves tour recipes\n\n");
}

void printProgramDescription()
{
	fprintf(stdout, "\t\t\t\t\t\tDevelopers:\n\n");
	fprintf(stdout, "\t\t\tGleb Ignatov\n");
	fprintf(stdout, "\t\t\tTatsiana Lesnikouskaya\n");
	fprintf(stdout, "\t\t\tFriday Nsiadu\n\n");
	fprintf(stdout, "\t\t\tProgram description:\n");
	fprintf(stdout, "\t\t\tThe program can memorize up to 50 recipes written by\n");
	fprintf(stdout, "\t\t\ta user. The program also provides various functions\n");
	fprintf(stdout, "\t\t\tfor viewing or modifying existing recipes: a user can\n");
	fprintf(stdout, "\t\t\tdelete, update, display, and search for recipes.\n");
	fprintf(stdout, "\t\t\tEach recipe consists of a titte and description\n\n");
}

void printUpdateMenu()
{
	fprintf(stdout, "\t\t\tHow do you want to update your recipe?\n\n");
	fprintf(stdout, "\ta) Change the title\n");
	fprintf(stdout, "\tb) Change the description\n");
	fprintf(stdout, "\tc) Change the title and description\n");
	fprintf(stdout, "\td) Go back to the main menu\n\n");
}