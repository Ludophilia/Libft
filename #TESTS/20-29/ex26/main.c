/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/15 19:53:03 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_test_split(char const *s1, char const set,
	char **expectation)
{
	char	*ret;

	// ret = ft_strtrim(s1, set);
	// printf("[1] ft_strtrim(\"%s\", \"%s\") -> \"%s\"\n", s1, set, ret);
	// if (ret == NULL)
	// 	assert(ret == expectation);
	// else
	// 	assert(ft_memcmp(ret, expectation, ft_strlen(expectation) + 1) == 0);
	// if (ret)
	// 	free(ret);
	printf("[OK]\n");
}

int	main(void)
{
	hdn_test_split(NULL, "", NULL);
}
