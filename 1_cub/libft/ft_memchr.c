/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichael <nmichael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:14:26 by nmichael          #+#    #+#             */
/*   Updated: 2021/11/24 14:14:28 by nmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	c1;
	size_t			index;

	s1 = (unsigned char *)s;
	c1 = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		if (s1[index] == c1)
			return (&s1[index]);
		index++;
	}
	return (0);
}
