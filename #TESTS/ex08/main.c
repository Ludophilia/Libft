/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/08 13:31:10 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

static void	hdn_test_ty01(int reference, size_t size, int expected_res)
{
	void	*ret[2];

	ret[0] = memcpy(&reference, &reference, size);
	assert(expected_res == reference);
	ret[1] = ft_memcpy(&reference, &reference, size);
	assert(ret[0] == &reference && ret[1] == &reference);
	assert(expected_res == reference);
}

static void	hdn_test_ty00(int reference, size_t size, int expected_res)
{
	int		cps[2];
	void	*ret[2];

	ft_bzero(cps, 2 * sizeof(int));
	ret[0] = memcpy(cps + 0, &reference, size);
	ret[1] = ft_memcpy(cps + 1, &reference, size);
	assert(ret[0] == cps + 0 && ret[1] == cps + 1);
	assert(expected_res == cps[0] && expected_res == cps[1]);
}

int	main(void)
{
	hdn_test_ty00(0x1234567F, 0, 0);
	hdn_test_ty00(0x1234567F, 2, 0x567f);
	hdn_test_ty00(0x1234567F, 4, 0x1234567F);
	hdn_test_ty01(0x1234567F, 0, 0x1234567F);
	hdn_test_ty01(0x1234567F, 2, 0x1234567F);
	hdn_test_ty01(0x1234567F, 4, 0x1234567F);
}
