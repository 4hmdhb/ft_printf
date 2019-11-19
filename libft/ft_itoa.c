/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:12:08 by basylbek          #+#    #+#             */
/*   Updated: 2019/11/11 14:04:16 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(uint64_t num, int base)
{
	char	*str;
	int		i;
	int		rem;

	i = ft_numlen(num, base);
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (num == 0)
		str[0] = '0';
	while (num)
	{
		rem = num % base;
		str[--i] = (rem >= 10) ? 'a' + (rem - 10) : rem + '0';
		num = num / base;
	}
	return (str);
}
