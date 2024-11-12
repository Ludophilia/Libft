/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/12 16:21:08 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "libft.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

static void	hdn_test_strrchr(const char *s, int c, char *expect)
{
	char	*ret[2];

	ret[0] = strrchr(s, c);
	ret[1] = ft_strrchr(s, c);
	printf("[1] strrchr('%s', '%c') -> '%s'\n", s, c, ret[0]);
	printf("[1] ft_strrchr('%s', '%c') -> '%s'\n", s, c, ret[1]);
	assert(ft_strcmp(ret[0], expect) == 0 && ft_strcmp(ret[1], expect) == 0);
	printf("[OK]\n");
}

int	main(void)
{
	hdn_test_strrchr("", 0, "");
	hdn_test_strrchr(";", 0, "");
	hdn_test_strrchr("00112233445566778899", 0, "");
	hdn_test_strrchr("aaabbbc", 'c', "c");
	hdn_test_strrchr("aaabbbc", 'a', "abbbc");
	hdn_test_strrchr("aaabbbc", 'b', "bc");
	hdn_test_strrchr("00000112233445566778899", '0', "0112233445566778899");
	hdn_test_strrchr("0011223344555555566778899", '5', "566778899");
	hdn_test_strrchr("00112233445566778888899", '8', "899");
}
