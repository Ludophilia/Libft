/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 19:03:54 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

static void	hdn_test_putchar(char c)
{
	int		fd;
	char	buffer;

	buffer = '4';
	assert(buffer != c);
	fd = open("test30", O_CREAT | O_TRUNC | O_RDWR);
	if (fd == -1 && dprintf(2, "Failed to create file.\n"))
		return ;
	// printf("ft_putchar_fd('%c', %i)\n", c, fd);
	ft_putchar_fd(c, fd);
	if (lseek(fd, 0, SEEK_SET) == -1 || (read(fd, &buffer, 1) == -1
			&& dprintf(2, "Failed to read file.\n")))
	{
		close(fd);
		unlink("test30");
		return ;
	}
	// printf("buffer -> %c\n", buffer);
	assert(buffer == c);
	close(fd);
	unlink("test30");
}

int	main(void)
{
	hdn_test_putchar('X');
	printf("[OK] putchar_fd\n");
}
