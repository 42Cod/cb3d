/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichael <nmichael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:15:41 by nmichael          #+#    #+#             */
/*   Updated: 2021/11/24 14:15:43 by nmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	jindex;

	jindex = 0;
	if (dst == 0 || src == 0)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (jindex < (size - 1) && src[jindex] != '\0')
	{
		dst[jindex] = src[jindex];
		jindex++;
	}
	dst[jindex] = '\0';
	return (ft_strlen(src));
}
