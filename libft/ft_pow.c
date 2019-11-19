/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 13:14:18 by basylbek          #+#    #+#             */
/*   Updated: 2019/11/08 14:29:00 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t		ft_pow(int64_t n, int base)
{
	uint64_t tmp;

	tmp = 1;
	base = (base < 0) ? base * -1 : base;
	if (base >= 20)
		base = 19;
	while (base--)
		tmp = n * tmp;
	return (tmp);
}
