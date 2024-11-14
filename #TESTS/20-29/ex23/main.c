/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/14 18:00:06 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include "libft.h"

static void	hdn_test_substr(const char *str)
{
	char	*ret[2];
}

// Errors:
// 		- s == NULL
//		- len 0
// 		- if start is outside of strlen (does NULL count? No).
//			- 012
// 			- start 2 ; slen 3 -> start still valid
// 		- s cannot accommodate len. len is too big.
// 			- 012
//				-> start 2 ; slen 3 ; len 1 -> "2" 
//					(maxsublen 1 or (3 - 2) or (slen - start))
//  			-> start 1 ; slen 3 ; len 7 -> "23"
//					(maxsublen 2 or (3 - 1) or (slen - start))
//  			-> start 0 ; slen 3 ; len 7 -> "123"
//					(maxsublen 3 or (3 - 0) or (slen - start))

int	main(void)
{
	hdn_test_strdup("");
	hdn_test_strdup("\x01\x02\x03");
	hdn_test_strdup("hello\0 (again)");
	hdn_test_strdup("hello (again)");
}
