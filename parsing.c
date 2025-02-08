/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:27:06 by pde-petr          #+#    #+#             */
/*   Updated: 2025/02/08 17:59:35 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

int	create_node(char *value, t_list **tab_a)
{
	int	error;
	int	int_atoi;

	error = 0;
	int_atoi = ft_atoi(value, &error);
	if (error == -1)
		return (1);
	if (*tab_a == NULL)
	{
		(*tab_a) = ft_lstnew((ft_new_t_int((int_atoi))));
	}
	else
		ft_lstadd_back(tab_a, ft_lstnew(ft_new_t_int((int_atoi))));
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
			if ((temp != *tab) \
			&& (((t_int_ext *)temp->content)->value == \
			((t_int_ext *)(*tab)->content)->value))
			{
				*tab = start;
				ft_free_list(tab);
				return (-1);
			}
			temp = temp->next;
		}
		*tab = (*tab)->next;
	}
	*tab = start;
	return (0);
}
