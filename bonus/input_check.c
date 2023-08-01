/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:46:47 by huolivei          #+#    #+#             */
/*   Updated: 2022/12/16 14:45:51 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	amount_zeros(char *av)
{
	int	i;

	i = 0;
	if (sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	is_digit(char *av)
{
	int	i;

	i = 0;
	if (sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && is_nb(av[i]))
		i++;
	if (av[i] != '\0' && !is_nb(av[i]))
		return (0);
	return (1);
}

int	is_correct_input(char **av)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	while (av[i])
	{
		if (!is_digit(av[i]))
			return (0);
		flag += amount_zeros(av[i]);
		i++;
	}
	if (flag > 1)
		return (0);
	if (has_duplicates(av))
		return (0);
	return (1);
}
