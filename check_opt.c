/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:27:34 by dim               #+#    #+#             */
/*   Updated: 2021/04/17 20:40:12 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	check_spcf(char spcf)
{
	if (spcf == 'c' || spcf == 's' || spcf == 'p' || spcf == 'd' || \
	spcf == 'i' || spcf == 'u' || spcf == 'x' || spcf == 'X' || spcf == '%')
		return (spcf);
	else
		return (0);
}

void	check_flag(const char **format, t_opt *save)
{
	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			save->l_align = 1;
		if (**format == '0')
			save->zero = 1;
		(*format)++;
	}
}

void	check_width(const char **format, t_opt *save, va_list *ap)
{
	int		nbr;

	nbr = 0;
	if (**format > '0' && **format <= '9')
		save->width = ft_atoi(format);
	else if (**format == '*')
	{
		nbr = va_arg(*ap, int);
		if (nbr < 0)
		{
			nbr = -1 * nbr;
			save->l_align = 1;
		}
		save->width = nbr;
		(*format)++;
	}
}

void	check_precision(const char **format, t_opt *save, va_list *ap)
{
	int		nbr;

	nbr = 0;
	if (**format >= '0' && **format <= '9')
	{
		save->precision = ft_atoi(format);
		if (save->precision == 0)
			save->precision = -1;
	}
	else if (**format == '*')
	{
		nbr = va_arg(*ap, int);
		save->precision = nbr;
		if (nbr < 0)
			save->precision = 0;
		if (nbr == 0)
			save->precision = -1;
		(*format)++;
	}
	else
		save->precision = -1;
}
