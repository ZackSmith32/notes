// int		*make_array(char *char_nums)
// {
// 	int		*num_arr;
// 	// char	**holder;
// 	char	**char_num_cpy;
// 	int		i;

// 	i = 0;
// 	num_arr = (int*)malloc(sizeof(int) * 9);
// 	char_num_cpy = ft_split_whitespaces(char_nums);
// 	while (char_num_cpy[i] != 0)
// 	{
// 		ft_putstr(char_num_cpy[i]);
// 		ft_putchar(' ');
// 		num_arr[i] = atoi(char_num_cpy[i]);
// 		i++;
// 	}
// 	num_arr[i] = '\0';
// 	return (num_arr);
// }