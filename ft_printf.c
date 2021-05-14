/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 02:23:52 by dim               #+#    #+#             */
/*   Updated: 2021/04/17 22:03:51 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		count;
	int		len;
	va_list	ap;

	if (format == NULL)
		return (-1);
	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if ((len = function_hub(&format, &ap)) == -1)
			{
				va_end(ap);
				return (-1);
			}
			count += len;
			continue;
		}
		write(1, format++, 1);
		count++;
	}
	va_end(ap);
	return (count);
}
