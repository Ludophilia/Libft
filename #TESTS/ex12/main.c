/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/12 14:23:24 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_test_toupper(int c, int expect)
{
	int	ret[2];

	printf("to_upper('%c') -> '%c'\n", c, expect);
	ret[0] = toupper(c);
	ret[1] = ft_toupper(c);
	assert(ret[0] == expect && ret[1] == expect);
	printf("[OK]\n");
}

int	main(void)
{
	hdn_test_toupper(0, 0);
	hdn_test_toupper('?', '?');
	hdn_test_toupper('0', '0');
	hdn_test_toupper('c', 'C');
	hdn_test_toupper('C', 'C');
	hdn_test_toupper(127, 127);
}
