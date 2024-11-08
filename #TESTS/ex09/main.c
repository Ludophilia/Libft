/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/08 17:53:31 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

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

// // What happens when src == dest
// // Regular copy, no overlap
// // What happens when dest > src
// // What happens when dest < src

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