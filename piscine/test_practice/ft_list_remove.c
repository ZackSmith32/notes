void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp())
{
 	t_list	**holer;

 

	while (!cmp(begin_list->data, data))
	{
		*begin_list = begin_list->next;
	}
	holder_prev = *begin_list->next;
 	holder = *begin_list->next;
	while (holder)
	{
		if (!cmp(holder->data, data_ref))
		{
			holder_prev->next = holder->next;
		}
		holder_prev = holder;
		holder = holder->next;
	}




}