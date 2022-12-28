/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:38:42 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/28 16:53:01 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <malloc.h>

// almost works like malloc_usable_size from <malloc.h>
size_t	check_zeroes(void *ptr)
{
	size_t	z;

	z = 0;
	while (*(unsigned char *)ptr++ == (unsigned char)0)
		z++;
	return (z);
}

int	main(void)
{
	char	*res[2] = {"KO", "OK"};
	char	*arr;
	char	*ft_arr;
	int		t;

	printf("ft_calloc:\n");
	printf("\tHappy path\n"); t = 0;
	printf("\t\tarr = calloc(2, 1); ft_arr = ft_calloc(2, 1)\n");
	arr = calloc(2, 1); ft_arr = ft_calloc(2, 1);
	printf("\t\t%i. - check_zeroes(arr) -> %lu\n",
		t++, check_zeroes(arr));
	printf("\t\t%i. - check_zeroes(ft_arr) -> %lu\n",
		t++, check_zeroes(ft_arr));
	printf("\t\t%i. - [*arr == 0] -> '%s'(%i)\n", 
		t++, res[*arr == 0], *arr);
	printf("\t\t%i. - [*ft_arr == 0] -> '%s'(%i)\n",
		t++, res[*ft_arr == 0], *ft_arr);
	printf("\t\t%i. - [*arr == *ft_arr] -> '%s'\n\n",
		t++, res[*arr == *ft_arr]);
	free(arr); free(ft_arr);
	
	printf("\tNo size or members\n"); t = 0;
	printf("\t\tarr = calloc(0, 1); ft_arr = ft_calloc(0, 1)\n");
	arr = calloc(0, 1); ft_arr = ft_calloc(0, 1);
	printf("\t\t%i. - check_zeroes(arr) -> %lu\n",
		t++, check_zeroes(arr));
	printf("\t\t%i. - check_zeroes(ft_arr) -> %lu\n",
		t++, check_zeroes(ft_arr));
	printf("\t\t%i. - [*arr == 0] -> '%s'(%i)\n",
		t++, res[*arr == 0], *arr);
	printf("\t\t%i. - [*ft_arr == 0] -> '%s'(%i)\n",
		t++, res[*ft_arr == 0], *ft_arr);
	printf("\t\t%i. - [*arr == *ft_arr] -> '%s'\n\n",
		t++, res[*arr == *ft_arr]);
	free(arr); free(ft_arr);

	// arr = calloc(2, 1);
}