/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichael <nmichael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:14:20 by nmichael          #+#    #+#             */
/*   Updated: 2021/11/24 14:14:22 by nmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	size_t			index;

	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dst;
	index = 0;
	while (n)
	{
		cdest[index] = csrc[index];
		if (csrc[index] == (unsigned char)c)
			break ;
		index++;
		n--;
	}
	if (n)
		return (&cdest[index + 1]);
	return (0);
}
