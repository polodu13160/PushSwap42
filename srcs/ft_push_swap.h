/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:27:27 by pauldepetri       #+#    #+#             */
/*   Updated: 2025/02/10 14:45:45 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "./printf42lyon/ft_printf.h"

typedef struct s_int_ext
{
	int		value;
	int		rank;
	int		asc_rank;
	int		desc_rank;
	int		rank_opt;
}			t_int_ext;
void		ft_rb(t_list **tab);
void		ft_sb(t_list **tab_b);
void		ft_rrb(t_list **tab);
void		ft_pa(t_list **tab_b, t_list **tab_a);
void		ft_pb(t_list **tab_a, t_list **tab_b);
void		ft_ra(t_list **tab);
void		ft_rra(t_list **tab);
void		ft_sa(t_list **tab_a);
t_int_ext	*ft_new_t_int(int value);
int			check_number(char *str);
int			create_node(char *value, t_list **tab_a);
int			check_duplicate_number(t_list **tab);
int			create_list(char **argv, t_list **tab_a);
void		ft_free_list(t_list **tab);

void		ft_free_tab(char **tab);
void		ft_rank(t_list **tab_a);
void		ft_rank_opt(t_list **tab_a);
void		ft_task(t_list **tab_a);
int			ft_run(t_list **tab, t_list **tab_dest, int chunk);
void		ft_analysis(t_list **tab, t_list **tab_dest, int init);
void		ft_push_b(t_list **tab_a, t_list **tab_b);
void		sort_small_value(t_list **tab_a);
void		ft_push_a(t_list **tab_a, t_list **tab_b);
int			ft_move_to_b(t_list *min_desc, t_list *min_asc, t_list **tab,
				t_list **tab_dest);
void		ft_move_to_a(t_list **tab_a, t_list **tab_b, int i, int swap_to_a);

#endif