/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:28:01 by segarcia          #+#    #+#             */
/*   Updated: 2021/12/08 23:19:11 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	is_separator(char const *s, char c, size_t i)
{
	return (i > 0 && s[i + 1] && s[i - 1] != c
		&& s[i] == c && s[i + 1] != c);
}

int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (is_separator(s, c, i))
			words++;
		i++;
	}
	if (words > 0)
		words++;
	return (words);
}

int	count_chars(char const *s, char c, size_t word_index)
{
	size_t	i;
	size_t	words;
	int		chars;

	i = 0;
	words = 0;
	chars = 0;
	while (s[i])
	{
		if (is_separator(s, c, i))
			words++;
		else
		{
			if (s[i] != c && words == word_index)
				chars++;
		}
		i++;
	}
	return (chars);
}

void	ft_strlcpy_sp(char *dst, const char *src, size_t size, int shift)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size > 0)
	{
		while (src[i])
		{
			while (i >= (size_t)shift - 1  && j < size)
			{
				dst[j] = src[i];
				j++;
			}
			i++;
		}
		dst[i] = '\0';
	}
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;
	int		chars;
	int		shift;

	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words));
	if (!res)
		return (NULL);                   
	i = 0;
	shift = 0;
	while (i < words)
	{
		chars = count_chars(s, c, i);
		shift += chars;
		printf("word[%i] - chars[%i]\n", i + 1, chars);
		printf("count: %i\n", shift);
		res[i] = (char *)malloc(sizeof(char) * (chars));
		ft_strlcpy_sp(res[i], s, chars, shift);
		i++;
	}
	res[i] = 0;
	return (res);
}
