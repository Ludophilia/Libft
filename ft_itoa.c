/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:27:18 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/08 22:12:34 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Divide and Conquer... Again !!! // strjoin sur toutes les instances d'itoa ?
// free memory avant quand meme... MEMORY LEAK SAFE OR NOT ?
// Where are negative numbers ?
char	*ft_itoa(int n)
{
	char	*str;
	char	digit;

	str = "";
	digit = '0' + (n % 10); // 42 -> 2
	if (n >= 10) // 42 -> 0, 4
		str = ft_strjoin(ft_itoa((n / 10) / 10), ft_itoa(n / 10));
	if (n != 0)
		str = ft_strjoin(str, &digit); // janky, no null character.
	return (str);
}
