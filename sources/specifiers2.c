/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:39:05 by basylbek          #+#    #+#             */
/*   Updated: 2019/11/07 19:52:35 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_specifier(t_params *element, va_list arguments)
{
	int		width;
	char	zero;
	char	c;
	int		i;

	c = va_arg(arguments, int);
	zero = (element->flags & ZERO_LB
	&& !(element->flags & MINUS_H)) ? '0' : ' ';
	width = element->width;
	if (element->flags & MINUS_H)
		ft_putchar(c);
	if (width != 0)
		width--;
	i = 0;
	while (i++ < width)
		ft_putchar(zero);
	if (!(element->flags & MINUS_H))
		ft_putchar(c);
	return (i);
}

int		s_specifier(t_params *element, va_list arguments)
{
	char	*tmp;

	FIELDS;
	prec = element->precision;
	if (prec == 0)
		s = ft_strnew(0);
	else
		s = ft_strdup(va_arg(arguments, char*));
	if (!s)
	{
		tmp = s;
		s = ft_strdup("(null)");
		ft_strdel(&tmp);
	}
	zero = (element->flags & ZERO_LB
	&& !(element->flags & MINUS_H)) ? "0" : " ";
	width = (element->flags & MINUS_H) ? element->width * -1 : element->width;
	while (prec < (int)ft_strlen(s))
	{
		tmp = ft_strnew(ft_strlen(s));
		ft_strncpy(tmp, s, prec);
		ft_strdel(&s);
		s = tmp;
	}
	return (width_apply(s, width, zero));
}

int		p_specifier(t_params *element, va_list arguments)
{
	int64_t	n;

	FIELDS;
	n = va_arg(arguments, long);
	prec = (element->precision == 2000000) ? 1 : element->precision;
	zero = (element->flags & ZERO_LB
	&& !(element->flags & MINUS_H)) ? "0" : " ";
	width = (element->flags & MINUS_H) ? element->width * -1 : element->width;
	if (!prec)
		s = ft_strdup("0x");
	else
	{
		s = ft_itoa_precision(n, prec, "0", 16);
		s = ft_strjoin_fr2("0x", s);
	}
	return (width_apply(s, width, zero));
}

int		f_specifier(t_params *element, va_list arguments)
{
	long double	f;

	FIELDS;
	if (element->length & ZERO_LB)
		f = va_arg(arguments, long double);
	else
		f = va_arg(arguments, double);
	prec = (element->precision == 2000000) ? 6 : element->precision;
	width = (element->flags & MINUS_H) ? element->width * -1 : element->width;
	zero = (element->flags & ZERO_LB
	&& !(element->flags & MINUS_H)) ? "0" : " ";
	s = ft_itoa_float(f, prec);
	if (!ft_strchr(s, '.') && (element->flags & HASH_LL))
		s = ft_strjoin_fr1(s, ".");
	s = space_apply(element->flags & PLUS_HH, element->flags & SPACE_L, s);
	return (width_apply(s, width, zero));
}

int		percent_specifier(t_params *element)
{
	int		width;
	char	*zero;
	char	*s;

	s = ft_strdup("%");
	zero = (element->flags & ZERO_LB
	&& !(element->flags & MINUS_H)) ? "0" : " ";
	width = (element->flags & MINUS_H) ? element->width * -1 : element->width;
	return (width_apply(s, width, zero));
}
