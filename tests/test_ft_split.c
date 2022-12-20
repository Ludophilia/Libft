/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:50:13 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/20 17:59:07 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_printstrs(char **strs)
{
	while (*strs)
		printf("\t-> '%s'\n", *strs++);
}

int	main(void)
{
	char	*str;

	str = "hello world ";
	printf("\nft_split(\"%s\", \'\\x20\'):\n", str);
	ft_printstrs(ft_split(str, '\x20'));
	str = "  12 34";
	printf("\nft_split(\"%s\", \'\\x20\'):\n", str);
	ft_printstrs(ft_split(str, '\x20'));
	str = " 12 34 ";
	printf("\nft_split(\"%s\", \'\\x20\'):\n", str);
	ft_printstrs(ft_split(str, '\x20'));
	str = "   12    34 ";
	printf("\nft_split(\"%s\", \'\\x20\'):\n", str);
	ft_printstrs(ft_split(str, '\x20'));
	str = "  tripouille  42  ";
	printf("\nft_split(\"%s\", \'\\x20\'):\n", str);
	ft_printstrs(ft_split(str, '\x20'));
	str = " "; // "  "
	printf("\nft_split(\"%s\", \'\\x20\'):\n", str);
	ft_printstrs(ft_split(str, '\x20'));
	str = "   12    34          ";
	printf("\nft_split(\"%s\", \'\\x20\'):\n", str);
	ft_printstrs(ft_split(str, '\x20'));
}