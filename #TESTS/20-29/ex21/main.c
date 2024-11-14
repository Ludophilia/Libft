/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/14 14:52:39 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_overflow_management_needed_cases(void)
{
	void	*hdn_test_calloc(size_t, size_t);

	hdn_test_calloc(-1, -1);
	hdn_test_calloc(-1, 2);
	hdn_test_calloc(-1, 6);
	hdn_test_calloc((ULONG_MAX / 2) + 1, 2);
	printf("\n");
}

static void	hdn_malloc_fails_on_these_cases(void)
{
	void	*hdn_test_calloc(size_t, size_t);

	hdn_test_calloc(-1, 1);
	hdn_test_calloc(ULONG_MAX, 1);
	hdn_test_calloc(ULONG_MAX / 2, 1);
	hdn_test_calloc(ULONG_MAX / 2, 2);
	hdn_test_calloc((ULONG_MAX - 1), 1);
	printf("\n");
}

static void	hdn_overflows_that_remains_on_limits(void)
{
	void	*hdn_test_calloc(size_t, size_t);

	hdn_test_calloc(ULONG_MAX + 1, 1);
	hdn_test_calloc((ULONG_MAX + 50), 2);
	printf("\n");
}

static void	hdn_it_s_zero_so_who_cares(void)
{
	void	*hdn_test_calloc(size_t, size_t);

	hdn_test_calloc(-1, 0);
	hdn_test_calloc(-1, 0);
	hdn_test_calloc(ULONG_MAX / 2, 0);
}

void	*hdn_test_calloc(size_t, size_t);

int	main(void)
{
	hdn_overflow_management_needed_cases();
	hdn_malloc_fails_on_these_cases();
	hdn_overflows_that_remains_on_limits();
	hdn_it_s_zero_so_who_cares();
}
