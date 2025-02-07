/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:20:39 by pauldepetri       #+#    #+#             */
/*   Updated: 2025/02/07 19:54:14 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"











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


int	main(int argc, char **argv)
{
	t_list		*tab_a;
	t_list		*tab_b;
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
			ft_analysis(&tab_a,&tab_b, 0);
		}
		sort_small_value(&tab_a);
		ft_push_a(&tab_a, &tab_b);

		ft_free_list(&tab_a);
		ft_free_list(&tab_b);
	}
	return (0);
}
