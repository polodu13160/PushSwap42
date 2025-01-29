void	ft_analysis(t_list **tab_a, t_list **tab_b, int max_a)
{
	
	t_list	*temp;
	t_list	*temp_compare;
	int		min_desc;
	int		min_asc;
	static int middle = -1;

	if (middle == -1)
	{
		middle = max_a / 2;
		ft_rank(tab_a);
	}
	min_desc = -1;
	ft_task(tab_a);
	temp = *tab_a;
	// printf("%d \n", max_a / 2);
	while (temp)
	{
		if (((t_int_ext *)temp->content)->rank <= middle)
		{
			if (min_desc == -1)
			{
				min_desc = ((t_int_ext *)temp->content)->desc_rank;
				min_asc = ((t_int_ext *)temp->content)->asc_rank;
			}
			if (min_desc > ((t_int_ext *)temp->content)->desc_rank)
				min_desc = ((t_int_ext *)temp->content)->desc_rank;
			if (min_asc > ((t_int_ext *)temp->content)->asc_rank)
				min_asc = ((t_int_ext *)temp->content)->desc_rank;
		}
		temp = temp->next;
	}
	printf("min_ask :%d  min desk : %d\n", min_asc, min_desc);
	if (min_desc == -1)
	{
		ft_rank(tab_b);
		ft_task(tab_b);

		t_list *current = *tab_b;

		while (current)
		{
			t_int_ext *content = (t_int_ext *)current->content;
			printf("value : %d  ||  rank : %d  || task_desk : %d|| task_asc: % d \n ", content->value, content->rank, content->desc_rank,
					content->asc_rank);
			current = current->next;
		}
		
	}
	else if (min_desc == 0 || min_asc == 0)
	{
		ft_pb(tab_a, tab_b);
		max_a--;
		ft_analysis(tab_a, tab_b, max_a);
	}
	else if ((*tab_a)->next != NULL && middle <= max_a )
	{
		if (((t_int_ext *)(*tab_a)->content)->rank > ((t_int_ext *)(*tab_a)->next->content)->rank)
		{
			// ft_sa(tab_a);
			ft_sa(tab_a);
			// ft_ra(tab_a);
		}
		else if ((min_desc > min_asc))
			ft_ra(tab_a);
		else 
			ft_rra(tab_a);
		// ft_analysis(tab_a, tab_b, max_a);
	}

}






visualiseur et perplexity 
	
