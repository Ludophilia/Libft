/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 18:44:25 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_test_atoi(const char *nptr)
{
	int	ret[2];

	ret[0] = atoi(nptr);
	ret[1] = ft_atoi(nptr);
	// printf("[0] atoi(\"%s\") -> %i\n", nptr, ret[0]);
	// printf("[0] ft_atoi(\"%s\") -> %i\n", nptr, ret[1]);
	assert(ret[0] == ret[1]);
}

int	main(void)
{
	hdn_test_atoi("");
	hdn_test_atoi("+");
	hdn_test_atoi("+-10");
	hdn_test_atoi("42");
	hdn_test_atoi("+42");
	hdn_test_atoi("10");
	hdn_test_atoi("0");
	hdn_test_atoi("-10");
	hdn_test_atoi("-42");
	hdn_test_atoi(" 42");
	hdn_test_atoi("   +42");
	hdn_test_atoi("  10");
	hdn_test_atoi("\t0");
	hdn_test_atoi("  -10");
	hdn_test_atoi("   \x0d-42");
	hdn_test_atoi("--42");
	hdn_test_atoi("++42");
	hdn_test_atoi("++ 42");
	hdn_test_atoi("\t\t\t\t\t\t++ 42");
	hdn_test_atoi("\t\t\x0a\x0b 042");
	hdn_test_atoi("128e128");
	hdn_test_atoi(" -10x42");
	hdn_test_atoi("\r\r\r128e128");
	hdn_test_atoi("-2147483648lll++-5ddj");
	hdn_test_atoi("2147483647k011");
	printf("[OK] atoi\n");
}
