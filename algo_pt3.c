/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_pt3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:48:22 by pde-petr          #+#    #+#             */
/*   Updated: 2025/02/07 20:15:17 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


void search_min_desc_min_asc(t_list **tab, t_list *min_asc, t_list *min_esc)
{
	
}
int	ft_run(t_list **tab, t_list **tab_dest, int middle)
{
	t_list	*temp;
	t_list	*min_desc;
	t_list	*min_asc;

	temp = *tab;
	min_asc = NULL;
	min_desc = NULL;
	// while (temp)
	// {
	// 	if (((t_int_ext *)temp->content)->rank_opt <= middle)
	// 	{
	// 		if (min_desc == NULL
	// 			|| ((t_int_ext *)min_desc->content)->desc_rank > ((t_int_ext *)temp->content)->desc_rank)
	// 			min_desc = temp;
	// 		if (min_asc == NULL
	// 			|| ((t_int_ext *)min_asc->content)->asc_rank > ((t_int_ext *)temp->content)->asc_rank)
	// 			min_asc = temp;
	// 	}
	// 	temp = temp->next;
	// }
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


