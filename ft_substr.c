/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:38:00 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/17 23:55:45 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_substr_test.cpp

// start == 0, maxlen == 42000, strlen == 10
//		-> bounded by s (null terminator) (or strlen)
//		-> 10 + 1 ("tri pou ille" + '\0')

// start == 1, maxlen == 1, strlen == 10
//		-> bounded by start and maxlen
//		-> 2 ("r" + '\0')

// start == 100, maxlen == 1, strlen == 10
//		-> bounded by start (out of bounds)
//		-> 1 ('\0')

// start == 9, maxlen == 10, strlen == 10
//		-> bounded by start and s (null terminator)
//		-> 2 ('9' + '\0')

// start == 0, maxlen == 0, strlen == 2
//		-> bounded by maxlen
//		-> 1 ('\0')

// start == 8, maxlen == 14, strlen == 22
//		-> bounded by maxlen or strlen
//		-> 15 ("LES HARICOTS !" + '\0')

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;
	size_t	slen;
	size_t	i;

	size = 0;
	slen = ft_strlen(s);
	while (((start + size) < slen) && (size < len))
		size++;
	substr = malloc((size + 1) * sizeof(char));
	if (!substr)
		return ((char *)0);
	i = 0;
	while ((i < size) && ((start + i) < slen))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\x0';
	return (substr);
}
