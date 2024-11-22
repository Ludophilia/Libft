/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 18:10:49 by jegerman         ###   ########.fr       */
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

static void	hdn_test_strchr(const char *s, int c, char *expect)
{
	char	*ret[2];

	ret[0] = strchr(s, c);
	ret[1] = ft_strchr(s, c);
	// printf("[1] strchr('%s', '%c') -> '%s'\n", s, c, ret[0]);
	// printf("[1] ft_strchr('%s', '%c') -> '%s'\n", s, c, ret[1]);
	assert(ft_strcmp(ret[0], expect) == 0 && ft_strcmp(ret[1], expect) == 0);
}

int	main(void)
{
	hdn_test_strchr("", 0, "");
	hdn_test_strchr(";", 0, "");
	hdn_test_strchr("00112233445566778899", 0, "");
	hdn_test_strchr("aaabbbc", 'c', "c");
	hdn_test_strchr("aaabbbc", 'a', "aaabbbc");
	hdn_test_strchr("aaabbbc", 'b', "bbbc");
	hdn_test_strchr("00112233445566778899", '0', "00112233445566778899");
	hdn_test_strchr("00112233445566778899", '5', "5566778899");
	hdn_test_strchr("00112233445566778899", '8', "8899");
	printf("[OK] strchr\n");
}
