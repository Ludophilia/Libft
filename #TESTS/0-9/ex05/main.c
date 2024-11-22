/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 17:46:09 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// size_t strlen(const char *s)
static void	hdn_test_and_cmp(char *str)
{
	size_t	ret[2];

	ret[0] = strlen(str);
	ret[1] = ft_strlen(str);
	// printf("strlen('%s') -> %lu\n", str, ret[0]);
	// printf("ft_strlen('%s') -> %lu\n", str, ret[1]);
	assert(ret[0] == ret[1]);
}

int	main(void)
{
	char	**strs;
	int		i;

	strs = (char *[]){"", "0", "01234", "01234\00056789", "0123456789", 0};
	i = -1;
	while (strs[++i])
		hdn_test_and_cmp(strs[i]);
	printf("[OK] strlen\n");
}
