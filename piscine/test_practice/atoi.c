#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int		ft_atoi(char *str)
{
	int		i;
	int		neg;
	int		total;
	i = 0;
	neg = 0;
	total = 0;
	while 	(str[i] == '\t' ||
			str[i] == ' ' ||
			str[i] == '\n' 
			)
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i]<= '9' && str[i] != '\0')
	{
		total = total * 10 + str[i] - '0';
		i++;
	}
	if(neg)
		total = -total;
	return (total);
}

int		ft_putnbr(int num)
{
	int total;
	int i;
	int neg;

	neg = 0;
	total = 0;
	i = 0;
	//printf("pt num");
	if (num < 0)
	{
		ft_putchar('-');
		num = num * -1;
	}
	if (num > 9)
	{
		//ft_putchar('z');
		//printf("%d", num);
		ft_putnbr(num / 10);
		ft_putchar(num % 10 + '0');
	}
	if (num < 10)
		ft_putchar(num + '0');

	return (0); 
}

int		main(int ac, char **argv)
{
	int		ans;

	ans = ft_atoi(argv[1]);

	ft_putnbr(ans);
	

	return (0);
}
