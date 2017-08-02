typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;


void	ft_list_forezach(t_list *begin_list, void (*f)(void *))
{
	t_list		*holder

	holder = f;
	while (holder->data != null)
	{
		f(holder->data)
		holder = holder->next;
	}



}