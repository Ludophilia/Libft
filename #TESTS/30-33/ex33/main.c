/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/19 11:25:24 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define FL_NAME "test33"

static void	hdn_test_putnbr(int n, char *expect)
{
	int		fd;
	char	buffer[50];

	ft_bzero(buffer, 50);
	fd = open(FL_NAME, O_CREAT | O_TRUNC | O_RDWR, S_IRWXU);
	if (fd == -1 && dprintf(2, "Failed to create file.\n"))
		return ;
	printf("ft_putnbr_fd(%i, %i)\n", n, fd);
	ft_putnbr_fd(n, fd);
	if (lseek(fd, 0, SEEK_SET) == -1
		|| (read(fd, buffer, ft_strlen(expect)) == -1
			&& dprintf(2, "Failed to read file.\n")))
	{
		close(fd);
		unlink(FL_NAME);
		return ;
	}
	printf("buffer -> \"%s\"\n", buffer);
	assert(ft_memcmp(buffer, expect, ft_strlen(expect)) == 0);
	close(fd);
	unlink(FL_NAME);
	printf("[OK]\n");
}

int	main(void)
{
	hdn_test_putnbr((int)2147483648, "-2147483648");
	hdn_test_putnbr(-2147483648, "-2147483648");
	hdn_test_putnbr(-10, "-10");
	hdn_test_putnbr(0, "0");
	hdn_test_putnbr(1000, "1000");
	hdn_test_putnbr(2147483647, "2147483647");
}
