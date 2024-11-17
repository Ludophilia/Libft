/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/17 16:19:26 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_free_strs(char **strs)
{
	int	j;

	j = 0;
	while (strs[j])
		free(strs[j++]);
	free(strs);
}

static void	hdn_check_assertion(char **strs, char **expc)
{
	int	i;

	i = -1;
	while (strs[++i])
		assert(ft_memcmp(strs[i], expc[i], ft_strlen(expc[i]) + 1) == 0);
}

static void	hdn_print_split(char const *s, char const c, char **strs)
{
	int	i;

	printf("[1] ft_split(\"%s\", '%c') -> ", s, c);
	if (*strs == NULL && printf("[%s]\n", *strs))
		return ;
	i = -1;
	while (strs[++i])
	{
		if (i == 0 && strs[i + 1] == 0 && printf("[%s]\n", strs[i]))
			return ;
		if (i == 0)
			printf("[%s, ", strs[i]);
		else if (strs[i + i] == 0)
			printf("%s]\n", strs[i]);
		else
			printf("%s, ", strs[i]);
	}
}

static void	hdn_test_split(char const *s, char const c,
	char **expc)
{
	char	**strs;

	strs = ft_split(s, c);
	hdn_print_split(s, c, strs);
	if (strs == NULL)
		assert(strs == expc);
	else
		hdn_check_assertion(strs, expc);
	if (strs)
		hdn_free_strs(strs);
	printf("[OK]\n");
}

int	main(void)
{
	hdn_test_split("", 0, (char *[]){0});
	hdn_test_split("abc", 0, (char *[]){"abc", 0});
	hdn_test_split("a b c", ' ', (char *[]){"a", "b", "c", 0});
	hdn_test_split("   a b c", ' ', (char *[]){"a", "b", "c", 0});
	hdn_test_split("   a b c    ", ' ', (char *[]){"a", "b", "c", 0});
	hdn_test_split("   a         b c    ", ' ', (char *[]){"a", "b", "c", 0});
	hdn_test_split("   a         b         c    ", ' ',
		(char *[]){"a", "b", "c", 0});
	hdn_test_split("   a      b     c    d", ' ',
		(char *[]){"a", "b", "c", "d", 0});
	hdn_test_split("e   a      b     c    d", ' ',
		(char *[]){"e", "a", "b", "c", "d", 0});
	hdn_test_split("e\001a\001b\001\001c\001\001\001d", '\001',
		(char *[]){"e", "a", "b", "c", "d", 0});
	hdn_test_split("xxexxxxaxxbxxcxxxxxdxx", 'x',
		(char *[]){"e", "a", "b", "c", "d", 0});
}
