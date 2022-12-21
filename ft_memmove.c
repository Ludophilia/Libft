/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:45:37 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/21 17:13:41 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	i = n;
	while (--i >= 0)
		((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}
