/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 19:01:34 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_capitalize_even_characters(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c = ft_toupper(*c);
}

static void	hdn_test_strmapi(char *s, void (*f)(unsigned int, char *),
	char *expc)
{
	// printf("ft_striteri(\"%s\", %p) -> ", s, f);
	ft_striteri(s, f);
	// printf("\"%s\"\n", s);
	if (s == NULL)
		assert(expc == NULL);
	else
		assert(ft_memcmp(s, expc, ft_strlen(s) + 1) == 0);
}

int	main(void)
{
	hdn_test_strmapi(NULL, hdn_capitalize_even_characters, NULL);
	hdn_test_strmapi((char []){'s', 'a', 'l', 'u', 't', '\0'}, NULL, "salut");
	hdn_test_strmapi(NULL, NULL, NULL);
	hdn_test_strmapi((char []){'\0'}, hdn_capitalize_even_characters, "");
	hdn_test_strmapi((char []){'s', 'a', 'l', 'u', 't', '\0'},
		hdn_capitalize_even_characters, "SaLuT");
	hdn_test_strmapi((char []){'s', 'a', '\x01', '\000', 'l', 'u', 't', '\0'},
		hdn_capitalize_even_characters, "Sa\x01");
	printf("[OK] striteri\n");
}
