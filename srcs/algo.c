/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:48:22 by pde-petr          #+#    #+#             */
/*   Updated: 2025/02/10 15:30:40 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

void	ft_analysis(t_list **tab, t_list **tab_dest, int init)
{
	static int	chunk;
	static int	size;
	int			stop;

	stop = 0;
	if (init == 0)
	{
		size = ft_lstsize(*tab);
		chunk = size / 4;
		ft_rank_opt(tab);
		init++;
	}
	ft_task(tab);
	if ((size - chunk) <= ft_lstsize(*tab))
	{
		stop = ft_run(tab, tab_dest, chunk);
		if (stop == 0)
			ft_analysis(tab, tab_dest, 1);
	}
}

void	ft_move_to_a(t_list **tab_a, t_list **tab_b, int i, int swap_to_a)
{
	while (1)
	{
		if (((t_int_ext *)(*tab_b)->content)->rank == swap_to_a)
		{
			ft_pa(tab_b, tab_a);
			break ;
		}
		else if (i == -1)
			ft_rb(tab_b);
		else
			ft_rrb(tab_b);
	}
}

void	ft_push_a(t_list **tab_a, t_list **tab_b)
{
	int		swap_to_a;
	int		i;
	t_list	*temp;

	i = 0;
	temp = (*tab_b);
	swap_to_a = ft_lstsize(*tab_b) - 1;
	if (swap_to_a == -1)
		return ;
	while (temp && ((t_int_ext *)temp->content)->rank != swap_to_a)
	{
		i++;
		temp = temp->next;
	}
	if (((swap_to_a + 1) % 2 == 0 && ((swap_to_a + 1) / 2) >= i) || ((swap_to_a
				+ 1) % 2 == 1 && ((swap_to_a + 1) / 2) > i))
		i = -1;
	ft_move_to_a(tab_a, tab_b, i, swap_to_a);
	if ((*tab_b) != NULL)
		ft_push_a(tab_a, tab_b);
}
