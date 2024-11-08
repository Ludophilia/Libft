/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/08 17:52:33 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

// // What happens when src == dest
// static void	hdn_test_ty01(int reference, size_t size, int expected_res)
// {
// 	void	*ret[2];

// 	ret[0] = memmove(&reference, &reference, size);
// 	assert(expected_res == reference);
// 	ret[1] = ft_memcpy(&reference, &reference, size);
// 	assert(ret[0] == &reference && ret[1] == &reference);
// 	assert(expected_res == reference);
// }

// // Regular copy, no overlap
// static void	hdn_test_ty00(int reference, size_t size, int expected_res)
// {
// 	int		cps[2];
// 	void	*ret[2];

// 	ft_bzero(cps, 2 * sizeof(int));
// 	ret[0] = memmove(cps + 0, &reference, size);
// 	ret[1] = ft_memmove(cps + 1, &reference, size);
// 	assert(ret[0] == cps + 0 && ret[1] == cps + 1);
// 	assert(expected_res == cps[0] && expected_res == cps[1]);
// }

// // What happens when dest > src
// static void	hdn_test_ty02(int srcs[2], int offset, size_t n, int expectation)
// {
// 	char	*p_srcs0;
// 	char	*p_srcs1;
// 	void	*ret[2];

// 	p_srcs0 = ((char *)srcs) + offset;
// 	p_srcs1 = ((char *)(srcs + 1)) + offset;
// 	ret[0] = memmove(p_srcs0, srcs + 0, n);
// 	ret[1] = ft_memmove(p_srcs1, srcs + 1, n);
// 	assert(ret[0] == p_srcs0 && ret[1] == p_srcs1);
// 	assert(srcs[0] == expectation && srcs[1] == expectation);
// }

// // What happens when dest < src
// static void	hdn_test_ty03(int srcs[2], int offset, size_t n, int expectation)
// {
// 	char	*p_srcs0;
// 	char	*p_srcs1;
// 	void	*ret[2];

// 	p_srcs0 = ((char *)srcs) + offset;
// 	p_srcs1 = ((char *)(srcs + 1)) + offset;
// 	ret[0] = memmove(srcs + 0, p_srcs0, n);
// 	ret[1] = ft_memmove(srcs + 1, p_srcs1, n);
// 	assert(ret[0] == srcs + 0 && ret[1] == srcs + 1);
// 	assert(srcs[0] == expectation && srcs[1] == expectation);
// }

// 01230000
// 00000000

// OH MY GOD, THIS IS SO BAD...

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

static void	hdn_test_fwd_move(int orig)
{
	char	*str;
	void	*ret;

	str = (char []){'x', '1', '2', '3', '0', '0', '0', '0', 0};
	printf("0: %s\n", str);
	if (orig)
		ret = memmove(str + 1, str, 4);
	else
		ret = ft_memmove(str + 1, str, 4);
	printf("1: %s\n", str);
	assert(ret == str + 1);
	assert(ft_strncmp(str, "xx12300", 7) == 0);
}

int	main(void)
{
	hdn_test_fwd_move(1);
	hdn_test_fwd_move(0); // WOW, YOU ARE LIKE VERY BAD AT THIS

}
// hdn_test_ty00(0x1234567F, 0, 0);
// hdn_test_ty00(0x1234567F, 2, 0x567f);
// hdn_test_ty00(0x1234567F, 4, 0x1234567F);
// hdn_test_ty01(0x1234567F, 0, 0x1234567F);
// hdn_test_ty01(0x1234567F, 2, 0x1234567F);
// hdn_test_ty01(0x1234567F, 4, 0x1234567F);
// hdn_test_ty02((int []){0x1234567F, 0x1234567F},
// 	2, 2, (0x567F << 16) + 0x567F);
// hdn_test_ty02((int []){0x1234567F, 0x1234567F},
// 	2, 2, (0x567F << 16) + 0x567F);
// hdn_test_ty03((int []){0x1234567F, 0x1234567F},
// 	2, 2, 0x12341234);