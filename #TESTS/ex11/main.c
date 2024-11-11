/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/11 18:00:33 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <assert.h>
#include <stdio.h>
#include "libft.h"

static int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

// size_t strlcat(char *dst, const char *src, size_t size);
static void	hdn_test_strlcat(char *dest, char *src, size_t size)
{
	char	dest0[50];
	char	dest1[50];
	size_t	ret[2];
	size_t	srcdest[3];

	ft_bzero(dest0, 50);
	ft_bzero(dest1, 50);
	if (dest)
	{
		strlcat(dest0, dest, ft_strlen(dest) + 1);
		strlcat(dest1, dest, ft_strlen(dest) + 1);
	}
	srcdest[0] = ft_strlen(src);
	srcdest[1] = ft_strlen(dest0);
	// size_t strlcat(char *dst, const char *src, size_t size);
	printf("dest0 -> '%s'; dest1 -> '%s'; src -> '%s'\n", *dest0, *dest1, *src);
	ret[0] = strlcat(dest0, src, size);
	ret[1] = ft_strlcat(dest1, src, size);
	printf("ret[0] -> %lu; ret[1] -> %lu\n", ret[0], ret[1]);
	if (size <= srcdest[0] + 1)
		assert(ret[0] == size + srcdest[0] && ret[1] == size + srcdest[0]);
	else
		assert(ret[0] == size + srcdest[0] && ret[1] == size + srcdest[0]);
}

int	main(void)
{
	hdn_test_strlcat("0123456789", 0);
	// hdn_test_strlcat("0123456789", 1);
	// hdn_test_strlcat("0123456789", 2);
	// hdn_test_strlcat("0123456789", 6);
	// hdn_test_strlcat("0123456789", 10);
}
