#define _POSIX_C_SOURCE 200809L
#include "rsa.h"

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
	long int v_num;
	int c;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: factors file\n");
		exit(EXIT_FAILURE);
	}
	fptr = fopen(av[1], "r");
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
			v_num = atoi(num);
			c = 2;
			while (c < v_num)
			{
				if (v_num % c == 0)
				{
					printf("%ld=%ld*%d\n", v_num, v_num / c, c);
					break;
				}
				c++;
			}
		}
	}
	fclose(fptr);
	free(buffer);
	return (0);
}
