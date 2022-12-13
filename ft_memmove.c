/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:45:37 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/13 16:50:09 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	t;

	i = 0;
	while ((i < n))
	{
		t = ((unsigned char *)src)[i];
		((unsigned char *)dest)[i] = t;
		i++;
	}
	return (dest);
}
