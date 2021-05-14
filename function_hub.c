/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_hub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:58:59 by dim               #+#    #+#             */
/*   Updated: 2021/04/17 20:33:40 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		function_hub(const char **format, va_list *ap)
{
	int		count;
	t_opt	save;

	count = 0;
	resetsave(&save);
	(*format)++;
	check_flag(format, &save);
	check_width(format, &save, ap);
	if (**format == '.')
	{
		*format = *format + 1;
		check_precision(format, &save, ap);
	}
	save.specifier = check_spcf(**format);
	(*format)++;
	if (save.specifier == 0)
		return (-1);
	count = sort_case(save, ap);
	return (count);
}

int		sort_case(t_opt save, va_list *ap)
{
	int		count;

	count = 0;
	if (save.specifier == 'c')
		count = case_c(save, ap);
	if (save.specifier == 's')
		count = case_s(save, ap);
	if (save.specifier == 'p')
		count = case_pointer(save, ap);
	if (save.specifier == 'd' || save.specifier == 'i' || save.specifier == 'u')
		count = case_diu(save, ap);
	if (save.specifier == 'x' || save.specifier == 'X')
		count = case_hex(save, ap);
	if (save.specifier == '%')
		count = case_percent(save);
	return (count);
}
