/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ids <ids@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:31:21 by dim               #+#    #+#             */
/*   Updated: 2021/04/20 03:17:40 by ids              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_option
{
	int		zero;
	int		l_align;
	int		width;
	int		precision;
	char	specifier;
}				t_opt;

typedef struct	s_form
{
	int		minus;
	int		arglen;
	char	*argstr;
}				t_form;

int				ft_printf(const char *form, ...);

int				function_hub(const char **format, va_list *ap);
int				sort_case(t_opt save, va_list *ap);

char			check_spcf(char format);
void			check_flag(const char **format, t_opt *save);
void			check_width(const char **format, t_opt *save, va_list *ap);
void			check_precision(const char **format, t_opt *save, va_list *ap);

int				case_c(t_opt save, va_list *ap);
int				case_s(t_opt save, va_list *ap);
int				s_len(t_opt *save, t_form *form);
int				s_modify(int len, t_opt *save, t_form *form);
char			*s_strdup(char *arg);

int				case_pointer(t_opt save, va_list *ap);
int				pointer_len(unsigned long long arg, t_opt *save, t_form *form);
int				case_percent(t_opt save);
int				percent_r_align(int len, char *str, t_opt save);

int				case_hex(t_opt save, va_list *ap);
int				case_diu(t_opt save, va_list *ap);
int				case_len(int arg, t_opt *save, t_form *form);
int				case_makestr(int len, t_opt *save, t_form *form);
int				l_align_str(int len, char *str, t_opt *save, t_form *form);
int				r_align_str(int len, char *str, t_opt *save, t_form *form);

char			*ft_uitoa(unsigned int nbr, int base);
char			*ft_ullitoa(unsigned long long nbr, int base);
int				nbrlen(unsigned int nbr, int base);
int				ulllen(unsigned long long nbr, int base);

void			resetsave(t_opt *save);
int				ft_strlen(const char *format);
int				ft_atoi(const char **format);
int				ft_putstr(char *str, int len);
void			ft_toupper(char *str);
char			*ft_strdup(const char *format);

#endif
