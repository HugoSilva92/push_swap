/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <huolivei <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:37:38 by huolivei          #+#    #+#             */
/*   Updated: 2022/12/18 23:35:30 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	sent;
	int	i;

	size = get_size(*stack_a);
	sent = 0;
	i = 0;
	while (size > 6 && i < size && sent < (size / 2))
	{
		if ((*stack_a)->index <= (size / 2))
		{
			pb(stack_a, stack_b);
			sent++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (size - sent > 3)
	{
		pb(stack_a, stack_b);
		sent++;
	}
}

int	get_max_i(t_list *stack)
{
	int	i;

	i = stack->index;
	while (stack)
	{
		if (stack->index > i)
			i = stack->index;
		stack = stack->next;
	}
	return (i);
}

void	small_sort(t_list **stack)
{
	int	max_i;

	max_i = get_max_i(*stack);
	if (is_sorted(*stack))
		return ;
	if ((*stack)->index == max_i)
		ra(stack);
	else if ((*stack)->next->index == max_i)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	rotate_stack(t_list **stack_a)
{
	int	min_pos;
	int	size;

	min_pos = get_lowest_index(stack_a);
	size = get_size(*stack_a);
	if (min_pos > (size / 2))
	{
		while (min_pos < size)
		{
			rra(stack_a);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(stack_a);
			min_pos--;
		}
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	push_to_b(stack_a, stack_b);
	small_sort(stack_a);
	while (*stack_b)
	{
		get_tar_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_less_cost(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		rotate_stack(stack_a);
}
