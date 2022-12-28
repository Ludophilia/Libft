/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:36:16 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/28 23:39:33 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*arr;
	long double	total;
	long double	max;

	total = ((long double)nmemb * (long double)size);
	max = SIZE_MAX;
	if (total >= max)
		return ((void *)0);
	arr = malloc(nmemb * size);
	if (arr)
		ft_bzero(arr, nmemb * size);
	return (arr);
}
