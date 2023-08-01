/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <huolivei <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:31:52 by huolivei          #+#    #+#             */
/*   Updated: 2022/12/18 23:36:44 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_pos(t_list **stack)
{
	t_list	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_best_targ_pos(t_list **stack, int b_index, int max_index, int tar_pos)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < max_index)
		{
			max_index = tmp->index;
			tar_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (max_index != INT_MAX)
		return (tar_pos);
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index < max_index)
		{
			max_index = tmp->index;
			tar_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (tar_pos);
}

void	get_tar_pos(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		tar_pos;

	tmp = *stack_b;
	get_pos(stack_a);
	get_pos(stack_b);
	tar_pos = 0;
	while (tmp)
	{
		tar_pos = get_best_targ_pos(stack_a, tmp->index, INT_MAX, tar_pos);
		tmp->targ_pos = tar_pos;
		tmp = tmp->next;
	}
}

int	get_lowest_index(t_list **stack)
{
	t_list	*tmp;
	int		min_i;
	int		min_p;

	tmp = *stack;
	min_i = INT_MAX;
	get_pos(stack);
	min_p = tmp->pos;
	while (tmp)
	{
		if (tmp->index < min_i)
		{
			min_i = tmp->index;
			min_p = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (min_p);
}
