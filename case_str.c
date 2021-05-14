/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ids <ids@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:18:07 by dim               #+#    #+#             */
/*   Updated: 2021/04/20 03:17:28 by ids              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		case_c(t_opt save, va_list *ap)
{
	int		count;
	int		len;
	char	arg;
	t_form	form;

	form.minus = 0;
	form.arglen = 1;
	save.precision = 0;
	save.zero = 0;
	arg = va_arg(*ap, int);
	form.argstr = (char *)malloc(sizeof(char));
	if (form.argstr == NULL)
		return (-1);
	*(form.argstr) = arg;
	len = case_len(arg, &save, &form);
	count = case_makestr(len, &save, &form);
	return (count);
}

int		case_s(t_opt save, va_list *ap)
{
	int		count;
	int		len;
	char	*arg;
	t_form	form;

	arg = NULL;
	form.minus = 0;
	save.zero = 0;
	arg = va_arg(*ap, char *);
	if (arg == NULL)
		form.arglen = 6;
	else
		form.arglen = ft_strlen(arg);
	form.argstr = s_strdup(arg);
	if (form.argstr == NULL)
		return (-1);
	len = s_len(&save, &form);
	count = s_modify(len, &save, &form);
	return (count);
}

int		s_modify(int len, t_opt *save, t_form *form)
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
	if (save->l_align == 1)
		count = l_align_str(len, str, save, form);
	else
		count = r_align_str(len, str, save, form);
	return (count);
}

int		s_len(t_opt *save, t_form *form)
{
	int len;

	if (save->precision == -1)
	{
		form->arglen = 0;
		save->precision = 0;
	}
	if (save->precision > form->arglen)
		save->precision = form->arglen;
	else if ((save->precision < form->arglen) && (save->precision > 0))
		form->arglen = save->precision;
	if ((save->precision == 0) && (form->arglen != 0))
		save->precision = form->arglen;
	if (save->width >= save->precision)
		len = save->width;
	else
		len = save->precision;
	return (len);
}

char	*s_strdup(char *arg)
{
	int		i;
	char	*str;
	char	*arr;

	arr = "(null)";
	if (arg == 0)
	{
		i = 6;
		str = (char *)malloc(sizeof(char) * 6);
		if (str == NULL)
			return (NULL);
		while (i-- > 0)
			str[i] = arr[i];
		return (str);
	}
	else
		str = ft_strdup(arg);
	return (str);
}
