/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 18:09:49 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_test_tolower(int c, int expect)
{
	int	ret[2];

	// printf("tolower('%c') -> '%c'\n", c, expect);
	ret[0] = tolower(c);
	ret[1] = ft_tolower(c);
	assert(ret[0] == expect && ret[1] == expect);
}

int	main(void)
{
	hdn_test_tolower(0, 0);
	hdn_test_tolower('?', '?');
	hdn_test_tolower('0', '0');
	hdn_test_tolower('c', 'c');
	hdn_test_tolower('z', 'z');
	hdn_test_tolower('C', 'c');
	hdn_test_tolower('Z', 'z');
	hdn_test_tolower(127, 127);
	printf("[OK] tolower\n");
}
