/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:43:17 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/13 20:00:33 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> // FORBIDDEN

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return ((void *)0);
	i = 0;
	while (i < n)
	{
		((int *)s)[i++] = c; // unsigned char and reworks
		// printf("\ni = %lu, c = %i, s[i] = %i\n", i, c, ((int *)s)[i]);
	}
	return (s);
}
