/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/13 11:47:01 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include "libft.h"

static void	hdn_test_memchr(const void *s, int c, size_t n)
{
	void	*ret[2];

	ret[0] = memchr(s, c, n);
	ret[1] = ft_memchr(s, c, n);
	printf("[1] memchr('%s', '%c', %lu) -> %p\n", (char *)s, c, n, ret[0]);
	printf("[1] ft_memchr('%s', '%c', %lu) -> %p\n", (char *)s, c, n, ret[1]);
	assert(ret[0] == ret[1]);
	printf("[OK]\n");
}

int	main(void)
{
	hdn_test_memchr("", 0, 0);
	hdn_test_memchr("", 0, 1);
	hdn_test_memchr("0123456789", 0, 0);
	hdn_test_memchr("0123456789", 0, 10);
	hdn_test_memchr("0123456789", 0, 11);
	hdn_test_memchr("0123456789", '0', 1);
	hdn_test_memchr("0123456789", '1', 2);
	hdn_test_memchr("0123456789", '2', 11);
	hdn_test_memchr("0123456222", '2', 11);
}
