/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 14:51:25 by zsmith            #+#    #+#             */
/*   Updated: 2016/07/31 14:51:26 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

void	ft_putchar(char c)
{
  write(1, &c, 1);
}

char	*ft_putnbr(int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(8);
  if (n < 0)
    {
      ft_putchar('-');
      n = -n;
    }
  if (n >= 10)
    {
      ft_putnbr(n / 10);
      str[i] = (n % 10 + '0');
      i++;
    }
  if (n < 10)
    {
      str[i] = (n % 10 + '0');
      i++;
    }
  return (str);
}

int		len(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


int		paren_ct(char *str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ')' || str[i] == '(')
			j++;
		i++;
	}
	return (j);	
}

int		ft_atoi(char *str)
{
	int n;
	int isneg;

	isneg = 0;
	n = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		isneg = 1;
		str++;
	}
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		n = n * 10 + (*str++ - '0');
	}
	if (isneg)
		return (-n);
	else
		return (n);
}