/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/18 16:34:31 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"

static char	hdn_capitalize_even_characters(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (ft_toupper(c));
	return (c);
}

static void	hdn_test_strmapi(char const *s, char (*f)(unsigned int, char),
	char *expc)
{
	char	*ret;

	ret = ft_strmapi(s, f);
	printf("ft_strmapi(\"%s\", %p) -> \"%s\"\n", s, f, ret);
	if (ret == NULL)
		assert(ret == expc);
	else
		assert(ft_memcmp(ret, expc, ft_strlen(expc) + 1) == 0);
	printf("[OK]\n");
	free(ret);
}

int	main(void)
{
	hdn_test_strmapi(NULL, hdn_capitalize_even_characters, NULL);
	hdn_test_strmapi("salut", NULL, NULL);
	hdn_test_strmapi(NULL, NULL, NULL);
	hdn_test_strmapi("", hdn_capitalize_even_characters, "");
	hdn_test_strmapi("salut", hdn_capitalize_even_characters, "SaLuT");
	hdn_test_strmapi("sa\x01\000lut", hdn_capitalize_even_characters, "Sa\x01");
}
