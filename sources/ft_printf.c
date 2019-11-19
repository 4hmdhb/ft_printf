/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:16:10 by basylbek          #+#    #+#             */
/*   Updated: 2019/11/15 15:34:46 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_specifiers		*g_dispatch[] = {
	c_specifier,
	s_specifier,
	p_specifier,
	di_cast,
	di_cast,
	di_cast,
	uoxx_cast,
	uoxx_cast,
	uoxx_cast,
	uoxx_cast,
	uoxx_cast,
	f_specifier,
};

char				*get_specifier(char *str, int i)
{
	char	*tmp;
	int		pos;

	pos = 0;
	while (!ft_strchr(ALLSUMBL, str[i + pos]) && str[i])
		pos++;
	tmp = ft_strnew(pos + 1);
	pos = 0;
	while (str[i])
	{
		tmp[pos] = str[i];
		if (ft_strchr(ALLSUMBL, str[i]))
			break ;
		pos++;
		i++;
	}
	return (tmp);
}

t_params			*create_elem(char *format, int *i)
{
	t_params	*element;
	char		*tmp;

	if (!(element = (t_params*)malloc(sizeof(t_params))))
		return (NULL);
	tmp = get_specifier(format, *i);
	handle_width(element, tmp);
	handle_precision(element, tmp);
	handle_length(element, tmp);
	handle_specifier(element, tmp);
	handle_flags(element, tmp);
	*i += ft_strlen(tmp);
	ft_strdel(&tmp);
	return (element);
}

void				delete_elem(t_params *element)
{
	free(element);
	element = NULL;
}

int					do_magic(t_params *element, va_list arguments)
{
	int	i;
	int d;

	i = 0;
	if (!element)
		return (0);
	if (element->specifier == '%')
		return (percent_specifier(element));
	else if (element->specifier == '0')
		return (0);
	else if (element->specifier == 'Z')
	{
		ft_putchar('Z');
		return (1);
	}
	while (i < 12)
	{
		if (ALLSUMBL[i] == element->specifier)
			d = g_dispatch[i](element, arguments);
		i++;
	}
	return (d);
}

int					ft_printf(const char *format, ...)
{
	FIELDS2;
	va_start(arguments, format);
	i = 0;
	d = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			element = create_elem((char*)format, &i);
			d = d + do_magic(element, arguments);
			delete_elem(element);
		}
		else
		{
			ft_putchar(format[i]);
			d++;
			i++;
		}
	}
	return (d);
}
