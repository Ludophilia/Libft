/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/14 16:02:05 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_test_strdup(const char *str)
{
	char	*ret[2];
	size_t	size;

	size = ft_strlen(str);
	ret[0] = strdup(str);
	ret[1] = ft_strdup(str);
	printf("strdup(\"%s\") -> \"%s\"\n", str, ret[0]);
	printf("ft_strdup(\"%s\") -> \"%s\"\n", str, ret[1]);
	if (ret[0] == NULL)
		assert(ret[0] == ret[1]);
	else
		assert(ft_memcmp(ret[0], str, size + 1) == 0
			&& ft_memcmp(ret[1], str, size + 1) == 0);
	free(ret[0]);
	free(ret[1]);
	printf("[OK]\n");
}

int	main(void)
{
	hdn_test_strdup("");
	hdn_test_strdup("\x01\x02\x03");
	hdn_test_strdup("hello\0 (again)");
	hdn_test_strdup("hello (again)");
}
