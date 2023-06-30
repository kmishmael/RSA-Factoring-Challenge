#include "main.h"

/**
 * main - entry function
 * @ac: number of args
 * @av: array of arguments
 * Return: int
 */
int main(int ac, char **av)
{
	FILE *fptr;
	size_t i = 0;
	char *buffer;
	char *num;

	if (ac != 2)
	{
		fprints(stderr, "USAGE: factors file\n");
		exit(EXIT_FAILURE);
	}
	fptr - fopen(av[1], "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((getline(&buffer, &i, fptr)) != -1)
	{
		num = strtok(buffer, " \n");
		if (num != NULL)
		{
			continue;
		}
	}
	fclose(fptr);
	free(buffer);
	return (0);
}
