/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo <hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:46:06 by huolivei          #+#    #+#             */
/*   Updated: 2023/01/04 00:57:34 by hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free (*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	error(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write (2, "Error\n", 6);
	exit (1);
}

void	get_index(t_list *stack, int size)
{
	t_list	*tmp;
	t_list	*highest;
	int		min;

	while (--size > 0)
	{
		tmp = stack;
		highest = NULL;
		min = INT_MIN;
		while (tmp)
		{
			if (tmp->value == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->value > min && tmp->index == 0)
			{
				min = tmp->value;
				highest = tmp;
				tmp = stack;
			}
			else
				tmp = tmp->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack -> value > stack->next->value)
			return (0);
		stack = stack -> next;
	}
	return (1);
}
