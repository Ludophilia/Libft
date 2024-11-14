/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:10:18 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/14 17:59:16 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	max_sublen;
	size_t	i;

	if (s == NULL || len == 0)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (NULL);
	max_sublen = slen - start;
	if (len < max_sublen)
		max_sublen = len;
	sub = malloc((max_sublen + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	sub[max_sublen] = '\0';
	i = 0;
	while (i < max_sublen)
	{
		sub[i] = s[start + i];
		++i;
	}
	return (sub);
}
