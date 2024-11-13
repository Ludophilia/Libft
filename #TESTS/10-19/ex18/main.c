/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/13 13:49:00 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include "libft.h"

static void	hdn_test_memcmp(const void *s1, const void *s2, size_t n)
{
	int	ret[2];

	ret[0] = memcmp(s1, s2, n);
	ret[1] = ft_memcmp(s1, s2, n);
	printf("[0] memcmp('%s', '%s', %lu) -> %i\n",
		(char *)s1, (char *)s2, n, ret[0]);
	printf("[0] ft_memcmp('%s', '%s', %lu) -> %i\n",
		(char *)s1, (char *)s2, n, ret[1]);
	assert(ret[0] == ret[1]);
	printf("[OK]\n");
}

int	main(void)
{
	hdn_test_memcmp("", "", 0);
	hdn_test_memcmp("", "", 1);
	hdn_test_memcmp("01", "02", 1);
	hdn_test_memcmp("01", "02", 2);
	hdn_test_memcmp("\xF0\xFF", "\xF0\xFF", 2);
	hdn_test_memcmp("\xF0\xFF", "\xF0\x01", 2);
	hdn_test_memcmp("0123456789", "0123456789", 11);
	hdn_test_memcmp("0123456789", "1123456789", 11);
	hdn_test_memcmp((int []){1}, (int []){0x00000001}, 4);
	hdn_test_memcmp((int []){(0x01 << 24) + 0x000000},
		(int []){(0xFF << 24) + 0x000000}, 3);
}
