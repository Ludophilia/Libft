/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/07 15:20:28 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <strings.h>
#include <assert.h>

#define CAST_TYPE unsigned char

static void	hdn_test_and_cmp(void)
{
	long	mem[2];
	int		size;
	int		i;

	mem[0] = 0xFFFFFFFFFFFFFFFF;
	mem[1] = 0xFFFFFFFFFFFFFFFF;
	size = 8;
	bzero(mem + 0, size);
	ft_bzero(mem + 1, size);
	i = -1;
	while (++i < size)
	{
		printf("ori: mem[0][%i] -> %i\n", i, ((CAST_TYPE *)(mem + 0))[i]);
		printf("ft: mem[1][%i] -> %i\n", i, ((CAST_TYPE *)(mem + 1))[i]);
		assert(((CAST_TYPE *)(mem + 0))[i] == ((CAST_TYPE *)(mem + 1))[i]);
	}
}

int	main(void)
{
	hdn_test_and_cmp();
}
