/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 04:56:17 by ids               #+#    #+#             */
/*   Updated: 2021/04/17 20:38:12 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	resetsave(t_opt *save)
{
	save->zero = 0;
	save->l_align = 0;
	save->width = 0;
	save->precision = 0;
	save->specifier = 0;
}

int		ft_strlen(const char *format)
{
	int		i;

	i = 0;
	while (format[i])
		i++;
	return (i);
}

int		ft_atoi(const char **format)
{
	int		nbr;

	nbr = 0;
	while (**format >= '0' && **format <= '9')
	{
		nbr = (nbr * 10) + (**format - '0');
		(*format)++;
	}
	return (nbr);
}
