/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:18:18 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/25 23:14:11 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dst;
	unsigned char		*s;
	unsigned char		find_c;
	size_t				i;

	i = 0;
	dst = (unsigned char *)dest;
	s = (unsigned char *)src;
	find_c = c;
	while (i < n)
	{
		dst[i] = s[i];
		if (s[i] == find_c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
