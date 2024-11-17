/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/17 18:35:18 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_test_itoa(int n, char *expc)
{
	char	*ret;

	ret = ft_itoa(n);
	printf("ft_itoa(%i) -> \"%s\"\n", n, ret);
	if (ret == NULL)
		assert(ret == expc);
	else
		assert(ft_memcmp(ret, expc, ft_strlen(expc) + 1) == 0);
	printf("[OK]\n");
	free(ret);
}

int	main(void)
{
	hdn_test_itoa(-2147483648, "-2147483648");
	hdn_test_itoa(-100, "-100");
	hdn_test_itoa(-10, "-10");
	hdn_test_itoa(0, "0");
	hdn_test_itoa(10, "10");
	hdn_test_itoa(100, "100");
	hdn_test_itoa(2147483647, "2147483647");
	hdn_test_itoa(12345, "12345");
	hdn_test_itoa(123456789, "123456789");
}
