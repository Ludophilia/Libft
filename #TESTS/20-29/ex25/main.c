/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 18:55:34 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_test_strtrim(char const *s1, char const *set,
	char *expectation)
{
	char	*ret;

	ret = ft_strtrim(s1, set);
	// printf("[1] ft_strtrim(\"%s\", \"%s\") -> \"%s\"\n", s1, set, ret);
	if (ret == NULL)
		assert(ret == expectation);
	else
		assert(ft_memcmp(ret, expectation, ft_strlen(expectation) + 1) == 0);
	if (ret)
		free(ret);
}

int	main(void)
{
	hdn_test_strtrim(NULL, "", NULL);
	hdn_test_strtrim("", NULL, NULL);
	hdn_test_strtrim(NULL, NULL, NULL);
	hdn_test_strtrim("0123", "03", "12");
	hdn_test_strtrim("012", "02", "1");
	hdn_test_strtrim("01", "0", "1");
	hdn_test_strtrim("01", "01", "");
	hdn_test_strtrim("0110010101010100101001010010101010010101", "01", "");
	hdn_test_strtrim("", "01", "");
	hdn_test_strtrim("01", "", "01");
	hdn_test_strtrim("0123456789", "012356789", "4");
	hdn_test_strtrim("0123456789", "01235678", "456789");
	printf("[OK] strtrim\n");
}
