/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:20:39 by pauldepetri       #+#    #+#             */
/*   Updated: 2025/02/06 17:47:14 by pde-petr         ###   ########.fr       */
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
			if ((temp != *tab)
				&& ((t_int_ext *)temp->content)->value == ((t_int_ext *)(*tab)->content)->value)
			{
				*tab = start;
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


int	create_list(char **argv, t_list **tab_a)
{
	char	**tab_split;
	int		i;

	tab_split = NULL;
	while (*argv)
	{
		i = 0;
		tab_split = ft_split(*argv, ' ');
		if (tab_split == NULL)
			return 1;
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
	if (check_duplicate_number(tab_a) == 1)
			return (-1);
	return (0);
}


int	main(int argc, char **argv)
{
	t_list		*tab_a;
	t_int_ext	*content;
	t_list		*temp;
	

	// tab_b = malloc(sizeof(t_list *));
	// tab_a = malloc(sizeof(t_list *));
	tab_a = NULL;
	
	if (argc > 1)
	{
		if (create_list(++argv, &tab_a) == -1)
		{
			ft_putendl_fd("Error \n", 1);
			return (1);
		}
		
		printf("dd");
		
		
		
	
		while (tab_a)
		{
			content = (t_int_ext *)tab_a->content;
				printf("value : %d  ||  rank : %d  || task_desk : \
		// // 		%d|| task_asc:% d \n ",
					content->value,
					content->rank,
					content->desc_rank,
					content->asc_rank);
			temp = tab_a;
			tab_a = tab_a->next;
			free(temp->content);
			free(temp);
		}
		free(tab_a);
		
		// while (tab_b)
		// {
		// 	temp = tab_b;
		// 	tab_b = tab_b->next;
		// 	free(temp->content);
		// 	free(temp);
		// }
		// free(tab_b);
	}
	return (0);
}
