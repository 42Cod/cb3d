/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichael <nmichael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:12:31 by nmichael          #+#    #+#             */
/*   Updated: 2021/11/24 14:12:33 by nmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*result;
	size_t	index;

	result = malloc(nitems * size);
	if (result == 0)
		return (0);
	index = 0;
	while (index < (nitems * size))
	{
		result[index] = '\0';
		index++;
	}
	return (result);
}
