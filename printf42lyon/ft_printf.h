/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-petr <pde-petr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:08:43 by pde-petr          #+#    #+#             */
/*   Updated: 2024/12/03 18:50:43 by pde-petr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft_updated/libft.h"
# include <stdarg.h>

# define HEXACAPS "0123456789ABCDEF"
# define HEXAMIN "0123456789abcdef"

int	ft_printhexa(unsigned long int hexa, char type);
int	ft_printf_format(char format, va_list arg);
int	ft_printf(const char *format, ...);

#endif
