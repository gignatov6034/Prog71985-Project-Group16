//Prog71985 - Project - Group 16
//Gleb I, Tatsiana L, Friday N. - OpenCloseFile.c contains all functions related to saving data to disk

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "OpenCloseFile.h"

void OpenAndLoadFile(RECIPE* AllRecipes)
{
	RECIPE* fp;

	if ((fp = fopen("datafile.txt", "r")) == NULL)
	{
		fprintf(stderr, "Can't open the %s file.\n", "datafile.txt");
		return 1;
	}

	for (int i = 0, b = 0; i < MAXRECIPES * 2; i++)
	{
		fread(&AllRecipes[i], sizeof(RECIPE), MAXRECIPES, fp);				//copies the data from datafile.txt to the array 
	}


	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Can't close the %s file.\n", "datafile.txt");
		return 1;
	}
}

void SaveAndCloseFile(RECIPE* AllRecipes)
{
	RECIPE* fp;

	if ((fp = fopen("datafile.txt", "w+")) == NULL)
	{
		fprintf(stderr, "Can't save the %s file.\n", "datafile.txt");
		return 1;
	}

	for (int i = 0; i < MAXRECIPES; i++)
	{
		fwrite(&AllRecipes[i], 1, sizeof(RECIPE), fp);						//puts the data from the array to datafile.txt
	}

	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Can't close the %s file.\n", "datafile.txt");
		return 1;
	}
}