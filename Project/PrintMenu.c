//Prog71985 - Project - Group 16
//Gleb I, Tatsiana L, Friday N. - PrintMenu.c contains all functions related to the UI 

#include <stdio.h>
#include "PrintMenu.h"

void printMainMenu()
{
	fprintf(stdout, "\t\t\t\t\t\tMain Menu\n");
	fprintf(stdout, "\t\t\ta) Add new recipe\n");
	fprintf(stdout, "\t\t\tb) Delete an existing recipe\n");
	fprintf(stdout, "\t\t\tc) Update an existing recipe\n");
	fprintf(stdout, "\t\t\td) Display a single recipe\n");
	fprintf(stdout, "\t\t\te) Display a range of recipes\n");
	fprintf(stdout, "\t\t\tf) Display all recipes\n");
	fprintf(stdout, "\t\t\tg) Search for a recipe\n\n");
	fprintf(stdout, "\t\t\th) Show program description\n\n");
	fprintf(stdout, "\t\t\ti) Quit\n\n");
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