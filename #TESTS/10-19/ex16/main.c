/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 18:14:25 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_test_strncmp(const char *s1, const char *s2, size_t n,
	int expect)
{
	int	ret[2];

	ret[0] = strncmp(s1, s2, n);
	ret[1] = ft_strncmp(s1, s2, n);
	// printf("[1] strncmp('%s', '%s', '%lu') -> '%i'\n", s1, s2, n, ret[0]);
	// printf("[1] ft_strncmp('%s', '%s', '%lu') -> '%i'\n", s1, s2, n, ret[1]);
	assert(ret[0] == expect && ret[1] == expect);
}

int	main(void)
{
	hdn_test_strncmp("", "a", 0, 0);
	hdn_test_strncmp("", "a", 1, -97);
	hdn_test_strncmp("", "a", 50, -97);
	hdn_test_strncmp("", "", 50, 0);
	hdn_test_strncmp("a", "", 0, 0);
	hdn_test_strncmp("a", "", 1, 97);
	hdn_test_strncmp("a", "", 69, 97);
	hdn_test_strncmp("aab", "aac", 2, 0);
	hdn_test_strncmp("aab", "aac", 3, -1);
	hdn_test_strncmp("aab", "aac", 420, -1);
	printf("[OK] strncmp\n");
}
