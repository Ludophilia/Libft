/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:50:13 by jgermany          #+#    #+#             */
/*   Updated: 2022/12/30 20:55:35 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <assert.h>

// static void	print_strs(char **strs)
// {
// 	int	len;

// 	len = -1;
// 	if (!strs)
// 		return ;
// 	if (!*strs)
// 		printf("\t\t\t-> (Empty)\n");
// 	while (strs[++len])
// 		printf("\t\t\t-> '%s'\n", strs[len]);
// 	printf("\t\t\t-> %i total\n", len);
// }

static void	freestrs(char **strs)
{
	char	**start;

	start = strs;
	if (strs != (char **)0) 
		while (*strs)
			free(*strs++);
	free(start);
}

static int	check_strs(char **ref, char **strs)
{
	int		i;
	size_t	lr;
	size_t	ls;

	i = -1;
	while (ref[++i])
	{
		lr = ft_strlen(ref[i]);
		ls = ft_strlen(strs[i]);
		if ((lr != ls) || ft_strncmp(ref[i], strs[i], ft_strlen(ref[i])))
			return (0);
	}
	return (1);
}

static void	split_testcase(char *name, char **ref, char *str, char sep)
{
	char	*res[2] = {"KO", "OK"};
	int		check_res;
	char	**strs;

	printf("\t%s\n", name);
	printf("\t\tft_split(\"%s\", \'%c\'):\n", str, sep);
	strs = ft_split(str, sep); //print_strs(strs);
	if (ref && strs)
	{
		check_res = check_strs(ref, strs);
		assert(check_res);
		printf("\t\t\t-> '%s'\n", res[check_res]);		
	}
	else
	{
		assert(ref == (char **)0);
		assert(strs == (char **)0);
		check_res = 1;
		printf("\t\t\t-> '%s'\n", res[check_res]);
	}
	freestrs(strs);
}

int	main(void)
{
	split_testcase("Happy path (1)", 
		(char *[4]){"salut", "ça", "va", 0},
		"salut ça va", ' ');
	split_testcase("Happy path (2)",
		(char *[5]){"This", "is", "a", "str", 0},
		"Thisxisxaxstr", 'x');

	split_testcase("Just space (1)", 
		(char *[]){0},
		" ", ' ');
	split_testcase("Just space (1)", 
		(char *[]){0},
		"                                  ", ' ');
		
	split_testcase("Empty string (1)", 
		(char *[]){0},
		"", 'W');
	split_testcase("Empty string (2)", 
		(char *[]){0},
		"", '\0');

	split_testcase("No str (1)", 
		(char **)0,
		(char *)0, 0);
	split_testcase("No str (2)", 
		(char **)0,
		(char *)0, 'L');

	split_testcase("Null separator (1)", 
		(char *[]){"Nothing should happen", 0},
		"Nothing should happen", '\x0');
	split_testcase("Null separator (2)", 
		(char *[]){"42School is kind of hardcore", 0}, 
		"42School is kind of hardcore", '\x0');
	split_testcase("Null separator (3)", 
		(char *[]){0}, 
		" ", ' ');

	split_testcase("Sep at start (1)", 
		(char *[]){"salut", "ça", "va", 0}, 
		" salut ça va", ' ');
	split_testcase("Sep at start (2)", 
		(char *[]){"This", "is", "a", "str", 0}, 
		"xThisxisxaxstr", 'x');

	split_testcase("Sep at end (1)", 
		(char *[]){"hello", "word", 0}, 
		"hello word ", ' ');
	split_testcase("Sep at end (2)", 
		(char *[]){"tripouille hommage", 0}, 
		"tripouille hommageE", 'E');

	split_testcase("Sep at start and end (1)", 
		(char *[]){"hello", "word", 0}, 
		" hello word ", ' ');
	split_testcase("Sep at start and end (2)", 
		(char *[]){"tripouille hommage", 0}, 
		"Etripouille hommageE", 'E');

	split_testcase("Repeated sep (1)", 
		(char *[]){"salut", "ca", "va", 0}, 
		"salutXXXXXXXcaXXvaXXXXXXXXXXXXXX", 'X');
	split_testcase("Repeated sep (2)", 
		(char *[]){"Aye", "sir", "!", 0}, 
		"                     Aye sir !", ' ');
	split_testcase("Repeated sep (3)", 
		(char *[]){"split", "this", "for", "me", "?", 0}, 
		"OOOOOOOOOOOOOsplitOOOOOOOOOthisOOOOforOOOOOmeOOO?OOOOOOOO", 'O');
}
