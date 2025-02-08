/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:20:39 by pauldepetri       #+#    #+#             */
/*   Updated: 2025/02/08 18:08:17 by pde-petr         ###   ########.fr       */
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
			if (((t_int_ext *)temp->content)->value > \
			((t_int_ext *)temp_compare->content)->value)
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
			if (((t_int_ext *)temp->content)->value > \
			((t_int_ext *)temp_compare->content)->value)
				rank++;
			temp_compare = temp_compare->next;
		}
		((t_int_ext *)temp->content)->rank_opt = rank;
		temp = temp->next;
	}
}

void	sort_small_value(t_list **tab_a)
{
	int		i;
	t_list	*temp;

	i = 0;
	ft_rank_opt(tab_a);
	temp = (*tab_a);
	temp = *tab_a;
	while (temp && ((t_int_ext *)temp->content)->rank_opt == i++)
	{
		temp = temp->next;
	}
	if (i == ft_lstsize(*tab_a))
		return ;
	else if (((t_int_ext *)(*tab_a)->content)->rank_opt > \
	((t_int_ext *)(*tab_a)->next->content)->rank_opt)
	{
		if (((t_int_ext *)(*tab_a)->content)->rank_opt < \
		((t_int_ext *)(ft_lstlast(*tab_a)->content))->rank_opt)
			ft_sa(tab_a);
		else
			ft_ra(tab_a);
	}
	else
		ft_rra(tab_a);
	return (sort_small_value(tab_a));
}

int	main(int argc, char **argv)
{
	t_list	*tab_a;
	t_list	*tab_b;

	tab_a = NULL;
	tab_b = NULL;
	if (argc > 1)
	{
		if (create_list(++argv, &tab_a) == -1)
		{
			ft_putendl_fd("Error \n", 2);
			return (1);
		}
		ft_rank(&tab_a);
		while (ft_lstsize(tab_a) > 3)
		{
			ft_analysis(&tab_a, &tab_b, 0);
		}
		sort_small_value(&tab_a);
		ft_push_a(&tab_a, &tab_b);
		ft_free_list(&tab_a);
		ft_free_list(&tab_b);
	}
	return (0);
}
