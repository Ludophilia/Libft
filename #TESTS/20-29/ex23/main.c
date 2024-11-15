/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/15 13:46:42 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_test_substr(char const *s, unsigned int start, size_t len,
	char *expectation)
{
	char	*ret;

	ret = ft_substr(s, start, len);
	printf("[1] ft_substr(\"%s\", %u, %lu) -> \"%s\"\n",
		s, start, len, ret);
	if (ret == NULL)
		assert(ret == expectation);
	else
		assert(ft_memcmp(ret, expectation, ft_strlen(expectation) + 1) == 0);
	if (ret)
		free(ret);
	printf("[OK]\n");
}

int	main(void)
{
	hdn_test_substr(NULL, 10, 200, NULL);
	hdn_test_substr("NULL", 10, 0, NULL);
	hdn_test_substr("01", 2, 1, NULL);
	hdn_test_substr("01", 0, 100, "01");
	hdn_test_substr("01234", 3, 100, "34");
	hdn_test_substr("0123456789", 3, 100, "3456789");
	hdn_test_substr("0123456789", 3, 2, "34");
	hdn_test_substr("01234", 1, 3, "123");
	hdn_test_substr("01234", 1, 4, "1234");
	hdn_test_substr("01234567", 1, 4, "1234");
	hdn_test_substr("01234567", 1, 5, "12345");
}
