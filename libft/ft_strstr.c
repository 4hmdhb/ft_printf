/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:05:25 by basylbek          #+#    #+#             */
/*   Updated: 2019/09/19 16:54:11 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[j])
	{
		tmp = j;
		while (needle[i] && (needle[i] == haystack[j]))
		{
			j++;
			i++;
		}
		if (!needle[i])
			return ((char*)haystack + tmp);
		else
		{
			i = 0;
			j = tmp + 1;
		}
	}
	return (0);
}
