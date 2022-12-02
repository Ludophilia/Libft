/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:18:59 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/02 21:20:49 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dori;
	size_t	dpos;
	size_t	spos;

	dpos = 0;
	while (size && dst[dpos])
	{
		dpos++;
		size--;
	}
	dori = dpos;
	spos = 0;
	while (src[spos])
	{
		if (size > 1)
		{
			dst[dpos] = src[spos];
			dpos++;
			size--;
		}
		spos++;
	}
	if (size)
		dst[dpos] = '\0';
	return (dori + spos);
}
