/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:27:27 by pauldepetri       #+#    #+#             */
/*   Updated: 2025/02/05 19:32:45 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP
# define FT_PUSH_SWAP

# include "printf42lyon/ft_printf.h"

typedef struct s_int_ext
{
	int				value;
	int				rank;
	int				asc_rank;
	int 			desc_rank;
	int				rank_opt;
}					t_int_ext;
typedef struct s_stock_int
{
	int				value;
	int				min_a;
	int				max_b;
	t_list			*temp_a;
	t_list			*temp_b;
	int				asc_tab_a;
	int				asc_tab_b;	
}					t_stock_int;


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