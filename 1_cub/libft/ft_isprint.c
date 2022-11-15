/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmichael <nmichael@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:13:10 by nmichael          #+#    #+#             */
/*   Updated: 2021/11/24 14:13:12 by nmichael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_isprint(int arg)
{
	if (arg >= 32 && arg < 127)
		return (1);
	else
		return (0);
}
