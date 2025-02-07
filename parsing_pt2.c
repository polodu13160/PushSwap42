/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pt2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:27:06 by pde-petr          #+#    #+#             */
/*   Updated: 2025/02/07 20:06:27 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	parse_list(int i, char **tab_split, char **argv, t_list **tab_a)
{
	while (*argv)
	{
		i = 0;
		tab_split = ft_split(*argv, ' ');
		if (tab_split == NULL)
			return (1);
		while (tab_split[i])
		{
			if (check_number(tab_split[i]) == 1)
			{
				ft_free_tab(tab_split);
				ft_free_list(tab_a);
				return (-1);
			}
			if (create_node(tab_split[i], tab_a) == 1)
			{
				ft_free_tab(tab_split);
				ft_free_list(tab_a);
				return (-1);
			};
			i++;
		}
		ft_free_tab(tab_split);
		argv++;
	}
	return (0);
}

int	create_list(char **argv, t_list **tab_a)
{
	char	**tab_split;
	int		i;

	i = 0;
	tab_split = NULL;
	if (parse_list(i, tab_split, argv, tab_a) == -1)
		return (-1);
	if (check_duplicate_number(tab_a) == -1)
		return (-1);
	return (0);
}
