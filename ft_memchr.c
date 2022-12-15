/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:21:31 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/15 21:06:37 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;

	i = 0;
	ps = (unsigned char *)s;
	while (i < n)// && ps[i]) // WTF ? THOT WAS ALL ?
	{
		if (ps[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return ((void *)0);
}
