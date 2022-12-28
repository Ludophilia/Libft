/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:36:16 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/28 16:49:33 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;

	// Please manage this edge case better
	if ((nmemb && size) && ((nmemb == SIZE_MAX) || (size == SIZE_MAX)))
		return ((void *)0);
	if (!nmemb)
		nmemb = 1;
	if (!size)
		size = 1;
	arr = malloc(nmemb * size);
	if (arr)
		ft_bzero(arr, nmemb * size);
	return (arr);
}
