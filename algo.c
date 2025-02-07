/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:48:22 by pde-petr          #+#    #+#             */
/*   Updated: 2025/02/07 19:48:19 by pde-petr         ###   ########.fr       */
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

void	ft_push_b(t_list **tab_a, t_list **tab_b)
{
	if ((*tab_b) == NULL)
		ft_pb(tab_a, tab_b);
	else if (ft_lstsize(*tab_b) == 1)
	{
		if (((t_int_ext *)(*tab_a)->content)->rank < ((t_int_ext *)(*tab_b)->content)->rank)
			ft_pb(tab_a, tab_b);
		else
		{
			ft_pb(tab_a, tab_b);
			ft_rb(tab_b);
		}
	}
	else if (((t_int_ext *)(*tab_a)->content)->rank < ((t_int_ext *)(*tab_b)->content)->rank)
		ft_pb(tab_a, tab_b);
	else if (((t_int_ext *)(*tab_a)->content)->rank > ((t_int_ext *)(*tab_b)->content)->rank)
	{
		if (((t_int_ext *)(*tab_a)->content)->rank > ((t_int_ext *)(ft_lstlast(*tab_b)->content))->rank)
		{
			ft_pb(tab_a, tab_b);
			ft_rb(tab_b);
		}
		else
			ft_pb(tab_a, tab_b);
	}
}

int	ft_run(t_list **tab, t_list **tab_dest, int middle)
{
	t_list	*temp;
	t_list	*min_desc;
	t_list	*min_asc;

	temp = *tab;
	min_asc = NULL;
	min_desc = NULL;
	while (temp)
	{
		if (((t_int_ext *)temp->content)->rank_opt <= middle)
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
	if (min_desc != NULL && (((t_int_ext *)min_asc->content)->asc_rank == 0
			|| ((t_int_ext *)min_desc->content)->desc_rank == 0))
	{
		ft_push_b(tab, tab_dest);
		return (0);
	}
	else if (min_desc != NULL)
	{
		if (((t_int_ext *)min_asc->content)->asc_rank == ((t_int_ext *)min_desc->content)->desc_rank)
		{
			if (((t_int_ext *)min_asc->content)->rank_opt > ((t_int_ext *)min_desc->content)->rank_opt)
				ft_rra(tab);
			else
				ft_ra(tab);
		}
		else if (((t_int_ext *)min_asc->content)->asc_rank > ((t_int_ext *)min_desc->content)->desc_rank)
			ft_ra(tab);
		else if (((t_int_ext *)min_asc->content)->asc_rank < ((t_int_ext *)min_desc->content)->desc_rank)
			ft_rra(tab);
		return (0);
	}
	return (1);
}

void	ft_analysis(t_list **tab, t_list **tab_dest, int init)
{
	static int	middle;
	static int	size;
	int			stop;

	stop = 0;
	if (init == 0)
	{
		size = ft_lstsize(*tab);
		middle = size / 2 / 2;
		ft_rank_opt(tab);
		init++;
	}
	ft_task(tab);
	if ((ft_lstsize(*tab) - middle) < ft_lstsize(*tab))
	{
		stop = ft_run(tab, tab_dest, middle);
		if (stop == 0)
			ft_analysis(tab, tab_dest, 1);
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
	while (temp && ((t_int_ext *)temp->content)->rank_opt == i)
	{
		i++;
		temp = temp->next;
	}
	if (i == ft_lstsize(*tab_a))
		return ;
	else if (((t_int_ext *)(*tab_a)->content)->rank_opt > ((t_int_ext *)(*tab_a)->next->content)->rank_opt)
	{
		if (((t_int_ext *)(*tab_a)->content)->rank_opt < ((t_int_ext *)(ft_lstlast(*tab_a)->content))->rank_opt)
			ft_sa(tab_a);
		else
			ft_ra(tab_a);
	}
	else
		ft_rra(tab_a);
	return (sort_small_value(tab_a));
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
	if ((*tab_b) != NULL)
		ft_push_a(tab_a, tab_b);
}
