/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:30:09 by segarcia          #+#    #+#             */
/*   Updated: 2022/05/10 12:23:25 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
}

static void	sign_validation(char num, size_t *i, int *sign)
{
	if (num == '-' || num == '+')
	{
		if (num == '-')
			*sign = -1;
		*i = *i + 1;
	}
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		res;
	size_t	i;
	size_t	counter;

	i = 0;
	res = 0;
	counter = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	sign_validation(str[i], &i, &sign);
	while (ft_isdigit(str[i]))
	{
		if (counter > 10)
			return (overflow(sign));
		res = (res * 10) + (str[i] - '0');
		i++;
		counter++;
	}
	return (res * sign);
}
