/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ids <ids@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:06:02 by dim               #+#    #+#             */
/*   Updated: 2021/04/20 03:17:09 by ids              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		case_pointer(t_opt save, va_list *ap)
{
	int					count;
	int					len;
	unsigned long long	arg;
	t_form				form;

	form.minus = 0;
	form.arglen = 0;
	save.zero = 0;
	arg = va_arg(*ap, unsigned long long);
	form.argstr = ft_ullitoa(arg, 16);
	form.arglen = ft_strlen(form.argstr);
	len = pointer_len(arg, &save, &form);
	count = case_makestr(len, &save, &form);
	return (count);
}

int		pointer_len(unsigned long long arg, t_opt *save, t_form *form)
{
	int		len;

	if ((save->precision == -1) && (arg != 0))
		save->precision = 0;
	if ((save->precision == -1) && (arg == 0))
	{
		form->arglen = 2;
		len = save->width;
	}
	else if ((form->arglen >= save->width) && \
	(form->arglen >= save->precision))
		len = form->arglen;
	else if ((save->width >= save->precision) && \
	(save->width >= form->arglen))
		len = save->width;
	else if ((save->precision >= save->width) && \
	(save->precision >= form->arglen))
		len = save->precision;
	if (len < 2)
		len = 2;
	return (len);
}

int		case_percent(t_opt save)
{
	int		i;
	int		len;
	char	*str;

	len = 1;
	if (save.width != 0)
		len = save.width;
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (-1);
	i = 0;
	if (save.l_align == 1)
	{
		str[i++] = '%';
		while (i < len)
			str[i++] = ' ';
		i = ft_putstr(str, len);
	}
	else
		i = percent_r_align(len, str, save);
	free(str);
	return (i);
}

int		percent_r_align(int len, char *str, t_opt save)
{
	int		i;

	i = len - 1;
	str[i--] = '%';
	while (i >= 0)
	{
		if (save.zero == 1)
			str[i--] = '0';
		else
			str[i--] = ' ';
	}
	i = ft_putstr(str, len);
	return (i);
}
