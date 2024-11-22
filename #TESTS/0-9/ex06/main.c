/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 17:46:39 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define CAST_TYPE unsigned char

static void	hdn_test_and_cmp(void)
{
	long	mem[2];
	void	*ret[2];
	int		size;
	int		data;
	int		i;

	data = 0xFF80;
	size = 8;
	ret[0] = memset(mem + 0, data, size);
	ret[1] = ft_memset(mem + 1, data, size);
	assert(ret[0] == mem + 0 && ret[1] == mem + 1);
	i = -1;
	while (++i < size)
	{
		// printf("ori: mem[0][%i] -> %i\n", i, ((CAST_TYPE *)ret[0])[i]);
		// printf("ft: mem[1][%i] -> %i\n", i, ((CAST_TYPE *)ret[1])[i]);
		assert(((CAST_TYPE *)ret[0])[i] == ((CAST_TYPE *)ret[1])[i]);
	}
	printf("[OK] memset\n");
}

int	main(void)
{
	hdn_test_and_cmp();
}
