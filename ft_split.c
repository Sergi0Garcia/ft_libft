/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:47:52 by segarcia          #+#    #+#             */
/*   Updated: 2022/04/28 14:09:12 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

int	count_words(const char *str, char c)
{
	int words;
	int ckpt;

	words = 0;
	ckpt = 0;
	// Chekpoint refers to a word count after c char encounter
	while (*str)
	{
		if (*str != c && ckpt == 0)
		{
			ckpt = 1;
			words++;
		}
		else if (*str == c)
			ckpt = 0;
		str++;
	}
	return (words);
}

int count_chars(const char *str, char c, int word_count)
{
	int words;
	int chars;
	int ckpt;

	words = 0;
	chars = 0;
	ckpt = 0;

	while (*str)
	{
		if (*str != c && ckpt == 0)
		{
			ckpt = 1;
			words++;
			if (words == word_count)
			{
				while (*str !=c)
				{
					chars++;
					str++;
				}
				return (chars);
			}
		}
		else if (*str == c)
			ckpt = 0;
		str++;
	}
	return (chars);
}

void	write_words(char *dst, const char *str, char c, int word_count)
{
	int words;
	int chars;
	int ckpt;

	words = 0;
	chars = 0;
	ckpt = 0;

	while (*str)
	{
		if (*str != c && ckpt == 0)
		{
			ckpt = 1;
			words++;
			if (words == word_count)
			{
				while (*str !=c)
				{
					*dst = *str;
					chars++;
					str++;
					dst++;
				}
				dst = 0;
			}
		}
		else if (*str == c)
			ckpt = 0;
		str++;
	}
}


char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;
	int		chars;
	int		shift;
	int 	freec;

	freec = 0;
	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	shift = 0;
	while (i < words)
	{
		chars = count_chars(s, c, i);
		res[i] = (char *)malloc(sizeof(char) * (chars + 1));
		write_words(res[i], s, c, i + 1);
		if (!res[i])
		{

			while(res[freec])
			{
				free(res[i]);
				freec++;
			}
			free(res);
		}
		i++;
	}
	res[i] = 0;
	return (res);
}


// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }

// int		main(int argc, const char *argv[])
// {
// 	char	**tabstr;
// 	int		i;
// 	int		arg;

// 	alarm(5);
// 	if (argc == 1)
// 		return (0);
// 	i = 0;
// 	if ((arg = atoi(argv[1])) == 1)
// 	{
// 		if (!(tabstr = ft_split("          ", ' ')))
// 			ft_print_result("NULL");
// 		else
// 		{
// 			while (tabstr[i] != NULL)
// 			{
// 				ft_print_result(tabstr[i]);
// 				write(1, "\n", 1);
// 				i++;
// 			}
// 		}
// 	}
// 	else if (arg == 2)
// 	{
// 		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
// 			ft_print_result("NULL");
// 		else
// 		{
// 			while (tabstr[i] != NULL)
// 			{
// 				ft_print_result(tabstr[i]);
// 				write(1, "\n", 1);
// 				i++;
// 			}
// 		}
// 	}
// 	else if (arg == 3)
// 	{
// 		if (!(tabstr = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')))
// 			ft_print_result("NULL");
// 		else
// 		{
// 			while (tabstr[i] != NULL)
// 			{
// 				ft_print_result(tabstr[i]);
// 				write(1, "\n", 1);
// 				i++;
// 			}
// 		}
// 	}
// 	else if (arg == 4)
// 	{
// 		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i')))
// 			ft_print_result("NULL");
// 		else
// 		{
// 			while (tabstr[i] != NULL)
// 			{
// 				ft_print_result(tabstr[i]);
// 				write(1, "\n", 1);
// 				i++;
// 			}
// 		}
// 	}
// 	else if (arg == 5)
// 	{
// 		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z')))
// 			ft_print_result("NULL");
// 		else
// 		{
// 			while (tabstr[i] != NULL)
// 			{
// 				ft_print_result(tabstr[i]);
// 				write(1, "\n", 1);
// 				i++;
// 			}
// 		}
// 	}
// 	else if (arg == 6)
// 	{
// 		if (!(tabstr = ft_split("", 'z')))
// 			ft_print_result("NULL");
// 		else
// 			if (!tabstr[0])
// 				ft_print_result("ok\n");
// 	}
// 	return (0);
// }
