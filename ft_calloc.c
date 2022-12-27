/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:36:16 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/27 20:43:58 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	// Please manage this edge case better
	if ((nmemb && size) && ((nmemb == SIZE_MAX) || (size == SIZE_MAX)))
		return ((void *)0);
	arr = malloc(nmemb * size);
	// please return NULL here
	if (arr)
		ft_bzero(arr, nmemb * size);
	return (arr);
}

#include <stdio.h>
int main()
{
	void *s = ft_calloc(SIZE_MAX / 2 + 5, 2);
	printf("%d", s == NULL); // this should return null
}