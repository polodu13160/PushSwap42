/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:00:24 by pde-petr          #+#    #+#             */
/*   Updated: 2024/12/09 16:33:40 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(unsigned long int hexa, char type)
{
	char	*hexa_tab;

	if (type == 'x')
		hexa_tab = HEXAMIN;
	else
		hexa_tab = HEXACAPS;
	if (hexa < 16)
		return (write(1, &hexa_tab[hexa], 1));
	else
		return (ft_printhexa(hexa / 16, type) + write(1, &hexa_tab[hexa % 16],
				1));
}
