/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:36:16 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/15 11:03:33 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// MEMORY LEAK SAFE OR NOT ?
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	if ((nmemb * size) > SIZE_MAX)
		return ((void *)0);
	arr = malloc(nmemb * size);
	if (!arr)
		return ((void *)0);
	ft_memset(arr, 0, nmemb);
	return (arr);
}
