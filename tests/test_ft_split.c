/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:50:13 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/25 19:44:38 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_printstrs(char **strs)
{
	size_t	len;

	len = 0;
	if (!*strs)
		printf("\t-> (Empty)\n");
	while (strs[len])
	{
		printf("\t -> '%s'\n", strs[len]);
		len++;
	}
	printf("\t -> %lu total\n", len);
}

void	ft_freestrs(char **strs)
{
	char	**head;

	head = strs;
	while (*head)
		free(*head++);
	free(strs);
}

void	ft_split_testcase(char *str, char sep)
{
	char	**strs;

	printf("\nft_split(\"%s\", \'%c\'):\n", str, sep);
	strs = ft_split(str, sep);
	ft_printstrs(strs);
	ft_freestrs(strs);
}

// The last one SHOULD SEGFAULT
int	main(void)
{
	// ft_split_testcase("hello world ", ' ');
	// ft_split_testcase("  12 34", ' ');
	// ft_split_testcase("   12    34 ", ' ');
	// ft_split_testcase("   12    34          ", ' ');
	// ft_split_testcase("  tripouille  42  ", ' ');
	// ft_split_testcase(" ", ' ');
	// ft_split_testcase("tripouille", 0);
	ft_split_testcase("      split       this for   me  !       ", ' ');
	// ft_split_testcase((char *)0, 0);
}
