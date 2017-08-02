#include <unistd.h>

void	first_word(char *str);


int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
	}
	else
	{
		first_word(argv[1]);
	}
	return (0);
}

void	first_word(char *str)
{
	int		i;
	int		z;

	z = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] >= 'a' || str[i] <= 'z' || str[i] >= 'A' 
			|| str[i] >= 'Z') && str[i] != ' ' && str[i] != '\0')
		{
			write(1, &str[i], 1);
			z = 1;
			i++;
		}
		if (z){
			write(1, "\n", 1);
			return;
		}
		i++;
	}
	return ;
}