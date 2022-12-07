/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:38:00 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/07 21:25:04 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// MEMORY LEAK SAFE OR NOT ?
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return ((char *)0);
	i = 0;
	while ((i < len))
		substr[i++] = s[start + i];
	substr[i] = '\x0';
	return (substr);
}
