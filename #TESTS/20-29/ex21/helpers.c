/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:53:55 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/14 14:34:14 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"

static int	hdn_check_if_all_zeroes(char *buffer,
	size_t nmemb, size_t size)
{
	size_t	total;
	size_t	i;

	i = 0;
	total = nmemb * size;
	while (i < total)
	{
		if (buffer[i] != 0)
			return (0);
		++i;
	}
	return (1);
}

void	*hdn_test_calloc(size_t nmemb, size_t size)
{
	char	*ret[2];

	ret[0] = calloc(nmemb, size);
	ret[1] = ft_calloc(nmemb, size);
	printf("calloc(%lu, %lu) -> %p\n", nmemb, size, ret[0]);
	printf("ft_calloc(%lu, %lu) -> %p\n", nmemb, size, ret[1]);
	if (ret[0] == NULL)
		assert(ret[0] == ret[1]);
	else
		assert(hdn_check_if_all_zeroes(ret[0], nmemb, size) == 1
			&& hdn_check_if_all_zeroes(ret[1], nmemb, size) == 1);
	printf("[OK]\n");
	return (ret[0]);
}
