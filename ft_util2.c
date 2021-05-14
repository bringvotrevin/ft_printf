/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 05:00:53 by ids               #+#    #+#             */
/*   Updated: 2021/04/17 20:24:36 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_toupper(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))
			str[i] = str[i] - 32;
		i++;
	}
}

int		ft_putstr(char *str, int len)
{
	int		i;

	i = len;
	while (i)
	{
		write(1, str++, 1);
		i--;
	}
	return (len);
}

char	*ft_strdup(const char *format)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = ft_strlen(format);
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = format[i];
		i++;
	}
	return (str);
}
