/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:45:37 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/15 12:23:43 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;
		
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	i = n - 1;
	while (n--)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i--;
	}	
	return (dest);
}
