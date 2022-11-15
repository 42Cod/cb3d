/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichael <nmichael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:15:36 by nmichael          #+#    #+#             */
/*   Updated: 2021/11/24 14:15:37 by nmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	destlen;
	size_t	srclen;

	index = 0;
	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size == 0 || size <= destlen)
		return (size + srclen);
	while (src[index] != '\0' && index < (size - destlen - 1))
	{
		dst[destlen + index] = src[index];
		index++;
	}
	dst[destlen + index] = '\0';
	return (destlen + srclen);
}
