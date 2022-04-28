/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:38:56 by segarcia          #+#    #+#             */
/*   Updated: 2022/04/20 11:38:58 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	handle_zero(size_t *i, char *str)
{
	*i = *i + 1;
	str[0] = '0';
}

static void	handle_negative(unsigned int *num, int *is_neg, char *str)
{
	str[0] = '-';
	*num = -(*num);
	*is_neg = 1;
}

char	*ft_itoa(int n)
{
	size_t			i;
	char			*str;
	int				len;
	int				is_neg;
	unsigned int	num;

	num = n;
	str = (char *)malloc(12);
	if (!str)
		return (NULL);
	i = 0;
	is_neg = 0;
	if (n == 0)
		handle_zero(&i, str);
	if (n < 0)
		handle_negative(&num, &is_neg, str);
	len = n_len(num);
	while (num != 0)
	{
		str[len - i -!is_neg] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	str[i + is_neg] = 0;
	return (str);
}
