/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:20:39 by pauldepetri       #+#    #+#             */
/*   Updated: 2025/02/05 20:34:04 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_rank(t_list **tab_a)
{
	t_list	*temp;
	t_list	*temp_compare;
	int		rank;

	temp = *tab_a;
	while (temp)
	{
		temp_compare = *tab_a;
		rank = 0;
		while (temp_compare)
		{
			if (((t_int_ext *)temp->content)->value > ((t_int_ext *)temp_compare->content)->value)
				rank++;
			temp_compare = temp_compare->next;
		}
		((t_int_ext *)temp->content)->rank = rank;
		temp = temp->next;
	}
}

void	ft_rank_opt(t_list **tab_a)
{
	t_list	*temp;
	t_list	*temp_compare;
	int		rank;

	temp = *tab_a;
	while (temp)
	{
		temp_compare = *tab_a;
		rank = 0;
		while (temp_compare)
		{
			if (((t_int_ext *)temp->content)->value > ((t_int_ext *)temp_compare->content)->value)
				rank++;
			temp_compare = temp_compare->next;
		}
		((t_int_ext *)temp->content)->rank_opt = rank;
		temp = temp->next;
	}
}

t_int_ext	*ft_new_t_int(int value)
{
	t_int_ext	*list;

	list = malloc(sizeof(t_int_ext));
	if (list == NULL)
		return (NULL);
	list->value = value;
	list->asc_rank = -1;
	list->desc_rank = -1;
	list->rank = -1;
	return (list);
}

void	ft_free_list(t_list **tab)
{
	t_list	*temp;

	while (*tab)
	{
		temp = *tab;
		*tab = (*tab)->next;
		free(temp->content);
		free(temp);
	}
	free(tab);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || ((i == 0) && (str[i] == '-'
						|| str[i] == '+'))))
			return (1);
		i++;
	}
	if (i == 1 && ((str[i - 1] == '-' || str[i - 1] == '+')))
		return (1);
	return (0);
}
int	check_duplicate_number(t_list **tab)
{
	t_list	*start;
	t_list	*temp;

	start = *tab;
	while (*tab)
	{
		temp = start;
		while (temp)
		{
			if ((temp != *tab)
				&& (((t_int_ext *)temp->content)->value) == ((t_int_ext *)(*tab)->content)->value)
			{
				ft_free_list(tab);
				return (1);
			}
			temp = temp->next;
		}
		*tab = (*tab)->next;
	}
	*tab = start;
	return (0);
}

int	create_node(char *value, t_list **tab_a)
{
	int	error;
	int	int_atoi;

	error = 0;
	int_atoi = ft_atoi(value, &error);
	if (error == -1)
		return (1);
	ft_lstadd_back(tab_a, ft_lstnew((void *)ft_new_t_int((int_atoi))));
	return (0);
}

int	create_list(char **argv, t_list **tab_a)
{
	char	**tab_split;
	int		i;

	tab_split = NULL;
	while (*argv)
	{
		i = 0;
		tab_split = ft_split(*argv, ' ');
		while (tab_split[i])
		{
			if (check_number(tab_split[i]) == 1)
			{
				ft_free_tab(tab_split);
				ft_free_list(tab_a);
				return (1);
			}
			if (create_node(tab_split[i], tab_a) == 1)
			{
				ft_free_tab(tab_split);
				ft_free_list(tab_a);
				return (1);
			};
			i++;
		}
		ft_free_tab(tab_split);
		argv++;
	}
	if (check_duplicate_number(tab_a) == 1)
		return (-1);
	return (0);
}

void	ft_rb(t_list **tab)
{
	t_list	*temp;
	t_list	*one_for_list;

	one_for_list = (*tab);
	temp = (*tab);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	*tab = (*tab)->next;
	one_for_list->next = NULL;
	temp->next = one_for_list;
	ft_printf("%s", "rb\n");
}



void	*ft_sb(t_list **tab_b)
{
	t_list	*temp;

	// t_list	*next;
	temp = *tab_b;
	*tab_b = (*tab_b)->next;
	temp->next = (*tab_b)->next;
	(*tab_b)->next = temp;
	ft_printf("%s", "sb\n");
}

void	ft_rrb(t_list **tab)
{
	t_list	*penultimate;
	t_list	*last_tab;

	last_tab = (*tab);
	while (last_tab->next != NULL)
	{
		penultimate = last_tab;
		last_tab = last_tab->next;
	}
	penultimate->next = NULL;
	last_tab->next = *tab;
	*tab = last_tab;
	ft_printf("%s", "rrb\n");
}
void	ft_pa(t_list **tab_b, t_list **tab_a)
{
	t_list	*temp;

	temp = *tab_b;
	*tab_b = (*tab_b)->next;
	temp->next = NULL;
	ft_lstadd_front(tab_a, temp);
	ft_printf("%s", "pa\n");
}
void	ft_pb(t_list **tab_a, t_list **tab_b)
{
	t_list	*temp;

	temp = *tab_a;
	*tab_a = (*tab_a)->next;
	temp->next = NULL;
	ft_lstadd_front(tab_b, temp);
	ft_printf("%s", "pb\n");
}

void	ft_ra(t_list **tab)
{
	t_list	*temp;
	t_list	*one_for_list;

	one_for_list = (*tab);
	temp = (*tab);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	*tab = (*tab)->next;
	one_for_list->next = NULL;
	temp->next = one_for_list;
	ft_printf("%s", "ra\n");
}

void	ft_rra(t_list **tab)
{
	t_list	*penultimate;
	t_list	*last_tab;

	last_tab = (*tab);
	while (last_tab->next != NULL)
	{
		penultimate = last_tab;
		last_tab = last_tab->next;
	}
	penultimate->next = NULL;
	last_tab->next = *tab;
	*tab = last_tab;
	ft_printf("%s", "rra\n");
}

void	ft_push_b(t_list **tab_a, t_list **tab_b)
{
	while (*tab_a)
	{
		// if (((t_int_ext *)(*tab_a)->content)->rank == 0)
		// {
		// 	break;
		// }
		
		
		if ((*tab_b) == NULL)
		{
			ft_pb(tab_a, tab_b);
		}
		else if (ft_lstsize(*tab_b) == 1)
		{
			if (((t_int_ext *)(*tab_a)->content)->rank < ((t_int_ext *)(*tab_b)->content)->rank)
			{
				// ft_pb(tab_a, tab_b);
				ft_rb(tab_b);
			}
			else 
				ft_pb(tab_a, tab_b);
		}
		else if (((t_int_ext *)(*tab_a)->content)->rank > ((t_int_ext *)(*tab_b)->content)->rank)
		{
			ft_pb(tab_a, tab_b);
		}
		else if (((t_int_ext *)(*tab_a)->content)->rank < ((t_int_ext *)(*tab_b)->content)->rank)
		{
			if (((t_int_ext *)(*tab_a)->content)->rank < ((t_int_ext *)(ft_lstlast(*tab_b)->content))->rank)
			{
				// ft_pb(tab_a, tab_b);
				ft_rb(tab_b);
			}
			else
			{
				ft_rrb(tab_b);
				// ft_pb(tab_a, tab_b);
				// ft_rb(tab_b);
			}
		}
		else if (((t_int_ext *)(*tab_a)->content)->rank > ((t_int_ext *)(*tab_b)->content)->rank)
			ft_pb(tab_a, tab_b);
		
	}
}


void ft_push_a(t_list **tab_a, t_list **tab_b)
{
	int swap_to_a;
	int i;
	int tt;
	t_list *temp;
	t_int_ext	*content;
	
	i = 0;
	


	temp = (*tab_b);
	swap_to_a = ft_lstsize(*tab_b) - 1;
	if (swap_to_a == -1)
		return ;


	// while (temp)
	// 	{
	// 		content = (t_int_ext *)temp->content;
	// 		printf("value : %d  ||  rank : %d  || task_desk : \
	// 			%d|| task_asc:% d \n ",
	// 				content->value,
	// 				content->rank,
	// 				content->desc_rank,
	// 				content->asc_rank);
	// 		temp = temp->next;
	// 	}
	// 	temp = (*tab_b);
	
	
	




	while (temp && ((t_int_ext*)temp->content)->rank != swap_to_a)
	{
		i++;
		temp = temp->next;
	}
	
	
	if (((swap_to_a + 1) % 2 == 0 && ((swap_to_a + 1) / 2) >= i) || ((swap_to_a +1) % 2 == 1 && ((swap_to_a + 1) / 2) > i))
		i = -1;
	
	// printf("swaptoa = %d, rank = %d ", swap_to_a, ((t_int_ext *)(*tab_b)->content)->rank);
	while (1)
	{
		if (((t_int_ext *)(*tab_b)->content)->rank == swap_to_a)
		{
			ft_pa(tab_b,tab_a);
			break;
		}
		else if (i == -1)
			ft_rb(tab_b);
		else 
			ft_rrb(tab_b);
	}
	
		
	if ((*tab_b) != NULL)
		ft_push_a(tab_a, tab_b);
}


void	ft_task(t_list **tab_a)
{
	t_list	*temp;
	int		i;
	int		j;

	i = 0;
	temp = *tab_a;
	while (temp)
	{
		((t_int_ext *)temp->content)->desc_rank = i;
		temp = temp->next;
		i++;
	}
	temp = *tab_a;
	j = 0;
	while (temp)
	{
		if (j == 0)
			((t_int_ext *)temp->content)->asc_rank = j++;
		else
			((t_int_ext *)temp->content)->asc_rank = --i;
		temp = temp->next;
	}
}

void	ft_run(t_list **tab, t_list **tab_dest, int middle)
{
	t_list	*temp;
	t_list	*min_desc;
	t_list	*min_asc;

	temp = *tab;
	min_asc = NULL;
	min_desc = NULL;
	while (temp)
	{
		if (((t_int_ext *)temp->content)->rank_opt < middle)
		{
			if (min_desc == NULL
				|| ((t_int_ext *)min_desc->content)->desc_rank > ((t_int_ext *)temp->content)->desc_rank)
				min_desc = temp;
			if (min_asc == NULL
				|| ((t_int_ext *)min_asc->content)->asc_rank > ((t_int_ext *)temp->content)->asc_rank)
				min_asc = temp;
		}
		temp = temp->next;
	}
	// printf("middle = %d min desc : %d, min asc : %d\n", middle,
	// 	((t_int_ext *)min_desc->content)->desc_rank,
	// 	((t_int_ext *)min_asc->content)->asc_rank);
	if (min_desc != NULL && (((t_int_ext *)min_asc->content)->asc_rank == 0
			|| ((t_int_ext *)min_desc->content)->desc_rank == 0))
{
	ft_pb(tab, tab_dest);
	return ;
}
		
	else if (min_desc != NULL)
	{
		if (((t_int_ext *)min_asc->content)->asc_rank == ((t_int_ext *)min_desc->content)->desc_rank)
		{
			if (((t_int_ext *)min_asc->content)->rank > ((t_int_ext *)min_desc->content)->rank)
				ft_rra(tab);
			else
				ft_ra(tab);
		}
		else if (((t_int_ext *)min_asc->content)->asc_rank > ((t_int_ext *)min_desc->content)->desc_rank)
			ft_ra(tab);
		else if (((t_int_ext *)min_asc->content)->asc_rank < ((t_int_ext *)min_desc->content)->desc_rank)
			ft_rra(tab);
	}
	ft_run(tab, tab_dest, middle);
	
}



int	ft_analysis(t_list **tab, t_list **tab_dest, int init)
{
	
	static int	middle;
	static int size;
	// static int	action = 4;

	if (init == 0)
	{
		size = ft_lstsize(*tab);
		middle = size/2;
		if (ft_lstsize(*tab) % 2 == 1)
			middle++;
		
		ft_rank_opt(tab);
		init++;
	}
	ft_task(tab);
	
	if (middle < ft_lstsize(*tab))
	{
		// printf("%d, %d\n", middle, ft_lstsize(*tab));
		if (size % 2 == 1)
			ft_run(tab, tab_dest, middle - 1);
		else 
			ft_run(tab, tab_dest, middle );
		// action--;
		// printf("action : %d\n", action);
		ft_analysis(tab, tab_dest, 1);
	}
}


int	main(int argc, char **argv)
{
	t_list		**tab_a;
	t_list		**tab_b;
	char		**tab;
	int			max_a;
	t_list		*current;
	t_int_ext	*content;
	t_list		*temp;
	

	tab_b = malloc(sizeof(t_list *));
	tab_a = malloc(sizeof(t_list *));
	*tab_a = NULL;
	*tab_b = NULL;
	if (!tab_a)
		return (1);
	if (argc > 1)
	{
		if (create_list(++argv, tab_a) == -1)
		{
			ft_putendl_fd("Error \n", 2);
			return (1);
		}
		// ft_rank(tab_a);
		
		// ft_analysis(tab_a,tab_b, 0);
		
		
		
		
		// ft_push_b(tab_a, tab_b);
		// ft_push_a(tab_a, tab_b);
		// current = *tab_a;
		// // while (current)
		// // {
		// // 	content = (t_int_ext *)current->content;
		// // 	printf("value : %d  ||  rank : %d  || task_desk : \
		// // 		%d|| task_asc:% d \n ",
		// // 			content->value,
		// // 			content->rank,
		// // 			content->desc_rank,
		// // 			content->asc_rank);
		// // 	current = current->next;
		// // }
		while (*tab_a)
		{
			temp = *tab_a;
			*tab_a = (*tab_a)->next;
			free(temp->content);
			free(temp);
		}
		free(tab_a);
		current = *tab_b;
		while (*tab_b)
		{
			temp = *tab_b;
			*tab_b = (*tab_b)->next;
			free(temp->content);
			free(temp);
		}
		free(tab_b);
	}
	return (0);
}
