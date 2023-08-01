/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo <hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:22:12 by huolivei          #+#    #+#             */
/*   Updated: 2023/01/04 00:56:00 by hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_nb(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	nb_cmp(char *str, char *str1)
{
	int	i;
	int	i1;

	i = 0;
	i1 = 0;
	if (str[i] == '+')
	{
		if (str1[i1] != '+')
			i++;
	}
	else if (str1[i1] == '+')
		i1++;
	while (str[i] && str1[i1] && str[i] == str1[i1])
	{
		i++;
		i1++;
	}
	return ((unsigned char)str[i] - (unsigned char)str1[i1]);
}

int	has_duplicates(char **av)
{
	int	i;
	int	i1;

	i = 1;
	while (av[i])
	{
		i1 = 1;
		while (av[i1])
		{
			if (i != i1 && nb_cmp(av[i], av[i1]) == 0)
				return (1);
			i1++;
		}
		i++;
	}
	return (0);
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == 45)
	{
		sign = -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}
