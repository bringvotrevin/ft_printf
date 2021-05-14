/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ids <ids@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 02:22:13 by dim               #+#    #+#             */
/*   Updated: 2021/04/20 03:16:04 by ids              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		case_hex(t_opt save, va_list *ap)
{
	int		count;
	int		arg;
	int		len;
	t_form	form;

	form.minus = 0;
	arg = va_arg(*ap, int);
	form.argstr = ft_uitoa(arg, 16);
	form.arglen = ft_strlen(form.argstr);
	if (save.specifier == 'X')
		ft_toupper(form.argstr);
	len = case_len(arg, &save, &form);
	count = case_makestr(len, &save, &form);
	return (count);
}
