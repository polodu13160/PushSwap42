/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:23:43 by pde-petr          #+#    #+#             */
/*   Updated: 2025/02/07 19:03:50 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_rb(t_list **tab)
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
	ft_printf("%s", "rb\n");
}



void	ft_sb(t_list **tab_b)
{
	t_list	*temp;

	// t_list	*next;
	temp = *tab_b;
	*tab_b = (*tab_b)->next;
	temp->next = (*tab_b)->next;
	(*tab_b)->next = temp;
	ft_printf("%s", "sb\n");
}

void	ft_rrb(t_list **tab)
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
	ft_printf("%s", "rrb\n");
}
void	ft_pa(t_list **tab_b, t_list **tab_a)
{
	t_list	*temp;

	temp = *tab_b;
	*tab_b = (*tab_b)->next;
	temp->next = NULL;
	ft_lstadd_front(tab_a, temp);
	ft_printf("%s", "pa\n");
}
void	ft_pb(t_list **tab_a, t_list **tab_b)
{
	t_list	*temp;

	temp = *tab_a;
	*tab_a = (*tab_a)->next;
	temp->next = NULL;
    if (tab_b == NULL)
    {
        tab_b = malloc(sizeof(t_list *));
    }
	ft_lstadd_front(tab_b, temp);
	ft_printf("%s", "pb\n");
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
void	ft_sa(t_list **tab_a)
{
	t_list	*temp;

	// t_list	*next;
	temp = *tab_a;
	*tab_a = (*tab_a)->next;
	temp->next = (*tab_a)->next;
	(*tab_a)->next = temp;
	ft_printf("%s", "sa\n");
}