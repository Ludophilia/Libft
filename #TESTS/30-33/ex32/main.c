/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:16:08 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/22 19:05:58 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

#define FL_NAME "test32"

static void	hdn_test_putendl(char *str, char *expect)
{
	int		fd;
	char	buffer[50];

	assert(str != NULL);
	ft_bzero(buffer, 50);
	fd = open(FL_NAME, O_CREAT | O_TRUNC | O_RDWR);
	if (fd == -1 && dprintf(2, "Failed to create file.\n"))
		return ;
	// printf("ft_putendl_fd(\"%s\", %i)\n", str, fd);
	ft_putendl_fd(str, fd);
	if (lseek(fd, 0, SEEK_SET) == -1
		|| (read(fd, buffer, ft_strlen(expect) + 1) == -1
			&& dprintf(2, "Failed to read file.\n")))
	{
		close(fd);
		unlink(FL_NAME);
		return ;
	}
	// printf("buffer -> \"%s\"\n", buffer);
	assert(ft_memcmp(buffer, expect, ft_strlen(expect) + 1) == 0);
	close(fd);
	unlink(FL_NAME);
}

int	main(void)
{
	hdn_test_putendl("", "\n");
	hdn_test_putendl("0123456789", "0123456789\n");
	printf("[OK] putendl_fd\n");
}
