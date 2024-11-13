/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/13 17:35:29 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

#include <assert.h>
#include <stdio.h>
#include "libft.h"

// void *calloc(size_t nmemb, size_t size);
int	main(void)
{
	char	*ptr;
	
	ptr = calloc((ULONG_MAX + 50), 2);
	printf("%p\n", ptr);
	if (ptr == NULL)
		return (1);
	*ptr = 'X';
	printf("%c\n", *ptr);
}
