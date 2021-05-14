/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dim <dim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 03:19:55 by dim               #+#    #+#             */
/*   Updated: 2021/04/17 20:34:30 by dim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int nbr, int base)
{
	int		len;
	char	*str;
	char	*arr;

	arr = "0123456789abcdef";
	len = nbrlen(nbr, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = arr[nbr % base];
		nbr /= base;
	}
	return (str);
}

char	*ft_ullitoa(unsigned long long nbr, int base)
{
	int		len;
	char	*str;
	char	*arr;

	arr = "0123456789abcdef";
	len = ulllen(nbr, base) + 2;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		if (len <= 1)
		{
			str[1] = 'x';
			str[0] = '0';
			break ;
		}
		str[len] = arr[nbr % base];
		nbr /= base;
	}
	return (str);
}

int		nbrlen(unsigned int nbr, int base)
{
	int		len;

	len = 1;
	while (nbr >= (unsigned int)base)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

int		ulllen(unsigned long long nbr, int base)
{
	int		len;

	len = 1;
	while (nbr >= (unsigned long long)base)
	{
		nbr /= base;
		len++;
	}
	return (len);
}
