/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:38:42 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/29 14:07:08 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <assert.h>
// #include <malloc.h> // for malloc_usable_size
// #include <float.h>

size_t	check_zeroes(void *ptr, size_t size)
{
	size_t	z;

	z = 0;
	while (size-- && *(unsigned char *)ptr++ == (unsigned char)0)
		z++;
	return (z);
}

void	calloc_testcase(char *name, size_t nmemb, size_t size)
{
	char	*res[2] = {"KO", "OK"};
	char	*arr;
	char	*ft_arr;
	int		t;

	printf("\t%s\n", name); t = 0;
	arr = calloc(nmemb, size); ft_arr = ft_calloc(nmemb, size);
	printf("\t\tarr = calloc(%lu, %lu); ft_arr = ft_calloc(%lu, %lu)\n",
		nmemb, size, nmemb, size);
	if (arr && ft_arr)
	{
		printf("\t\t%i. - check_zeroes(arr, %lu) -> %lu\n",
			t++, nmemb * size, check_zeroes(arr, nmemb * size));
		assert(check_zeroes(arr, nmemb * size) == nmemb * size);
		printf("\t\t%i. - check_zeroes(ft_arr, %lu) -> %lu\n",
			t++, nmemb * size, check_zeroes(ft_arr, nmemb * size));
		assert(check_zeroes(ft_arr, nmemb * size) == nmemb * size);
		if (nmemb * size)
		{
			printf("\t\t%i. - [*arr == 0] -> '%s'(%i)\n", 
			t++, res[*arr == 0], *arr);
			assert(*arr == 0);
			printf("\t\t%i. - [*ft_arr == 0] -> '%s'(%i)\n",
				t++, res[*ft_arr == 0], *ft_arr);
			assert(*ft_arr == 0);
		}
		free(arr); free(ft_arr);
	}
	else
	{
		printf("\t\t%i. - [arr == NULL] -> '%s'(%i)\n",
			t++, res[arr == (char *)0], arr == (char *)0);
		assert(arr == 0);
		printf("\t\t%i. - [ft_arr == NULL] -> '%s'(%i)\n",
			t++, res[ft_arr == (char *)0], ft_arr == (char *)0);
		assert(ft_arr == 0);
	}
}

int	main(void)
{
	printf("ft_calloc:\n");
	calloc_testcase("Happy path (1)", 2, 1);
	calloc_testcase("Happy path (2)", 15, sizeof(int));
	calloc_testcase("No size or Numbers (1)", SIZE_MAX, 0);
	calloc_testcase("No size or Numbers (2)", 0, SIZE_MAX);
	calloc_testcase("No size or Numbers (3)", 0, SIZE_MAX);
	calloc_testcase("Size too long (1)", SIZE_MAX, 1);
	calloc_testcase("Size too long (2)", 1, SIZE_MAX);
	calloc_testcase("Size too long (3)", SIZE_MAX, 1  * sizeof(char));
	calloc_testcase("Size too long (4)", 1 * sizeof(char), SIZE_MAX);
	calloc_testcase("Size too long (5) but no overflow", (SIZE_MAX / 2), 2);
	calloc_testcase("Size too long (6)", (SIZE_MAX / 2) + 1, 2);
	calloc_testcase("Size too long (7)", (SIZE_MAX / 2) + 5, 2);
	calloc_testcase("Size too long (8)", (SIZE_MAX / 100) + 42, 100);
	calloc_testcase("Size too long (9)", (SIZE_MAX / 100) + 42, 123);
	calloc_testcase("Size too long (10)", SIZE_MAX, SIZE_MAX);
}