/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldepetrini <pauldepetrini@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:27:27 by pauldepetri       #+#    #+#             */
/*   Updated: 2024/12/23 00:57:12 by pauldepetri      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP
# define FT_PUSH_SWAP

# include "printf42lyon/ft_printf.h"

typedef struct s_int
{
	int				value;
	char			*content;

	struct s_int	*next;
}					t_int;
int					ft_check_tab(char **tab);

void				ft_full_swap(int **tab_a, int *tab_b);
int					*ft_swap(int **tab, char *instruction);

void				ft_full_push(int **tab_a, int *tab_b);
void	*ft_push(int **dest, int **src, char *instruction, int max_dest,
		int max_src);

	void ft_full_rotate(int **tab_a, int **tab_b);
int					*ft_rotate(int **tab, char *instruction, int max_tab);

void				ft_full_reverse_rotate(int **tab_a, int **tab_b);
int					*ft_reverse_rotate(int **tab, char *instruction);

#endif