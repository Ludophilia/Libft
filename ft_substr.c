/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:38:00 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/17 19:39:03 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	size;

	// ft_substr_test.cpp

	// if ((start < ft_strlen(s)) && (len > ft_strlen(s))) 
	// 	size = (ft_strlen(s) - start);
	// else if ((start < ft_strlen(s)) && (len <= ft_strlen(s)))
	// 	size = (len - start);
	// else
	// 	size = 0; // +1 ??
		
	if (len > ft_strlen(s))
		size = ft_strlen(s);
	else
		size = len;

	substr = malloc((size + 1) * sizeof(char));
	if (!substr)
		return ((char *)0);
	i = 0;
	while ((i < len) && ((start + i) < ft_strlen(s)))
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\x0';
	return (substr);
}
