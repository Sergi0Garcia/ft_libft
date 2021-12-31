/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:46:27 by segarcia          #+#    #+#             */
/*   Updated: 2021/11/29 20:37:36 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*substr;

	start = 0;
	i = 0;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	start = i;
	i = ft_strlen(s1);
	while (i > start && is_in_set(s1[i - 1], set))
		i--;
	end = i;
	substr = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s1 + start, end - start + 1);
	return (substr);
}
