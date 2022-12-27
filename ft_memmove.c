/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:45:37 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/27 20:37:37 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy_reverse(void *dest, const void *src, size_t n)
{
	int	i;

	i = n;
	while (--i >= 0)
		((char *)dest)[i] = ((char *)src)[i];
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*(*fp[2])(void *, const void *, size_t);

	fp[0] = ft_memcpy;
	fp[1] = ft_memcpy_reverse;
	return (fp[dest <= src](dest, src, n));
}
