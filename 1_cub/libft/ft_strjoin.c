/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichael <nmichael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:15:31 by nmichael          #+#    #+#             */
/*   Updated: 2021/11/24 14:15:32 by nmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index;
	size_t	jindex;
	size_t	length;
	char	*newstr;

	if (s1 == 0 || s2 == 0)
		return (0);
	index = 0;
	jindex = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc((length + 1) * sizeof(char));
	if (newstr == 0)
		return (0);
	while (s1[index] != '\0')
	{
		newstr[index] = s1[index];
		index++;
	}
	while (s2[jindex] != '\0')
	{
		newstr[index + jindex] = s2[jindex];
		jindex++;
	}
	newstr[index + jindex] = '\0';
	return (newstr);
}
