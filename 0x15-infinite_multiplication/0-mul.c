#include "holberton.h"

/**
 * _puts - Function that prints a string to stdout.
 * @str: character.
 * Return: Always 0.
**/
void _puts(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}

/**
 * _isdigit - Function that checks if str is a digit
 * @str: character.
 * Return: 0 or 1.
 */
int _isdigit(char str)
{
	int num;

	if (str >= 48 && str <= 57)
	{
		num = 1;
	}
	else
	{
		num = 0;
	}
	return (num);
}

/**
 * val_digit - tFunction that checks for digit as caracter.
 * @str: character.
 * Return: void
 */
void val_digit(char *str)
{
	int x = 0;

	while (str[x] != '\0')
	{
		if (_isdigit(str[x]))
		{
			x++;
		}
		else
		{
			_puts("Error");
			exit(98);
		}
	}
}

/**
 * mult - Function that allows multiply two numbers
 * @a: first num to be multiplied
 * @b: second num to be multiplied
 * @l1: lenght of first number
 * @l2: lenght of second number
 * Return: void
 */
char *mult(char *a, char *b, int l1, int l2)
{
	char *val = NULL;
	int x, y, flag, sum_len, end1, end2;

	sum_len = l1 + l2;
	val = malloc(sizeof(char) * sum_len);
	if (val == NULL)
	{
		_puts("Error");
		exit(98);
	}
	for (x = 0; x < sum_len; x++)
	{
		val[x] = '0';
	}
	end1 = l1 - 1;
	for (x = end1; x >= 0; x--)
	{
		flag = 0;
		end2 =  l2 - 1;
		for (y = end2; y >= 0; y--)
		{
			flag += (a[x] - '0') * (b[y] - '0');
			flag += val[x + y + 1] - '0';
			val[x + y + 1] = (flag % 10) + '0';
			flag /= 10;
		}

		if (flag)
		{
			val[x + y + 1] = (flag % 10) + '0';
		}
	}
	return (val);
}

/**
 * main - Main file
 * @ac: number of arguments
 * @av: value of arguments
 * Return: 0 (sucess) or 1 (error)
 */
int main(int ac, char **av)
{
	int l1 = 0, l2 = 0;
	char *a = av[1], *b = av[2], *val = NULL;

	val_digit(av[1]);
	val_digit(av[2]);
	if (ac != 3 || av[1][0] == 48 || av[2][0] == 48)
	{
		_puts("Error");
		exit(98);
	}
	while (a[l1])
	{
		l1++;
	}
	while (b[l2])
	{
		l2++;
	}
	val = mult(a, b, l1, l2);
	if (val[0] == '0')
	{
		_puts(val + 1);
	}
	else
	{
		_puts(val);
	}
	free(val);
	return (0);
}
