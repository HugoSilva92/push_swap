/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugo <hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:22:15 by huolivei          #+#    #+#             */
/*   Updated: 2023/01/04 00:54:45 by hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*initialize(long int nb)
{
	t_list	*stack;

	stack = malloc (sizeof (*stack));
	if (!stack)
		return (NULL);
	stack -> value = nb;
	stack -> index = 0;
	stack -> pos = 0;
	stack -> targ_pos = 0;
	stack -> cost_a = 0;
	stack -> cost_b = 0;
	stack -> next = NULL;
	return (stack);
}

t_list	*get_bottom_stack(t_list *stack)
{
	while (stack -> next)
		stack = stack -> next;
	return (stack);
}

void	add_bottom(t_list **stack, t_list *new)
{
	t_list	*bottom;

	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	bottom = get_bottom_stack(*stack);
	bottom -> next = new;
}

t_list	*get_values(int ac, char **av)
{
	t_list		*stack;
	long int	nb;
	int			i;

	nb = 0;
	i = 1;
	stack = NULL;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error(&stack, NULL);
		if (i == 1)
			stack = initialize((int)nb);
		else
			add_bottom(&stack, initialize((int)nb));
		i++;
	}
	return (stack);
}

int	get_size(t_list *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack -> next;
		i++;
	}
	return (i);
}
