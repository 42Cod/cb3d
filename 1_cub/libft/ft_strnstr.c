/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichael <nmichael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:16:21 by nmichael          #+#    #+#             */
/*   Updated: 2021/11/24 14:16:23 by nmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	index;
	size_t	jindex;

	if (little[0] == '\0')
		return ((char *) big);
	jindex = 0;
	while (jindex < len && big[jindex])
	{
		index = 0;
		while (jindex < len && little[index] && big[jindex]
			&& little[index] == big[jindex])
		{
			index++;
			jindex++;
		}
		if (little[index] == '\0')
			return ((char *)&big[jindex - index]);
		jindex = jindex - index + 1;
	}
	return (0);
}
