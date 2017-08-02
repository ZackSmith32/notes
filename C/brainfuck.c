#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void		brainfuck(char *str)
{
	int		i;
	int		counter;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * 2048);
	while (i < 2048)
	{
		ret[i] = 0;
		i++;
	}
	i = 0;	
	while (str[i] != 0)
	{
		if (str[i] == '>')
			ret++;
		if (str[i] == '<')
			ret--;
		if (str[i] == '+')
			(*ret)++;
		if (str[i] == '-')
			(*ret)--;
		if (str[i] == '.')
		{
			printf("i = %d\n", i);
			printf("ret = %d\n", *ret);
			printf("ret = %c\n", *ret);
			ft_putchar(*ret);
		}
		printf("open brac ret = %d, str[i] = %c\n", *ret, str[i]	);
		if (str[i] == '[' && *ret == 0)
		{
			printf("[\n");	
			while (1)
			{
				if (str[i] == '[')
				{
					counter++;
				}
				else if (str[i] == ']')
				{
					counter--;
				}
				if (counter == 0)
					break;
				i++;
			}
		}
		if (str[i] == ']' && *ret != 0)
		{
			printf("] i = %d\n", i);
			while (1)
			{
				printf("backtrack while\n");
				if (str[i] == ']')
				{
					counter++;
				}
				else if (str[i] == '[')
					counter--;
				if (counter == 0)
					break;
				i--;

			}
			printf("] i = %d\n", i);
		}
		// print	f("done w loop\n");
		i++;
	}
}

int		main(void)
{
	brainfuck("+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>.");
	return (0);
}