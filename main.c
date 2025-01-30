/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:20:39 by pauldepetri       #+#    #+#             */
/*   Updated: 2025/01/30 16:28:00 by pde-petr         ###   ########.fr       */
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



void	*ft_push(int **dest, int **src, char *instruction, int max_dest,
		int max_src)
{
	int	*malloc_int_dest;
	int	*malloc_int_src;
	int	i;

	i = 0;
	// printf("test %d\n", (*src)[0]);
	// printf("test %d\n", (*src)[1]);
	malloc_int_dest = ft_calloc(max_dest, sizeof(int));
	if (!malloc_int_dest)
		return (NULL);
	malloc_int_src = ft_calloc(max_src, sizeof(int));
	if (!malloc_int_src)
	{
		free(malloc_int_dest);
		return (NULL);
	}
	ft_printf("%s\n", instruction);
	i = 0;
	malloc_int_dest[i] = (*src)[i];
	while ((*src)[++i])
		malloc_int_src[i - 1] = (*src)[1];
	i = 0;
	while (*dest && (*dest)[i++])
		malloc_int_dest[i] = (*dest)[i - 1];
	// i = 0;
	*dest = malloc_int_dest;
	*src = malloc_int_src;
	return (malloc_int_dest);
}
int	*ft_rotate(int **tab, char *instruction, int max_tab)
{
	int	temp;

	ft_printf("%s\n", instruction);
	temp = (*tab)[max_tab - 1];
	(*tab)[max_tab - 1] = (*tab)[0];
	(*tab)[0] = temp;
	return (0);
}
// void	ft_ra(t_list ***tab_a, t_list *biggest_number)
// {
// }

// int	ft_pb(t_list ***tab_a, t_list *biggest_number, t_list ***tab_b)
// {
// }

// int	*ft_sort(t_list **tab_a, t_list **tab_b, int max_a)
// {
// 	t_list	*temp;
// 	int		i;
// 	t_list	*number_biggest;

// 	number_biggest = NULL;
// 	temp = *tab_a;
// 	while (temp)
// 	{
// 		if (i == 0)
// 		{
// 			ft_sa()
// 		}
// 		if (i == max_a - 2)
// 		{
// 		}
// 		if ((number_biggest == NULL)
// 			|| (number_biggest->content < temp->content))
// 		{
// 			number_biggest = temp;
// 		}
// 	}
// 	if (max_a - 1 > 0)
// 	{
// 		ft_ra(&tab_a, number_biggest);
// 		max_a = ft_pb(&tab_a, number_biggest, &tab_b);
// 	}
// 	return (ft_sort(tab_a, tab_b, max_a));
// 	return (0);
// }

