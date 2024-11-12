/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/12 13:55:41 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <assert.h>
#include <stdio.h>
#include "libft.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

static void	hdn_init_dests(char *dest_init, char *dest0, char *dest1)
{
	size_t	dest_init_len;

	dest_init_len = ft_strlen(dest_init);
	ft_bzero(dest0, 50);
	ft_bzero(dest1, 50);
	if (dest_init == NULL)
		return ;
	strlcat(dest0, dest_init, dest_init_len + 1);
	strlcat(dest1, dest_init, dest_init_len + 1);
}

static void	hdn_test_strlcat(char *dest_init, char *src, size_t size,
	char *expect)
{
	char	dest0[50];
	char	dest1[50];
	size_t	ret[2];
	size_t	srclen;
	size_t	destlen;

	hdn_init_dests(dest_init, dest0, dest1);
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest_init);
	printf("[0] dest0 -> '%s'; dest1 -> '%s'; src -> '%s'; size -> %lu\n",
		dest0, dest1, src, size);
	ret[0] = strlcat(dest0, src, size);
	ret[1] = ft_strlcat(dest1, src, size);
	printf("[1] ret[0] -> %lu; ret[1] -> %lu\n", ret[0], ret[1]);
	if (size <= destlen)
		assert(ret[0] == size + srclen && ret[1] == size + srclen);
	else
		assert(ret[0] == srclen + destlen && ret[1] == srclen + destlen);
	printf("[1] dest0 -> '%s'; dest1 -> '%s'\n", dest0, dest1);
	assert(ft_strcmp(dest0, expect) == 0 && ft_strcmp(dest1, expect) == 0);
	printf("[OK]\n");
}

int	main(void)
{
	hdn_test_strlcat("", "01", 0, "");
	hdn_test_strlcat("", "01", 1, "");
	hdn_test_strlcat("", "01", 2, "0");
	hdn_test_strlcat("", "01", 3, "01");
	hdn_test_strlcat("01", "", 2, "01");
	hdn_test_strlcat("01", "", 5, "01");
	hdn_test_strlcat("01", "23", 3, "01");
	hdn_test_strlcat("01", "23", 4, "012");
	hdn_test_strlcat("01", "23", 5, "0123");
	hdn_test_strlcat("01234", "56789", 10, "012345678");
}
