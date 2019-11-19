/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:53:16 by basylbek          #+#    #+#             */
/*   Updated: 2019/11/07 19:01:03 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_flags(t_params *element, char *format)
{
	int pos;

	pos = 0;
	element->flags = 0;
	while (!ft_isdigit(format[pos]) && format[pos])
	{
		if (format[pos] == '.')
			break ;
		pos++;
	}
	if (format[pos] == '0')
		element->flags |= ZERO_LB;
	if (ft_strchr(format, '-'))
		element->flags |= MINUS_H;
	if (ft_strchr(format, '+'))
		element->flags |= PLUS_HH;
	if (ft_strchr(format, '#'))
		element->flags |= HASH_LL;
	if (ft_strchr(format, ' '))
		element->flags |= SPACE_L;
}

void		handle_length(t_params *element, char *format)
{
	element->length = 0;
	if (ft_strchr(format, 'j'))
		element->length |= HASH_LL;
	if (ft_strchr(format, 'z'))
		element->length |= SIZE_T;
	if (ft_strstr(format, "ll"))
		element->length |= HASH_LL;
	else if (ft_strchr(format, 'l'))
		element->length |= SPACE_L;
	if (ft_strstr(format, "hh"))
		element->length |= PLUS_HH;
	else if (ft_strchr(format, 'h'))
		element->length |= MINUS_H;
	if (ft_strchr(format, 'L'))
		element->length |= ZERO_LB;
}

void		handle_width(t_params *element, char *format)
{
	int pos;

	pos = 0;
	while (!(format[pos] >= 49 && format[pos] <= 57) && format[pos])
	{
		if (format[pos] == '.')
			break ;
		pos++;
	}
	if (ft_isdigit(format[pos]))
		element->width = ft_atoi(&(format[pos]));
	else
		element->width = 0;
}

void		handle_precision(t_params *element, char *format)
{
	int pos;

	pos = 0;
	while (format[pos] != '.' && format[pos])
		pos++;
	if (format[pos] == '.')
	{
		pos++;
		if (ft_isdigit(format[pos]))
			element->precision = ft_atoi(&(format[pos]));
		else
			element->precision = 0;
	}
	else
		element->precision = 2000000;
}

void		handle_specifier(t_params *element, char *format)
{
	int pos;

	pos = 0;
	while (!ft_strchr(ALLSUMBL, format[pos]) && format[pos])
		pos++;
	if (ft_strchr(ALLSUMBL, format[pos]) && format[pos])
		element->specifier = format[pos];
	else
		element->specifier = '0';
}
