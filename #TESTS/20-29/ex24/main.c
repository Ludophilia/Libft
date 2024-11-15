/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/15 14:14:06 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_test_strjoin(char const *s1, char const *s2, char *expectation)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	printf("[1] ft_strjoin(\"%s\", \"%s\") -> \"%s\"\n", s1, s2, ret);
	if (ret == NULL)
		assert(ret == expectation);
	else
		assert(ft_memcmp(ret, expectation, ft_strlen(expectation) + 1) == 0);
	if (ret)
		free(ret);
	printf("[OK]\n");
}

int	main(void)
{
	hdn_test_strjoin(NULL, NULL, NULL);
	hdn_test_strjoin("01234", "", "01234");
	hdn_test_strjoin("", "56789", "56789");
	hdn_test_strjoin("01234", "56789", "0123456789");
	hdn_test_strjoin("01\000234", "56789", "0156789");
	hdn_test_strjoin("01234", "5\0006789", "012345");
}
