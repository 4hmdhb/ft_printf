/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:13:42 by basylbek          #+#    #+#             */
/*   Updated: 2019/10/23 18:34:39 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t		ft_atoi(const	char *str)
{
	intmax_t	tmp;
	int			sign;
	int			count;

	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	str += (sign == -1 || *str == '+') ? 1 : 0;
	while (*str == '0')
		str++;
	tmp = 0;
	count = 0;
	while (ft_isdigit(*str) && ++count)
		tmp = (tmp * 10ULL) + (*str++ - '0');
	if (count > 19 || tmp > 9223372036854775807LL)
		return (sign == -1) ? 0 : -1;
	return (tmp * sign);
}
