/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichael <nmichael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:16:26 by nmichael          #+#    #+#             */
/*   Updated: 2021/11/24 14:16:28 by nmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	while (index >= 0)
	{
		if (str[index] == (char)c)
			return ((char *)(str + index));
		index--;
	}
	return (NULL);
}