void	ft_rank(t_list **tab_a)
{
	t_list	*temp;
	t_list	*temp_compare;
	int		rank;

	temp = *tab_a;
	while (temp)
	{
		temp_compare = *tab_a;
		rank = 1;
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
void	*ft_pb(t_list **tab_a, t_list **tab_b)
{
	t_list	*temp;

	temp = *tab_a;
	*tab_a = (*tab_a)->next;
	temp->next = NULL;
	ft_lstadd_front(tab_b, temp);
	ft_printf("%s", "pb\n");
}
void	*ft_sa(t_list **tab_a)
{
	t_list	*temp;

	// t_list	*next;
	temp = *tab_a;
	*tab_a = (*tab_a)->next;
	temp->next = (*tab_a)->next;
	(*tab_a)->next = temp;
	ft_printf("%s", "sa\n");
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

// void ft_rra(t_list **tab){

// 	t_list *penultimate;
// 	t_list *last_tab;
// 	last_tab = (*tab);
// 	t_list *temp;

// 	temp = *tab;

// 	while (last_tab->next != NULL)
//     {
//         penultimate = last_tab;
//         last_tab = last_tab->next;
//     }
// 	penultimate->next = NULL;
// 	last_tab->next = *tab;
// 	*tab = last_tab;

// 	ft_printf("%s", "rra\n");
// }

// else if (min_asc > min_desc)
// {
// }
// ft_sort(tab_a, tab_b, max_a);

// void	ft_analysis(t_list **tab_a, int max_a)
// {
	// ft_rank(tab_a);
	// if (middle == -1)
	// {
	// 	middle = max_a / 2;
	// }
	// min_desc = -1;
	// ft_task(tab_a);
	// temp = *tab_a;
	// // printf("%d \n", max_a / 2);
	// while (temp)
	// {
	// 	if (((t_int_ext *)temp->content)->rank <= middle)
	// 	{
	// 		if (min_desc == -1)
	// 		{
	// 			min_desc = ((t_int_ext *)temp->content)->desc_rank;
	// 			min_asc = ((t_int_ext *)temp->content)->asc_rank;
	// 		}
	// 		if (min_desc > ((t_int_ext *)temp->content)->desc_rank)
	// 			min_desc = ((t_int_ext *)temp->content)->desc_rank;
	// 		if (min_asc > ((t_int_ext *)temp->content)->asc_rank)
	// 			min_asc = ((t_int_ext *)temp->content)->desc_rank;
	// 	}
	// 	temp = temp->next;
	// }
// }
void	ft_init_tab_b(t_list tab_b, t_list tab_a)
{
}
int create_node(char *value, t_list **tab_a)
{
	int	error;
	int int_atoi;

	error = 0;
	int_atoi = ft_atoi(value, &error);
	if (error == -1)
		return (1);
	
	ft_lstadd_back(tab_a, ft_lstnew((void *)ft_new_t_int((int_atoi))));
	return 0;
}
void ft_free_tab(char **tab)
{
	int i;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
int  check_number(char *str)
{
	while (*str)
	{
		if ((*str == '-' ||  *str == '+')|| (*str >= '0' && *str <= '9'));
		else 
			return (1);
		str++;
	}
	return 0;
}
int check_duplicate_number(t_list **tab)
{
	t_list *start;
	t_list *temp;
	
	printf("123");
	start = *tab;

	while (*tab)
	{
		temp = start;
		while (temp)
		{
			if ((temp != *tab) && (((t_int_ext *)temp->content)->value) == ((t_int_ext *)(*tab)->content)->value)
			{
				ft_free_list(tab);
				return 1;
			}
			temp = temp->next;
		}
		*tab = (*tab)->next;
	}
	*tab = start;
	return 0;
}

int create_list(char **argv, t_list **tab_a)
{
	char **tab_split;
	tab_split = NULL;
	int i;
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
		return 1;
	return 0;
}


void ft_run(t_list **tab, t_list **tab_dest)
{
	
}
void ft_analysis(t_list **tab)
{
	ft_rank(tab);
	ft_task(tab);
	// ft_run(tab,);
}

int	main(int argc, char **argv)
{
	t_list **tab_a;
	// t_list **tab_b;
	char **tab;
	int max_a;
	t_list *current;
	t_int_ext *content;
	t_list *temp;

	// tab_b = malloc(sizeof(t_list **));
	tab_a = malloc(sizeof(t_list **));
	*tab_a = NULL;
	if (!tab_a)
		return (1);
	if (argc > 1)
	{
		if (create_list(++argv, tab_a) == 1)
		{
			ft_putendl_fd("Error \n", 2);
			return (1);
		}
		
			

		ft_analysis(tab_a);
		// ft_init_tab_b(tab_b, tab_a);

		current = *tab_a;

		while (current)
		{
			content = (t_int_ext *)current->content;
			printf("value : %d  ||  rank : %d  || task_desk : %d|| task_asc:% d \n ", content->value, content->rank, content->desc_rank,
				content->asc_rank);
			current = current->next;
		}

		while (*tab_a)
		{
			temp = *tab_a;
			*tab_a = (*tab_a)->next;
			free(temp->content);
			free(temp);
		}
		free(tab_a);
	}
	return (0);
}
