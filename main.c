/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldepetrini <pauldepetrini@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:20:39 by pauldepetri       #+#    #+#             */
/*   Updated: 2024/12/23 01:04:06 by pauldepetri      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	check_and_count_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!ft_check_number(tab[i]))
		{
			ft_putendl_fd("Error\n", 2);
			return (-1);
		}
		i++;
	}
	return (i);
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

int	*ft_sort(int *tab_a, int *tab_b, int max_b, int max_a)
{
	if (tab_a[0] > tab_a[1])
	{
		// ft_printf("tab a %d, %d \n", tab_a[0], tab_a[1]);
		max_b++;
		max_a--;
		ft_push(&tab_b, &tab_a, "pb", max_b, max_a);
	}
	if (max_b > 2)
	{
		if (tab_b[0] > tab_b[1])
			ft_rotate(&tab_b, "rb", max_b);
	}
	return (0);
	// return (ft_sort(tab_a, tab_b, max_b, max_a));
}

#include "ft_push_swap.h"

// t_int	*create_list(t_int **list, t_int *tab_a)
// {
// 	*list = malloc(sizeof(t_int));
// 	if (!*list)
// 	{
// 		*list = tab_a;
// 		while (tab_a)
// 		{
// 			*list = tab_a->next;
// 			free(tab_a);
// 			tab_a = *list;
// 		}
// 		return (NULL);
// 	}
// 	return (*list);
// }

// t_int	*create_chain_list(char **argv, t_int *tab_a)
// {
// 	int		i;
// 	t_int	*temp;

// 	i = 0;
// 	while (*argv)
// 	{
// 		if (i++ == 0)
// 		{
// 			tab_a = malloc(sizeof(t_int));
// 			temp = tab_a;
// 		}
// 		else
// 		{
// 			temp = create_list(&temp->next, tab_a);
// 		}
// 		if (!temp)
// 			return (NULL);
// 		temp->content = *argv;
// 		temp->value = ft_atoi(*argv++);
// 		temp->next = NULL;
// 	}
// 	return (tab_a);
// }

int	main(int argc, char **argv)
{
	int	*tab_a;
	int	max_a;
	int	*tab_b;

	tab_b = NULL;
	if (argc > 1)
	{
		max_a = check_and_count_tab(++argv);
		if (max_a == -1)
			return (1);
		tab_a = ft_calloc(max_a, sizeof(int));
		if (!tab_a)
			return (1);
		max_a = 0;
		while (*argv)
			tab_a[max_a++] = ft_atoi(*argv++);
		tab_b = ft_sort(tab_a, tab_b, 1, max_a);
		free(tab_a);
	}
	return (0);
}
