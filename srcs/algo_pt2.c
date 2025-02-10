/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_pt2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:48:22 by pde-petr          #+#    #+#             */
/*   Updated: 2025/02/10 15:18:20 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_push_b(t_list **tab_a, t_list **tab_b)
{
	t_int_ext	*content_a;

	content_a = ((t_int_ext *)(*tab_a)->content);
	if ((*tab_b) == NULL)
		ft_pb(tab_a, tab_b);
	else if (ft_lstsize(*tab_b) == 1)
	{
		if (content_a->rank < ((t_int_ext *)(*tab_b)->content)->rank)
			ft_pb(tab_a, tab_b);
		else
		{
			ft_pb(tab_a, tab_b);
			ft_rb(tab_b);
		}
	}
	else if (content_a->rank < ((t_int_ext *)(*tab_b)->content)->rank)
		ft_pb(tab_a, tab_b);
	else if (content_a->rank > ((t_int_ext *)(*tab_b)->content)->rank)
	{
		ft_pb(tab_a, tab_b);
		if (content_a->rank > \
		((t_int_ext *)(ft_lstlast(*tab_b)->content))->rank)
			ft_rb(tab_b);
	}
}

int	ft_move_to_b(t_list *min_desc, t_list *min_asc, t_list **tab,
		t_list **tab_dest)
{
	if (min_desc != NULL && *tab != NULL)
	{
		if ((((t_int_ext *)min_asc->content)->asc_rank == 0
				|| ((t_int_ext *)min_desc->content)->desc_rank == 0))
			ft_push_b(tab, tab_dest);
		else if (((t_int_ext *)min_asc->content)->asc_rank == \
		((t_int_ext *)min_desc->content)->desc_rank)
		{
			if (((t_int_ext *)min_asc->content)->rank_opt > \
			((t_int_ext *)min_desc->content)->rank_opt)
				ft_rra(tab);
			else
				ft_ra(tab);
		}
		else if (((t_int_ext *)min_asc->content)->asc_rank > \
		((t_int_ext *)min_desc->content)->desc_rank)
			ft_ra(tab);
		else if (((t_int_ext *)min_asc->content)->asc_rank < \
		((t_int_ext *)min_desc->content)->desc_rank)
			ft_rra(tab);
		return (0);
	}
	return (1);
}

int	ft_run(t_list **tab, t_list **tab_dest, int chunk)
{
	t_list	*temp;
	t_list	*min_desc;
	t_list	*min_asc;

	temp = *tab;
	min_asc = NULL;
	min_desc = NULL;
	while (temp)
	{
		if (((t_int_ext *)temp->content)->rank_opt <= chunk)
		{
			if (min_desc == NULL
				|| ((t_int_ext *)min_desc->content)->desc_rank > \
				((t_int_ext *)temp->content)->desc_rank)
				min_desc = temp;
			if (min_asc == NULL
				|| ((t_int_ext *)min_asc->content)->asc_rank > \
				((t_int_ext *)temp->content)->asc_rank)
				min_asc = temp;
		}
		temp = temp->next;
	}
	if (ft_move_to_b(min_desc, min_asc, tab, tab_dest) == 0)
		return (0);
	return (1);
}
