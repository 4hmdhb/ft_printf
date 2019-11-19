/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:18:24 by basylbek          #+#    #+#             */
/*   Updated: 2019/11/11 14:14:29 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*add_space(char *s, int prec, char *c)
{
	int i;

	i = (prec < 0) ? ft_strlen(s) * -1 : ft_strlen(s);
	if (prec < 0)
	{
		while (i-- > prec)
			s = ft_strjoin_fr1(s, c);
	}
	else
	{
		while (i++ < prec)
			s = ft_strjoin_fr2(c, s);
	}
	return (s);
}

char	*ft_itoa_precision(int64_t n, int prec, char *c, int base)
{
	char	*s;
	int		sign;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = n * -1;
	}
	s = ft_itoa(n, base);
	s = add_space(s, prec, c);
	if (sign)
		s = ft_strjoin_fr2("-", s);
	return (s);
}

char	*ft_itoa_precision_u(uint64_t n, int prec, char *c, int base)
{
	char	*s;

	s = ft_itoa(n, base);
	s = add_space(s, prec, c);
	return (s);
}

void	precision(long double *fpart, uintmax_t *ipart, int prec)
{
	if ((long)((*fpart - (long)*fpart) * 10) >= 5)
	{
		if (prec == 0)
			*ipart = *ipart + 1;
		else
			*fpart = *fpart + 1;
	}
	if (ft_numlen(*fpart, 10) > prec && prec != 0)
	{
		*ipart = *ipart + 1;
		*fpart = 0;
	}
}

char	*ft_itoa_float(long double n, int prec)
{
	uintmax_t		ipart;
	long double		fpart;
	char			*s;
	int				sign;

	sign = 0;
	if (n < 0.0)
	{
		n = n * -1.0;
		sign = 1;
	}
	ipart = n;
	fpart = (n - (long double)ipart) * ft_pow(10, prec);
	if (prec == 20)
		fpart *= 10;
	precision(&fpart, &ipart, prec);
	s = ft_itoa(ipart, 10);
	if (prec != 0)
	{
		s = ft_strjoin_fr1(s, ".");
		s = ft_strjoin_fr(s, ft_itoa_precision(fpart, prec, "0", 10));
	}
	if (sign)
		s = ft_strjoin_fr2("-", s);
	return (s);
}
