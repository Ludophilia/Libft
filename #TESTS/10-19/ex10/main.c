/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/12 11:18:09 by jegerman         ###   ########.fr       */
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

static void	hdn_test_strlcpy(char *src, size_t size)
{
	char	dest0[50];
	char	dest1[50];
	size_t	ret[2];

	*dest0 = 0;
	*dest1 = 0;
	ret[0] = strlcpy(dest0, src, size);
	ret[1] = ft_strlcpy(dest1, src, size);
	assert(strlen(src) == ret[0]);
	assert(strlen(src) == ret[1]);
	if (size == 0 || size == 1)
	{
		if (size == 1)
			assert(*dest0 == 0 && *dest1 == 0);
		printf("[OK] src -> %s for size -> %lu\n", src, size);
		printf("[OK] dest0 -> %s, dest1 -> %s\n", dest0, dest1);
		return ;
	}
	assert(ft_strncmp(src, dest0, size - 1) == 0 && dest0[size - 1] == 0);
	assert(ft_strncmp(src, dest1, size - 1) == 0 && dest1[size - 1] == 0);
	printf("[OK] src -> %s for size -> %lu\n", src, size);
	printf("[OK] dest0 -> %s, dest1 -> %s\n", dest0, dest1);
}

int	main(void)
{
	hdn_test_strlcpy("0123456789", 0);
	hdn_test_strlcpy("0123456789", 1);
	hdn_test_strlcpy("0123456789", 2);
	hdn_test_strlcpy("0123456789", 6);
	hdn_test_strlcpy("0123456789", 10);
}
