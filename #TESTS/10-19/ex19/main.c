/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 18:42:14 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include "libft.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

static void	hdn_test_strnstr(const char *big, const void *little, size_t len)
{
	char	*ret[2];

	ret[0] = strnstr(big, little, len);
	ret[1] = ft_strnstr(big, little, len);
	// printf("[0] strnstr(\"%s\", \"%s\", %lu) -> \"%s\"\n",
	// 	(char *)big, (char *)little, len, ret[0]);
	// printf("[0] ft_strnstr(\"%s\", \"%s\", %lu) -> \"%s\"\n",
	// 	(char *)big, (char *)little, len, ret[1]);
	if (ret[0] == NULL)
		assert(ret[0] == ret[1]);
	else
		assert(ft_strcmp(ret[0], ret[1]) == 0);
}

int	main(void)
{
	hdn_test_strnstr("", "", 0);
	hdn_test_strnstr("", "", 50);
	hdn_test_strnstr("012", "12", 1);
	hdn_test_strnstr("012", "12", 2);
	hdn_test_strnstr("012", "12", 3);
	hdn_test_strnstr("01\0002", "12", 3);
	hdn_test_strnstr("01235", "01236", 1);
	hdn_test_strnstr("01235", "0", 1);
	hdn_test_strnstr("01235", "2", 2);
	hdn_test_strnstr("01235", "2", 3);
	hdn_test_strnstr("01235", "235", 3);
	hdn_test_strnstr("01235", "235", 4);
	hdn_test_strnstr("01235", "235", 5);
	hdn_test_strnstr("01235x", "2356", 6);
	hdn_test_strnstr("01235", "01236", 4);
	hdn_test_strnstr("01235", "0123", 4);
	hdn_test_strnstr("01235", "01236", 5);
	hdn_test_strnstr("", "123456", 6);
	hdn_test_strnstr("012", "", 6);
	hdn_test_strnstr("012", "123456", 6);
	hdn_test_strnstr("123456", "123456", 6);
	hdn_test_strnstr("123456", "123456", 10);
	printf("[OK] strnstr\n");
}
