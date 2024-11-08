/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:02:22 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/08 15:48:41 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	*ft_rev_memcpy(void *dest, void *src, size_t n)
{
	if (n == 0)
		return (dest);
	while (--n >= 0)
	{
		((char *)dest)[n] = ((char *)src)[n];
		if (n == 0)
			break ;
	}
	return (dest);
}

void	*ft_memmove(void *dest, void *src, size_t n)
{
	t_mover	*movers;
	void	*ret_dest;

	movers = (t_mover[]){ft_memcpy, ft_rev_memcpy};
	ret_dest = (movers[src >= dest])(dest, src, n);
	return (ret_dest);
}
