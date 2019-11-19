/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:35:15 by basylbek          #+#    #+#             */
/*   Updated: 2019/11/08 12:58:12 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space(char *s, int width, char c)
{
	int i;

	i = (width < 0) ? ft_strlen(s) * -1 : ft_strlen(s);
	if (width < 0)
	{
		ft_putstr(s);
		while (i-- > width)
			ft_putchar(c);
	}
	else
	{
		while (i++ < width)
			ft_putchar(c);
		ft_putstr(s);
	}
}

int		width_apply(char *s, int width, char *c)
{
	int		ret;
	char	*s2;

	s2 = s;
	ret = (width < 0) ? width * -1 : width;
	if (ret < (int)ft_strlen(s))
		ret = ft_strlen(s);
	if ((s[0] == '-' || s[0] == '+' || s[0] == ' ') && c[0] == '0')
	{
		width--;
		ft_putchar(s[0]);
		s++;
	}
	if ((ft_strstr(s, "0x") || ft_strstr(s, "0X")) && c[0] == '0')
	{
		width -= 2;
		if (ft_strstr(s, "0X"))
			ft_putstr("0X");
		else
			ft_putstr("0x");
		s += 2;
	}
	print_space(s, width, *c);
	ft_strdel(&s2);
	return (ret);
}

char	*hash_apply(t_params *element, char *s)
{
	char *tmp;

	if (element->specifier == 'X')
		tmp = ft_strjoin("0X", s);
	else if (element->specifier == 'x')
		tmp = ft_strjoin("0x", s);
	else if (element->specifier == 'o' && s[0] != '0')
		tmp = ft_strjoin("0", s);
	else
		tmp = ft_strdup(s);
	ft_strdel(&s);
	return (tmp);
}

char	*space_apply(int sign, int space, char *s)
{
	char *plus;
	char *tmp;

	plus = (sign) ? "+" : "";
	if (plus[0] == '+' && s[0] != '-')
		tmp = ft_strjoin("+", s);
	else if (s[0] != '-' && s[0] != '+' && space)
		tmp = ft_strjoin(" ", s);
	else
		tmp = ft_strdup(s);
	ft_strdel(&s);
	return (tmp);
}
