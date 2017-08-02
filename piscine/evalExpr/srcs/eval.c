/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 18:37:20 by zsmith            #+#    #+#             */
/*   Updated: 2016/07/30 18:37:24 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#include "main.h"


int		count_nums(char *str)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			n++;
		i++;
	}
	return (n / 2 - 1);
}

int		count_ops(char *str)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (str[i])
	{
		if(	*str == '+' ||
			*str == '-' ||
			*str == '/' ||
			*str == '%' ||
			*str == '*' ||
			*str == '(' ||
			*str == ')')
		{
			n++;
		}
		i++;
	}
	return (n);
}

char		**parse_nums(char *lets)
{
	char	**full_str;
	int		spot;


	spot = 0;
	full_str = (char**)malloc(sizeof(char*) * get_word_count(lets));
	full_str = ft_split_whitespaces(lets);
	g_op = (char**)malloc(sizeof(char*) * (count_nums(lets) + 1));
	g_num = (int*)malloc(sizeof(int) * (count_ops(lets) + 1));
	g_nend = -1;
	g_oend = -1;
	full_str = first_pass(full_str);
	return (full_str);
}

char	**first_pass(char **str)
{
	int		i;
	int		hld;
	int		a;
	int		b;

	i = -1;
	while (str[++i] != 0)
	{
		if ((str[i][0] <= '9' && str[i][0] >= '0') && (str[i+2][0] <= '9' && 
			str[i+2][0] >= '0') &&	(OPS_CONDITIONS_B))
		{
			hld = parse_operator(str[i+1]);
			a = atoi(str[i]);
			b = atoi(str[i + 2]);
			str[i] = 0;
			str[i + 1] = 0;
			str[i + 2] = ft_putnbr(calculate(a, b , g_func_arr[hld].f));
			i++;
		}
	}
	str = removblank(str, i);
	return (str);
}

int		pre_calc(char **str)
{
	
	int		i;
	int		j;
	int		k;
	
	i = -1;
	j = -1;
	k = -1;
	while (str[++i])
	{
		printf("i: %d  %s\n", i, str[i]);
		if (str[i][0] == ')' || str[i+1] == 0)
		{
			pop();
			printf("after pop i: %d\n", i);
		}
		if (str[i][0] <= '9' && str[i][0] >= '0')	
		{	g_num[++g_nend] = atoi(str[i]);
			//printf("in nums i:%d, num:%c\n", i, str[i][0]);
		}
		if (OPS_CONDITIONS)
		{
			g_op[++g_oend] = str[i];
			//printf("in ops i:%d, op:%c\n", i, str[i][0]);
		}
	}
	return (0);
}

int		pop(void)
{
	int		hld;
	int		num1;
	int		num2;

	printf("pop start\n");
	while (ft_strcmp(g_op[g_oend], "(") && g_oend != 0)
	{
		hld = parse_operator(g_op[g_oend]);
		num1 = g_num[g_nend - 1];
		num2 = g_num[g_nend];
		g_nend  = g_nend - 1;
		printf("calculate %d %s %d\n", num1, g_func_arr[hld].op_nm, num2);
		g_num[g_nend] = calculate(num1, num2, g_func_arr[hld].f);
		g_op[g_oend] = "\0";
		g_oend--;
	}

	printf("pop end\n");
	return (0);
}

int		calculate(int arg1, int arg2, int (*f)(int, int))
{
	int ans;

	ans = f(arg1, arg2);
	printf("!answer %d\n", ans );
	return (ans);
}

int		parse_operator(char *op)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if ((ft_strcmp(op, g_func_arr[i].op_nm) == 0))
			break ;
		i++;
	}
	return (i);
}

void 	ft_putstr(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{	
		ft_putchar(str[index]);
		index++;
	}
}

char	*mystrcpy(char *str1, char *str2)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str1[i])
	{
		str2[j] = str1[i];
		if (str1[i] == '(' || str1[i + 1] == ')')
			str2[++j] = ' ';
		i++;
		j++;
	}
	str2[j] = '\0';
	return (str2);
}

int		eval_expr(char *argv)
{
	char	**spc_nums;
	char	*str_start;
	int		foo;

	printf("in the prog\n");
	str_start = (char*)malloc(sizeof(char) * len(argv) + paren_ct(argv));
	printf("malloced\n");
	str_start = mystrcpy(argv, str_start);
	printf("strcpy\n");
	spc_nums = parse_nums(str_start);
	printf("parsed\n");
	foo = pre_calc(spc_nums);

	// pre_calc(spc_nums);

	return (0);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	**removblank(char **str, int len)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (i < len+1)
	{
		while (str[++i] == 0)
		{
			j = i;
			while (str[j + 1] == 0)
				j++;
			str[i] = str[j];
		}
		i++;
	}
	return (str);	
}































