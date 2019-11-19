/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:06:07 by basylbek          #+#    #+#             */
/*   Updated: 2019/11/08 12:56:20 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		di_specifier(t_params *element, int64_t n)
{
	FIELDS;
	prec = (element->precision == 2000000) ? 1 : element->precision;
	width = (element->flags & MINUS_H) ? element->width * -1 : element->width;
	zero = ((element->flags & ZERO_LB) && element->precision > element->width
	&& !(element->flags & MINUS_H)) ? "0" : " ";
	if (prec == 0 && n == 0)
		s = ft_strnew(0);
	else if ((unsigned long long)n == -9223372036854775808ULL)
		s = ft_strdup("-9223372036854775808");
	else
	{
		s = ft_itoa_precision(n, prec, "0", 10);
	}
	s = space_apply(element->flags & PLUS_HH, element->flags & SPACE_L, s);
	return (width_apply(s, width, zero));
}

int		uoxx_specifier(t_params *element, uint64_t digit)
{
	FIELDS;
	prec = (element->precision == 2000000) ? 1 : element->precision;
	width = (element->flags & MINUS_H) ? element->width * -1 : element->width;
	zero = ((element->flags & ZERO_LB) && element->precision > element->width
	&& !(element->flags & MINUS_H)) ? "0" : " ";
	if (prec == 0 && digit == 0 && (!(element->flags & HASH_LL)
	|| element->specifier == 'x' || element->specifier == 'X'))
		s = ft_strnew(0);
	else if (element->specifier == 'x')
		s = ft_itoa_precision_u(digit, prec, "0", 16);
	else if (element->specifier == 'X')
		s = ft_toupper(ft_itoa_precision_u(digit, prec, "0", 16));
	else if (element->specifier == 'o')
		s = ft_itoa_precision_u(digit, prec, "0", 8);
	else if (element->specifier == 'u' || element->specifier == 'U')
		s = ft_itoa_precision_u(digit, prec, "0", 10);
	if (element->flags & HASH_LL && digit != 0)
		s = hash_apply(element, s);
	return (width_apply(s, width, zero));
}

int		uoxx_cast(t_params *element, va_list arguments)
{
	uint64_t		ulli;

	if (element->length & PLUS_HH)
		ulli = (unsigned char)va_arg(arguments, unsigned int);
	else if (element->specifier == 'U')
		ulli = va_arg(arguments, unsigned long);
	else if (element->length & MINUS_H)
		ulli = (unsigned short int)va_arg(arguments, unsigned int);
	else if (element->length & HASH_LL)
		ulli = va_arg(arguments, unsigned long long);
	else if (element->length & SPACE_L)
		ulli = va_arg(arguments, unsigned long);
	else
		ulli = va_arg(arguments, unsigned int);
	return (uoxx_specifier(element, ulli));
}

int		di_cast(t_params *element, va_list arguments)
{
	int64_t	lli;

	if (element->length & SIZE_T)
		lli = va_arg(arguments, unsigned long long int);
	else if (element->length & HASH_LL)
		lli = va_arg(arguments, long long int);
	else if (element->length & SPACE_L || element->specifier == 'D')
		lli = va_arg(arguments, long int);
	else if (element->length & PLUS_HH)
		lli = (signed char)va_arg(arguments, int);
	else if (element->length & MINUS_H)
		lli = (short int)va_arg(arguments, int);
	else
		lli = va_arg(arguments, int);
	return (di_specifier(element, lli));
}
