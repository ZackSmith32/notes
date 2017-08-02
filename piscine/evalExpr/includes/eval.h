/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalE.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 21:31:47 by zsmith            #+#    #+#             */
/*   Updated: 2016/07/30 21:31:49 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_H
# define EVAL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# define OPS_CONDITIONS	\
		(str[i][0] == '-' ||	\
		str[i][0] == '+' ||		\
		str[i][0] == '*' ||		\
		str[i][0] == '/' ||		\
		str[i][0] == '%' ||		\
		str[i][0] == '(')

# define OPS_CONDITIONS_B	\
		str[i + 1][0] == '*' ||		\
		str[i + 1][0] == '/' ||		\
		str[i + 1][0] == '%' ||		



int		g_ans;
char	**g_op;
int		*g_num;
int		g_nend;
int		g_oend;

char	**ft_split_whitespaces(char *str);
int		*make_array(char *char_nums);
void 	ft_putstr(char *str);
void	ft_putchar(char c);
char	*mystrcpy(char *str1, char *str2);
void	ft_putchar(char c);
char	*ft_putnbr(int n);
int		len(char *str);
int		paren_ct(char *str);
int		get_word_count(char *str);
int		get_arr_len(char **str);
int		calc(int *nums, char *ops);
int		ft_strcmp(char *s1, char *s2);
int		parse_operator(char *op);
int				ft_add(int a, int b);
int				ft_sub(int a, int b);
int				ft_mult(int a, int b);
int				ft_mod(int a, int b);
int				ft_div(int a, int b);
int		calculate(int arg1, int arg2, int (*f)(int, int));
int		pop(void);
char	**removblank(char **str, int len);
char	**first_pass(char **str);

typedef struct	s_operators
{
	char		*op_nm;
	int			(*f)(int, int);
}				t_ops;

#endif
