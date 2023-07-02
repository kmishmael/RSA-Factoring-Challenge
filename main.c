#define _POSIX_C_SOURCE 200809L
#include "rsa.h"

void factors(long long int v_num);

/*
int main(int ac, char **av)
{
	FILE *fptr;
	size_t i = 0;
	char *buffer;
	char *num;
	long long v_num;
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
			v_num = atoll(num);
			if (v_num % 2 == 0)
			{
				printf("%lld=%lld*%d\n", v_num, v_num / 2, 2);
			}
			c = 3;
			while ((c * c) < v_num)
			{
				if (v_num % c == 0)
				{
					printf("%lld=%lld*%d\n", v_num, v_num / c, c);
					break;
				}
				c += 2;
			}
		}
	}
	fclose(fptr);
	free(buffer);
	return (0);
}
*/

void factors(long long int v_num)
{
	int c;

	if (v_num % 2 == 0)
	{
		printf("%lld=%lld*%d\n", v_num, v_num / 2, 2);
	}
	c = 3;
	while ((c * c) <= v_num)
	{
		if (v_num % c == 0)
		{
			printf("%lld=%lld*%d\n", v_num, v_num / c, c);
			break;
		}
		c += 2;
	}
}
