/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_diu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ids <ids@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 19:46:22 by dim               #+#    #+#             */
/*   Updated: 2021/04/20 03:29:57 by ids              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		case_diu(t_opt save, va_list *ap)
{
	int		count;
	int		len;
	int		arg;
	t_form	form;

	form.minus = 0;
	form.arglen = 0;
	arg = va_arg(*ap, int);
	if ((save.specifier != 'u') && (arg < 0))
	{
		form.minus = 1;
		arg = -1 * arg;
	}
	form.argstr = ft_uitoa(arg, 10);
	form.arglen = ft_strlen(form.argstr);
	len = case_len(arg, &save, &form);
	count = case_makestr(len, &save, &form);
	return (count);
}

int		case_len(int arg, t_opt *save, t_form *form)
{
	int		len;

	if (save->l_align == 1 || save->precision > 0 || save->precision == -1)
		save->zero = 0;
	if ((save->precision == -1) && (arg != 0))
		save->precision = 0;
	if ((save->precision == -1) && (arg == 0))
	{
		form->arglen = 0;
		len = save->width;
	}
	else if ((form->arglen >= save->width - form->minus) && \
	(form->arglen >= save->precision))
		len = form->arglen + form->minus;
	else if ((save->width - form->minus >= save->precision) && \
	(save->width - form->minus >= form->arglen))
		len = save->width;
	else if ((save->precision >= save->width - form->minus) && \
	(save->precision >= form->arglen))
		len = save->precision + form->minus;
	return (len);
}

int		case_makestr(int len, t_opt *save, t_form *form)
{
	int		count;
	char	*str;

	if (len == 0)
	{
		free(form->argstr);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (-1);
	if (((save->zero == 1) && (save->precision == 0)) || \
	((save->zero == 1) && (form->minus == 1) && (save->precision == 0)))
		save->precision = len - form->minus;
	if (save->precision < form->arglen)
		save->precision = form->arglen;
	if (save->l_align == 1)
		count = l_align_str(len, str, save, form);
	else
		count = r_align_str(len, str, save, form);
	return (count);
}

int		l_align_str(int len, char *str, t_opt *save, t_form *form)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (form->minus == 1)
		str[i++] = '-';
	while (i < len)
	{
		while (i < (save->precision - form->arglen + form->minus))
			str[i++] = '0';
		while (i < save->precision + form->minus)
			str[i++] = form->argstr[j++];
		str[i++] = ' ';
	}
	i = ft_putstr(str, len);
	free(form->argstr);
	free(str);
	return (i);
}

int		r_align_str(int len, char *str, t_opt *save, t_form *form)
{
	int		i;

	i = len - 1;
	while (i >= 0)
	{
		while (form->arglen-- > 0)
			str[i--] = form->argstr[form->arglen];
		while (i >= len - save->precision - form->minus)
		{
			if ((i == len - save->precision - form->minus) && \
			(form->minus == 1))
				str[i--] = '-';
			else
				str[i--] = '0';
		}
		if (i >= 0)
			str[i--] = ' ';
	}
	i = ft_putstr(str, len);
	free(form->argstr);
	free(str);
	return (i);
}
